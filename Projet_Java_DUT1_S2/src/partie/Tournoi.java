// imp:ements une interface
package partie;

import java.util.ArrayList;

import moulin.Moulin;

public class Tournoi {
    private ArrayList<Partie> parties;
    
    /**
     * Constructeur d'un tournoi, avec un nombre de tours et un nombre de parties choisis
     * @param fabJ la fabrique de joueurs, qui permet de choisir le type des joueurs
     * @param nbTours le nombre de tours choisis pour effectuer le jeu du Moulin
     * @param nbParties le nombre de parties que comporte un tournoi
     */
    public Tournoi(IFabriqJoueur fabJ, int nbTours, int nbParties) {
    	IJoueur joueur1 = fabJ.choisirJoueur();
    	IJoueur joueur2 = fabJ.choisirJoueur();
    	parties = new ArrayList<Partie>();
    	for (int i = 0; i < nbParties; ++i)
            parties.add(new Partie(joueur1, joueur2, nbTours));
    }
    
    /**
     * Constructeur d'un tournoi, avec un nombre de tours par defaut et un 
     * nombre de parties choisis
     * @param fabJ la fabrique de joueurs, qui permet de choisir le type des joueurs
     * @param nbParties le nombre de parties que comporte un tournoi
     */
    public Tournoi(IFabriqJoueur fabJ, int nbParties) {
    	IJoueur joueur1 = fabJ.choisirJoueur();
    	IJoueur joueur2 = fabJ.choisirJoueur();
    	parties = new ArrayList<Partie>();
    	for (int i = 0; i < nbParties; ++i)
            parties.add(new Partie(joueur1, joueur2));
    }
    
    /**
     * Constructeur d'un tournoi, avec un nombre de tours et un nombre de parties par defaut
     * @param fabJ la fabrique de joueurs, qui permet de choisir le type des joueurs
     */
    public Tournoi(IFabriqJoueur fabJ) {
        this(fabJ, 100);
    }
    
    /**
     * Permet au programme d'enchaîner les parties
     */
    public void deroulerParties() {
        for (Partie part : parties) {
			part.jeuSansAffichage();
		}
    }
    
    /**
     * Détermine qui est le gagnant d'un tournoi, c'est à dire qui a remporter le plus de parties
     * @return le symbole du gagnant du tournoi
     */
    public char gagnantTournoi() {
    	int comptJoueur = 0;
    	final char j1 = Moulin.getSymbols()[comptJoueur];
    	++comptJoueur;
    	final char j2 = Moulin.getSymbols()[comptJoueur];
    	int compteurj1 = 0;
    	int compteurj2 = 0;
    	for (Partie part : parties) {
    		if (part.getResultat().perdant == j1)
    			++compteurj2;
    		else if (part.getResultat().perdant == j2)
    			++compteurj1;
		}
    	if (compteurj1 > compteurj2)
    		return j1;
    	else if (compteurj1 < compteurj2)
    	 	return j2;
    	else
    		return Moulin.getVIDE();
    }
    
    /**
     * Détermine le nombre de parties qu'à remporté le gagnant du tournoi
     * @return le nombre de parties qu'à remporté le gagnant du tournoi
     */
    public int gagnantTournoiScore() {
    	int comptJoueur = 0;
    	final char j1 = Moulin.getSymbols()[comptJoueur];
    	++comptJoueur;
    	final char j2 = Moulin.getSymbols()[comptJoueur];
    	int compteurj1 = 0;
    	int compteurj2 = 0;
    	for (Partie part : parties) {
    		if (part.getResultat().perdant == j1)
    			++compteurj2;
    		else if (part.getResultat().perdant == j2)
    			++compteurj1;
		}
    	if (compteurj1 > compteurj2)
    		return compteurj1;
    	else if (compteurj1 < compteurj2)
    	 	return compteurj2;
    	else
    		return -1; 
    }
    
    /**
     * Permet d'afficher les grilles finales des parties
     * @return la grille finale de toutes les parties du tournoi
     */
    public String[] getTablResultats() { 
    	String[] resultat = new String[this.parties.size()];
    	int i = 0;
    	for (Partie part : parties) {
			resultat[i++] = part.getResultat().resMoulin;
		}
    	return resultat;
    }
}
