DROP TABLE IF EXISTS abonnement;
DROP TABLE IF EXISTS typeAbonnement;
DROP TABLE IF EXISTS entretien;
DROP TABLE IF EXISTS location;
DROP TABLE IF EXISTS voiture;
DROP TABLE IF EXISTS station;
DROP TABLE IF EXISTS utilisateur;
DROP TABLE IF EXISTS localisation;

CREATE TABLE localisation (
   idLocalisation INTEGER PRIMARY KEY,
   latitude FLOAT,
   longitude FLOAT,
   pays VARCHAR,
   ville VARCHAR
);

CREATE TABLE station (
   idStation INTEGER PRIMARY KEY,
   capacite INTEGER,
   idLocalisation INTEGER REFERENCES localisation(idLocalisation) ON DELETE CASCADE,
   dateLocalisation DATE
);

CREATE TABLE voiture (
   plaque VARCHAR PRIMARY KEY,
   niveauBatterie INTEGER,
   idLocalisation INTEGER REFERENCES localisation(idLocalisation) ON DELETE CASCADE,
   dateLocalisation DATE,
   idStation INTEGER REFERENCES station(idStation) ON DELETE CASCADE
);

CREATE TABLE entretien (
   idEntretien INTEGER PRIMARY KEY,
   description VARCHAR,
   plaque VARCHAR REFERENCES voiture(plaque) ON DELETE CASCADE,
   dateEntretien DATE
);

CREATE TABLE utilisateur (
   idUtilisateur INTEGER PRIMARY KEY,
   nom VARCHAR,
   prenom VARCHAR,
   age INTEGER,
   adresse VARCHAR,
   telephone VARCHAR,
   idLocalisation INTEGER REFERENCES localisation(idLocalisation) ON DELETE CASCADE,
   dateLocalisation DATE
);

CREATE TABLE location (
   idLocation INTEGER PRIMARY KEY,
   dateLocation DATE,
   idUtilisateur INTEGER REFERENCES utilisateur(idUtilisateur) ON DELETE CASCADE,
   plaque VARCHAR REFERENCES voiture(plaque),
   dureeUtilisation INTEGER,
   prixLocation FLOAT
);

CREATE TABLE typeAbonnement (
   idTypeAbonnement INTEGER PRIMARY KEY,
   intitulé VARCHAR,
   prixTypeAbonnement FLOAT,
   indiceRemise INTEGER
);

CREATE TABLE abonnement (
   idAbonnement INTEGER PRIMARY KEY,
   dateDebutAbonnement DATE,
   dateFinAbonnement DATE,
   idUtilisateur INTEGER REFERENCES utilisateur(idUtilisateur) ON DELETE CASCADE,
   idTypeAbonnement INTEGER REFERENCES typeAbonnement(idTypeAbonnement) ON DELETE CASCADE
);



/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */


INSERT INTO localisation (idLocalisation,latitude,longitude,pays,ville) VALUES
(1,49,89,'France','Paris'),
(2,78,56,'France','Paris'),
(3,12,75,'France','Paris'),
(6,60,50,'France','Paris'),
(7,56,90,'France','Paris'),
(8,60,34,'France','Paris'),
(9,34,34,'France','Paris'),
(10,49,89,'France','Paris'),
(11,49,89,'France','Paris'),
(12,49,89,'France','Paris'),
(13,49,89,'France','Paris'),
(14,78,56,'France','Paris'),
(15,78,56,'France','Paris'),
(16,12,75,'France','Paris'),
(17,12,75,'France','Paris'),
(18,12,75,'France','Paris'),
(19,12,75,'France','Paris'),
(20,14,76,'France','Paris'),
(21,60,50,'France','Paris'),
(22,56,90,'France','Paris'),
(23,60,34,'France','Paris'),
(24,34,34,'France','Paris'),
(25,31,48,'France','Paris'),
(26,64,54,'France','Paris'),
(27,18,75,'France','Paris')
;

INSERT INTO station (idStation,capacite,idLocalisation,dateLocalisation) VALUES
(1,10,1,'2019-01-02'),
(2,5,2,'2019-01-02'),
(3,10,3,'2019-01-02');

