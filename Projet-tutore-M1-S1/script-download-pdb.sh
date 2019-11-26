#!/bin/sh

x=1

# Récupérer nb ligne fichier
y=$(cat fichiersATelecharger | wc -l)

for line in $(cat fichiersATelecharger);
do
    echo " ####################"
    echo $x sur $y
    echo " ####################"
    wget -P ./PDB_files $line

    x=$((x + 1))
done
