package joueur;

import moulin.Moulin;
import partie.IJoueur;
import point.Point;

import static java.lang.System.out;
import java.util.Scanner;

public class Human implements IJoueur {
	private Moulin m;
	private Scanner s;
	private char pion;
	
	/**
	 * Constructeur du joueur Human
	 * @param s type humain choisis par l'utilisateur
	 */
	public Human(Scanner s){
		this.s = s;
	}
	
	/**
	 * Permet au joueur humain de faire une partie de Moulin
	 * @param m le jeu du Moulin
	 */
	public void jouer(Moulin m) {
		this.m = m; 
		if (m.getNBCoups() < Moulin.getNBJoueurs())
			this.pion = m.aQui();
		if (m.getNBCoups() < Moulin.getMaxPions())
			ajouterPion();
		else 
			bougerPion();
	}
	
	/**
	 * Permet au joueur humain de déplacer son pion lorsque les 6 pions 
	 * initiaux ont été placés sur la grille du Moulin
	 */
	private void bougerPion() {
		Point départ, arrivée;
		do {
			out.println(m.aQui() + " : Choisissez la case de départ.");
			départ = saisirCase();
			out.println(m.aQui() + " : Choisissez la case d'arrivée.");
			arrivée = saisirCase();
			if (!m.peutDéplacerEn(départ.x, départ.y, arrivée.x, arrivée.y))
				out.println("Ce dépladement n'est pas valide");
		} while (!m.peutDéplacerEn(départ.x, départ.y, arrivée.x, arrivée.y));
		m.déplacerEn(départ.x, départ.y, arrivée.x, arrivée.y);
	}
	
	/**
	 * permet au joueur humain de désigner une case à partir de ses coordonnées
	 * @return une case de la grille du Moulin
	 */
	public Point saisirCase() {
		int x = saisirCoordonnée();
		int y = saisirCoordonnée();
		return new Point(x,y);
	}
	
	/**
	 * permet au joueur humain de placer ses pions sur la grille du Moulin
	 */
	private void ajouterPion() {
		int x,y;
		do {
			out.println(m.aQui() + " : Choisissez la case où ajouter votre pion.");
			x = saisirCoordonnée();
			y = saisirCoordonnée();
			if (! m.peutPoserEn(x, y))
				out.println("Cette case n'est pas valide");
		} while (! m.peutPoserEn(x, y));
		m.placer(x, y);
	}
	
	/**
	 * permet au joueur humain d'entrer un coordonné, servant à désigner une case de la
	 * grille Moulin
	 * @return le nombre correspondant au coordonnée entré par le joueur,
	 * dans une grille où les indices commencent à 1
	 */
	public int saisirCoordonnée() {
		out.println("entrez la coordoonnée : ");
		while (!s.hasNextInt()) {
			out.println("saisissez un entier");
			s.next();
		}
		return s.nextInt();
	}
	
	/**
	 * permet de savoir quel est le pion utilisé par le joueur (X ou O)
	 * @return le pion utilisé par le joueur
	 */
	public char getPion() { return this.pion; }
}