INSERT INTO voiture (plaque,niveauBatterie,idLocalisation,dateLocalisation,idStation) VALUES
('TL845KD', 15, 6, '2019-01-02', NULL),
('IO855PZ', 42, 7, '2019-01-02', NULL),
('HO154SF', 59, 8, '2019-01-02', NULL),
('PZ532OJ', 36, 9, '2019-01-02', NULL),
('OA734PS', 84, 10, '2019-01-02',1),
('ZL578ZD', 84, 11, '2019-01-02',1),
('AP545OA', 95, 12, '2019-01-01',1),
('KD564JE', 75, 13, '2019-01-02',1),
('LA454JD', 95, 14, '2019-01-02',2),
('LK541JZ', 81, 15, '2019-01-01',2),
('KA743OD', 62, 16, '2019-01-02',3),
('AK542OA', 74, 17, '2019-01-02',3),
('AE756DO', 95, 18, '2019-01-02',3),
('AO782OD', 67, 19, '2019-01-02',3),
('GE524ZP', 76, 20, '2019-01-02',3);

INSERT INTO entretien (idEntretien,description,plaque,dateEntretien) VALUES

/* CHANGER DATE */
(1,'Changement des roues','TL845KD','2018-01-16'),
(2,'Liquide de frein','IO855PZ','2018-07-29'),
(3,'Plaquette de frein','HO154SF','2018-10-16'),
(4,'Revision des 80000 KM','PZ532OJ','2018-12-07'),
(5,'Remplacement des feux de routes','OA734PS','2018-12-14'),
(6,'Changement de la carroserie','ZL578ZD','2017-12-03'),
(7,'Remplacement du pare-brise','AP545OA','2019-01-01'),
(8,'Remplacement des feux de signalisaation','KD564JE','2017-07-02'),
(9,'Remplacement du pare-brise','LA454JD','2018-11-02'),
(10,'Changement du moteur','LK541JZ','2018-12-07'),
(11,'Revision des 80000 KM','KA743OD','2018-09-14'),
(12,'Reparation de la courroi de distributuion','AK542OA','2018-10-02'),
(13,'Nettoyage des sols','AE756DO','2019-01-03'),
(14,'Reparation de la courroi de distributuion','AO782OD','2019-01-02'),
(15,'Revision des 80000 KM','GE524ZP','2018-01-02')
;

INSERT INTO utilisateur (idUtilisateur,nom,prenom,age,adresse,telephone,idLocalisation,dateLocalisation) VALUES
(1,'Claude', 'Jean', 46, '5 rue du Boulier, Paris', '0156543546', 21, '2019-01-02'),
(2,'Schwarzenegger', 'Arnold', 28, '45 rue de la Paix, Paris', '0112654656', 22, '2019-01-01'),
(3, 'Paul', 'Jacques', 23, '205 avenue des Champs-Elysées, Paris', '0265413248', 23, '2018-12-30'),
(4,'McClane', 'John', 77, '404 impasse des Aubergines, Paris', '0154135452', 24, '2019-01-01'),
(5,'Viande', 'Boris',38, '25 rue Albert Einstein, Paris', '0131265255', 25, '2018-12-29')
; 

INSERT INTO location (idLocation,dateLocation,idUtilisateur,plaque, dureeUtilisation, prixLocation) VALUES

(1,'2019-01-07',1,'TL845KD',2040,6.8),
(2,'2019-01-07',2,'IO855PZ',9360,46.8),
(3,'2019-01-07',3,'HO154SF',4020,40.2),
(4,'2019-01-07',4,'PZ532OJ',240,2.4),
(5,'2019-01-07',5,'OA734PS',5400,27),
(6,'2019-01-06',1,'ZL578ZD',1380,4.6),
(7,'2019-01-06',2,'AP545OA',5220,26.1),
(8,'2018-11-05',3,'KD564JE',8940,89.4),
(9,'2019-01-04',4,'LA454JD',10020,100.2),
(10,'2019-01-02',5,'LK541JZ',2700,13.5),
(11,'2019-01-02',1,'KA743OD',6000,20),
(12,'2018-12-27',2,'AK542OA',4680,23.4),
(13,'2019-01-02',3,'AE756DO',7260,72.6),
(14,'2019-01-02',4,'AO782OD',4020,40.2),
(15,'2019-01-02',5,'GE524ZP',5340,26.7)
;

