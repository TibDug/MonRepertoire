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
