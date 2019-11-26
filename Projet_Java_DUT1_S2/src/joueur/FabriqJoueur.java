package joueur;

import java.util.Scanner;

import partie.IFabriqJoueur;
import partie.IJoueur;

public class FabriqJoueur implements IFabriqJoueur {
    private Scanner s;
	
    /**
     * Constructeur de la fabriqJoueur
     * @param s type de joueur choisis par l'utilisateur
     */
	public FabriqJoueur(Scanner s) {
		this.s = s;
	}
	
	/**
	 * détermine le type de joueur choisis par l'utilisateur
	 */
    @Override
	public IJoueur choisirJoueur() {
        System.out.println("Veuillez choisir un type de joueur :");
        System.out.println("1/ Joueur Humain");
        System.out.println("2/ Intelligence MinMax");
        System.out.println("3/ Ordinateur Aléatoire");
        int choix = s.nextInt();
        while ( choix < 1 || choix > 3 ) {
            choix = s.nextInt();
        }
        if (choix == 1) {
            return new Human(s);
        } 
        else if (choix == 2) {
            return new IAminmax();
        }
        else {
            return new IArandom();
        }
    }
}