INSERT INTO typeAbonnement (idTypeAbonnement,intitulé,prixTypeAbonnement,indiceRemise) VALUES
(1,'Gratuit', 0.00, 1),
(2,'Premium', 9.99, 2),
(3,'Business', 19.99,3)
;

INSERT INTO abonnement (idAbonnement,dateDebutAbonnement,dateFinAbonnement,idUtilisateur,idTypeAbonnement) VALUES

(1,'2019-01-01','2019-02-01',1,3),
(2,'2018-12-09','2019-01-09',2,2),
(3,'2018-12-27','2019-01-27',3,1),
(4,'2018-12-14','2019-01-14',4,1),
(5,'2019-01-02','2019-02-02',5,2),
(6,'2018-11-08','2018-12-08',1,2),
(7,'2018-11-26','2018-12-26',3,1)
;



/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
DEALLOCATE PREPARE nouvel_utilisateur;
DEALLOCATE PREPARE changement_adresse;
DEALLOCATE PREPARE changement_telephone;
DEALLOCATE PREPARE changement_abonnement;
DEALLOCATE PREPARE suppression_utilisateur;
DEALLOCATE PREPARE nouvelle_voiture;
DEALLOCATE PREPARE mise_a_jour_batterie;
DEALLOCATE PREPARE nouvel_entretien_voiture;
DEALLOCATE PREPARE changement_station;
DEALLOCATE PREPARE suppression_voiture;


PREPARE nouvel_utilisateur(INTEGER,VARCHAR,VARCHAR,INTEGER,VARCHAR,VARCHAR,INTEGER,DATE) AS
INSERT INTO utilisateur VALUES ($1,$2,$3,$4,$5,$6,$7,$8);

EXECUTE nouvel_utilisateur(16, 'Clooney', 'Georges', 57, 'Los Angeles', '0135516652', 26, '2016-09-21');





PREPARE changement_adresse(INTEGER,VARCHAR) AS
UPDATE utilisateur 
SET adresse = $2
WHERE idUtilisateur = $1;

EXECUTE changement_adresse(16, 'New York');




PREPARE changement_telephone(INTEGER,VARCHAR) AS
UPDATE utilisateur 
SET telephone = $2
WHERE idUtilisateur = $1;

EXECUTE changement_telephone(16, '555012834');


PREPARE suppression_utilisateur(INTEGER) AS
DELETE FROM utilisateur WHERE idUtilisateur = $1;

EXECUTE suppression_voiture(16);




PREPARE changement_abonnement(INTEGER,INTEGER) AS
UPDATE abonnement
SET idTypeAbonnement = $2
WHERE idUtilisateur = $1;

EXECUTE changement_abonnement(16,3);




PREPARE nouvelle_voiture(VARCHAR,INTEGER,INTEGER,DATE,INTEGER) AS
INSERT INTO voiture VALUES ($1,$2,$3,$4,$5);

EXECUTE nouvelle_voiture('BR766ET',100,27,'2019-01-04',NULL);




PREPARE mise_a_jour_batterie(VARCHAR, INTEGER) AS
UPDATE voiture
SET niveauBatterie = $2
WHERE plaque = $1;

EXECUTE mise_a_jour_batterie('BR766ET', 75);




PREPARE nouvel_entretien_voiture(INTEGER,VARCHAR,VARCHAR,DATE) AS
INSERT INTO entretien VALUES ($1,$2,$3,$4);

EXECUTE nouvel_entretien_voiture(19,'Remplacement plaquettes de frein','BR766ET','2019-01-29');




PREPARE changement_station(VARCHAR, INTEGER) AS
UPDATE voiture
SET idStation = $2
WHERE plaque = $1;

EXECUTE changement_station('BR766ET',2);




PREPARE suppression_voiture(VARCHAR) AS
DELETE FROM voiture WHERE plaque = $1;

EXECUTE suppression_voiture('BR766ET');



/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

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

-- Véhicules n’ayant pas eu d_entretien depuis un an.

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
/* Nous partons du principe que tous nos abonnements sont mensuel ou annuel. */

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




