package partie;

import moulin.Moulin;

class Resultat {
    public String resMoulin;
    public char perdant;
    
    /**
     * Constructeur de résultat
     * @param toStringMoulin grille résultant de la fin de la partie
     * @param perdant symbole du joueur ayant perdu la partie de Moulin
     */
    public Resultat(String toStringMoulin, char perdant) {
        this.resMoulin = toStringMoulin;
        this.perdant = perdant;
    }
}


public class Partie {
    private IJoueur j1;
    private IJoueur j2;
    private Moulin m;
    private boolean affichage = true;
    
    /**
     * Constructeur d'une partie, avec 2 joueurs et un nombre de tours définis
     * @param joueur1 le premier joueur
     * @param joueur2 le second joueur
     * @param nbTours le nombre de tours choisis pour effectuer la partie de Moulin
     */
    public Partie(IJoueur joueur1, IJoueur joueur2, int nbTours) {
        this.m = new Moulin(nbTours);
        this.j1 = joueur1;
        this.j2 = joueur2;
    }
    
    /**
     * Constructeur d'une partie, avec 2 joueurs et un nombre de tours par defaut
     * @param joueur1 le premier joueur
     * @param joueur2 le second joueur
     */
    public Partie(IJoueur joueur1, IJoueur joueur2) {
        this.m = new Moulin();
        this.j1 = joueur1;
        this.j2 = joueur2;
    }
    
    /**
     * Constructeur d'une partie, créant des joueurs d'un certain type et ayant un
     * nombre de tours défini 
     * @param fabJ la fabrique de joueurs, qui permet de choisir le type des joueurs
     * @param nbTours le nombre de tours choisis pour effectuer la partie de Moulin
     */
    public Partie(IFabriqJoueur fabJ, int nbTours) {
        this.m = new Moulin(nbTours);
        this.j1 = fabJ.choisirJoueur();
        this.j2 = fabJ.choisirJoueur();
    }
    
    /**
     * Constructeur d'une partie, créant des joueurs d'un certain type et ayant un
     * nombre de tours par defaut 
     * @param fabJ la fabrique de joueurs, qui permet de choisir le type des joueurs
     */
    public Partie(IFabriqJoueur fabJ) {
        this.m = new Moulin();
        this.j1 = fabJ.choisirJoueur();
        this.j2 = fabJ.choisirJoueur();
    }
    
    /**
     * Permet de définir que le déroulement de la partie de Moulin ne doit pas être
     * affiché à l'écran
     */
    public void jeuSansAffichage() { affichage = false; this.game(); }
    
    /**
     * Permet de définir que le déroulement de la partie de Moulin doit être affiché 
     * à l'écran
     */
    public void jeu() { affichage = true; this.game(); }
    
    /**
     * Permet d'afficher le déroulement d'une partie de Moulin à l'écran
     */
    private void game() {
    	IJoueur joueurs[] = {j1, j2};
    	int i = 0;
   	 	while( !m.estFinie()) {
            afficher();
            joueurs[i++ % Moulin.getNBJoueurs()].jouer(m);
        }
        afficher();
	}

    /**
     * Permet d'afficher la partie à l'écran si l'affichage est activé, et sinon de
     * ne rien afficher
     */
    private void afficher() {
        if (affichage)
            System.out.println(m);
    }
    
    /**
     * Permet d'obtenir le résultat d'une partie de Moulin (grille finale et perdant)
     * @return le résultat de la partie de Moulin
     */
    public Resultat getResultat() {
        assert (m.estFinie());
        if (m.alignement()) 
            return new Resultat( m.toString(), m.aQui() );
        else
            return new Resultat( m.toString(), Moulin.getVIDE() );
    }
}
