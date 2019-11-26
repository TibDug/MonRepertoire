DEALLOCATE PREPARE voitures_proches;
DEALLOCATE PREPARE calcul_prix_location;
DEALLOCATE PREPARE calcul_prix_total;
DEALLOCATE PREPARE nombre_places;
DEALLOCATE PREPARE alerte_abonnement;


/* 1) Liste des 10 objets disponibles les plus proches d_un utilisateur. */

PREPARE voitures_proches(INTEGER) AS
SELECT v.plaque, v.niveauBatterie,SQRT(POW((
	SELECT lu.latitude
	FROM utilisateur AS u JOIN localisation AS lu ON u.idLocalisation = lu.idLocalisation
	WHERE u.idUtilisateur = $1)
- lv.latitude, 2) + POW((
	SELECT lu.longitude
	FROM utilisateur AS u JOIN localisation AS lu ON u.idLocalisation = lu.idLocalisation
	WHERE u.idUtilisateur = $1)
-lv.longitude, 2)) AS distance
FROM voiture AS v JOIN localisation AS lv ON v.idLocalisation = lv.idLocalisation
WHERE v.idStation IS NOT NULL
ORDER BY distance
LIMIT 10;

EXECUTE voitures_proches(5);


/* 2) Objets nécessitant une intervention. */

-- Véhicules n’ayant pas eu d'entretien depuis un an.

SELECT v.plaque
FROM voiture AS v NATURAL JOIN entretien AS e
WHERE e.dateEntretien < (CAST(NOW() AS DATE) - 365);


/* 3) Calcul du prix d’une location selon l’abonnement. */

PREPARE calcul_prix_location(INTEGER) AS
SELECT ((l.dureeUtilisation * 0.01) / t.indiceRemise) AS prix_location
FROM location AS l NATURAL JOIN utilisateur AS u NATURAL JOIN abonnement AS a NATURAL JOIN typeAbonnement AS t
WHERE l.idLocation = $1 
AND (l.dateLocation BETWEEN a.dateDebutAbonnement AND a.dateFinAbonnement);

EXECUTE calcul_prix_location(3);


/* 4) Calcul du prix total des locations d’un client au cours du mois dernier. */

PREPARE calcul_prix_total(INTEGER) AS
SELECT u.idUtilisateur, SUM(l.prixLocation)
FROM location as l NATURAL JOIN utilisateur as u NATURAL JOIN abonnement as a NATURAL JOIN typeAbonnement as t
WHERE u.idUtilisateur = $1 
AND EXTRACT(MONTH FROM l.dateLocation) = EXTRACT(MONTH FROM NOW())
AND (l.dateLocation BETWEEN a.dateDebutAbonnement AND a.dateFinAbonnement)
GROUP BY u.idUtilisateur;

EXECUTE calcul_prix_total(1);


/* 5) Durée moyenne d’une location par utilisateur, puis au total. */

SELECT u.idUtilisateur, u.nom, AVG(l.dureeUtilisation),SUM(l.dureeUtilisation)
FROM location AS l NATURAL JOIN utilisateur AS u
GROUP BY u.idUtilisateur
ORDER BY u.idUtilisateur;


/* 6) Chiffre d’affaire généré au cours du mois dernier. */

DROP FUNCTION chiffreAffaireLocation();
DROP FUNCTION chiffreAffaireAbonnement();

CREATE OR REPLACE FUNCTION chiffreAffaireLocation()
returns float as
$BODY$
DECLARE
CAL float;
BEGIN
SELECT SUM(l.prixLocation) into CAL
FROM location AS l
WHERE EXTRACT(MONTH FROM l.dateLocation) = EXTRACT(MONTH FROM NOW());
IF CAL IS NULL
THEN
RETURN 0;
END IF;
RETURN CAL;
END;
$BODY$
LANGUAGE PLPGSQL;

CREATE OR REPLACE FUNCTION chiffreAffaireAbonnement()
returns float as
$BODY$
DECLARE
CAA float;
BEGIN
SELECT SUM(t.prixTypeAbonnement) INTO CAA
FROM typeAbonnement AS t NATURAL JOIN abonnement AS a
WHERE EXTRACT(MONTH FROM a.dateDebutAbonnement) = EXTRACT(MONTH FROM NOW());
IF CAA IS NULL
THEN
RETURN 0;
END IF;
RETURN CAA;
END;
$BODY$
LANGUAGE PLPGSQL;

SELECT (chiffreAffaireLocation() + chiffreAffaireAbonnement()) AS chiffreAffaireTotal;


/* 7) Calcul des places disponibles pour une station */

PREPARE nombre_places(INTEGER) AS
SELECT s.idStation, s.capacite - COUNT(v.plaque) AS placesDispo
FROM voiture AS v JOIN station AS s ON v.idStation = s.idStation
WHERE s.idStation = $1
group by s.idStation;

EXECUTE nombre_places(1);


/* 8) Tous les utilisateurs dont l’abonnement se termine au maximum dans $1 jours */
/* Nous partons du principe que tous nos abonnements sont mensuels */

PREPARE alerte_abonnement(INTEGER) AS 
SELECT u.idUtilisateur, u.nom
FROM utilisateur AS u NATURAL JOIN abonnement AS a 
WHERE (dateFinAbonnement - CAST(NOW() AS DATE)) < $1
ORDER BY u.idUtilisateur;

EXECUTE alerte_abonnement(10);


/* 9) Voiture étant apparié à une station mais n’étant pas garé sur cette station (c'est une erreur, ce cas de figure ne devrait pas arriver) */

SELECT v.plaque, s.idStation
FROM voiture AS v JOIN station AS s ON v.idStation = s.idStation
WHERE v.idStation IS NOT NULL
AND v.idStation = s.idStation
AND ((SELECT l1.longitude FROM localisation AS l1 WHERE s.idLocalisation = l1.idLocalisation) != (SELECT l2.longitude FROM localisation AS l2 WHERE v.idLocalisation = l2.idLocalisation)
OR (SELECT l3.latitude FROM localisation AS l3 WHERE s.idLocalisation = l3.idLocalisation) != (SELECT l4.latitude FROM localisation AS l4 WHERE v.idLocalisation = l4.idLocalisation));


/* 10) Renvoie les utilisateurs ayant dépensés plus de 100 € de location */

SELECT u.idUtilisateur, u.nom, SUM(prixLocation)
FROM utilisateur AS u NATURAL JOIN abonnement AS a NATURAL JOIN location AS l
GROUP BY u.idUtilisateur
HAVING SUM(prixLocation) >= 100
ORDER BY u.idUtilisateur;

