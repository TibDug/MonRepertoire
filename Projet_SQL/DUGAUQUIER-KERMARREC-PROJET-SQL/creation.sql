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
   plaque VARCHAR REFERENCES voiture(plaque) ON DELETE CASCADE,
   dureeUtilisation INTEGER,
   prixLocation FLOAT
)c

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