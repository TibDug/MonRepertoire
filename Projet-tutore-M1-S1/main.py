#! pymol -cq main.py -- 4

from pymol import cmd
import os, os.path
import time
DIR = "PDB_files/"
nbFic = len(os.listdir(DIR))

one_letter = {'VAL':'V', 'ILE':'I', 'LEU':'L', 'GLU':'E', 'GLN':'Q', \
'ASP':'D', 'ASN':'N', 'HIS':'H', 'TRP':'W', 'PHE':'F', 'TYR':'Y',    \
'ARG':'R', 'LYS':'K', 'SER':'S', 'THR':'T', 'MET':'M', 'ALA':'A',    \
'GLY':'G', 'PRO':'P', 'CYS':'C'}


def chargerFichier(nomRepertoire, nomFichier):
    try:        
        cmd.reinitialize()
        cmd.load(nomRepertoire + nomFichier + ".pdb")
        print("Chargement du ficher " +  nomFichier + " effectue")
    except:
        print("Erreur de chargement du ficher " +  nomFichier)

def selectionADN(dist):
    cmd.select("DNA", "resn DA+DC+DG+DT")
#        ADN = []
#        try :
#            atoms = cmd.get_model("DNA")
#            for at in atoms.atom:
#                ADN.append(at.resi)
#   cmd.select("resInte", "byres DNA expand " + dist + " and not inorganic and not solvent")
    cmd.select("resInte", "byres DNA around " + dist)
    print("Selection effectuee")

def ecritureResidusInteractions():
    cmd.iterate("resInte", "print('{}'.format(one_letter[resn]))")
    with open ("Selection_Interactions/fichierInteraction", "a") as f:
        cmd.iterate("resInte", "f.write('{}'.format(one_letter[resn]))")
        f.write("\n")

def genererPDB(nomRepertoire, nomFichier):
    cmd.save(nomRepertoire + "interactions_" + nomFichier + ".pdb", "resInte")
    print("Creation du fichier reussie")

def comptageAtomes():
    cmd.select("atoms", "all")
    print("On a " + str(cmd.count_atoms("atoms")) + " atomes en contact avec l'ADN")

def comptageResidus():
    cmd.select("residues", "name ca")
    print("On a " + str(cmd.count_atoms("residues")) + " residus en contact avec l'ADN")
    
def genererAtomesLourds(nomFichier):
    cmd.select("heavyAtoms", "name N+O+F+NA+MG+AL+P+S+CI+K+ZN")
    cmd.iterate("heavyAtoms", "f.write('{} : {}({})\\n'.format(name,resn,resi))")
    f.write("\n")

for i in range(nbFic):
    nomFic = os.listdir(DIR)[i].split(".")[0]
    with open ("Atomes_Lourds/atomes_lourds_" + nomFic + ".txt", "w") as f:
        chargerFichier(DIR, nomFic)
        selectionADN(sys.argv[1])
        genererPDB("PDB_interactions/", nomFic)
        chargerFichier("PDB_interactions/", "interactions_" + nomFic)          
        comptageAtomes()
        comptageResidus()
        genererAtomesLourds(f)
        print("\n")       
        pass
    
    
