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