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
	 * Permet au joueur humain de d�placer son pion lorsque les 6 pions 
	 * initiaux ont �t� plac�s sur la grille du Moulin
	 */
	private void bougerPion() {
		Point d�part, arriv�e;
		do {
			out.println(m.aQui() + " : Choisissez la case de d�part.");
			d�part = saisirCase();
			out.println(m.aQui() + " : Choisissez la case d'arriv�e.");
			arriv�e = saisirCase();
			if (!m.peutD�placerEn(d�part.x, d�part.y, arriv�e.x, arriv�e.y))
				out.println("Ce d�pladement n'est pas valide");
		} while (!m.peutD�placerEn(d�part.x, d�part.y, arriv�e.x, arriv�e.y));
		m.d�placerEn(d�part.x, d�part.y, arriv�e.x, arriv�e.y);
	}
	
	/**
	 * permet au joueur humain de d�signer une case � partir de ses coordonn�es
	 * @return une case de la grille du Moulin
	 */
	public Point saisirCase() {
		int x = saisirCoordonn�e();
		int y = saisirCoordonn�e();
		return new Point(x,y);
	}
	
	/**
	 * permet au joueur humain de placer ses pions sur la grille du Moulin
	 */
	private void ajouterPion() {
		int x,y;
		do {
			out.println(m.aQui() + " : Choisissez la case o� ajouter votre pion.");
			x = saisirCoordonn�e();
			y = saisirCoordonn�e();
			if (! m.peutPoserEn(x, y))
				out.println("Cette case n'est pas valide");
		} while (! m.peutPoserEn(x, y));
		m.placer(x, y);
	}
	
	/**
	 * permet au joueur humain d'entrer un coordonn�, servant � d�signer une case de la
	 * grille Moulin
	 * @return le nombre correspondant au coordonn�e entr� par le joueur,
	 * dans une grille o� les indices commencent � 1
	 */
	public int saisirCoordonn�e() {
		out.println("entrez la coordoonn�e : ");
		while (!s.hasNextInt()) {
			out.println("saisissez un entier");
			s.next();
		}
		return s.nextInt();
	}
	
	/**
	 * permet de savoir quel est le pion utilis� par le joueur (X ou O)
	 * @return le pion utilis� par le joueur
	 */
	public char getPion() { return this.pion; }
}

