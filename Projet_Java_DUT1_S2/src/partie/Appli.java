package partie;

import static java.lang.System.out;


import java.util.Scanner;

import joueur.FabriqJoueur;
import moulin.Moulin;

public class Appli {
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String choix;
		int choixInt;
		Partie p = null;
		Tournoi t = null;
		out.println("|---Bienvenue dans le jeu du Moulin---|");
		out.println("  1 2 3\r\n3 . . .\r\n2 . . .\r\n1 . . .\r\n\r\n"
				+ "X.Y\r\n1.3 2.3 3.3\r\n1.2 2.2 3.2\r\n1.1 2.1 3.1\r\n");
		out.println("Voulez-vous organiser une (p)artie ou un (t)ournoi ?");
		choix = s.nextLine();
		while (!choix.equals("p") && !choix.equals("t"))
			choix = s.nextLine();
		if ( choix.equals("p") ) {
			out.println("Voulez vous selectionner le nombre de tours ? (10 par défaut) o/n");
			choix = s.nextLine();
			while (!choix.equals("o") && !choix.equals("n"))
				choix = s.nextLine();
			if (choix.equals("o")) {
				out.print("Entrez le nombre de tours (entre 10 et 99) : ");
				choixInt = s.nextInt();
				while (choixInt < 10 || choixInt > 99)
					choixInt = s.nextInt();
				p = new Partie(new FabriqJoueur(s), choixInt);
				
			}
			else if (choix.equals("n")) {
				p = new Partie(new FabriqJoueur(s));
			}
			p.jeu();
			out.println("La partie est finie");
			if (p.getResultat().perdant != Moulin.getVIDE())
				out.println(p.getResultat().perdant + " a perdu");
			else
				out.println("Match Nul");
			out.println(p.getResultat().resMoulin);
		}
		else if ( choix.equals("t") ) {
			out.println("Voulez vous selectionner le nombre de parties ? (100 par défaut) o/n");
			choix = s.nextLine();
			while (!choix.equals("o") && !choix.equals("n"))
				choix = s.nextLine();
			if (choix.equals("o")) {
				out.print("Entrez le nombre de parties (entre 10 et 100000) : ");
				int nbParties = s.nextInt();
				while (nbParties < 10 || nbParties > 100000)
					nbParties = s.nextInt();
				out.println("Voulez vous selectionner le nombre de tours ? (10 par défaut) o/n");
				choix = s.nextLine();
				while (!choix.equals("o") && !choix.equals("n"))
					choix = s.nextLine();
				if (choix.equals("o")) {
					out.print("Entrez le nombre de tours (entre 10 et 99) : ");
					choixInt = s.nextInt();
					while (choixInt < 10 || choixInt > 99)
						choixInt = s.nextInt();
					t = new Tournoi(new FabriqJoueur(s), choixInt, nbParties);
				}
				else if (choix.equals("n")) {
					t = new Tournoi(new FabriqJoueur(s), nbParties);
				}
				
			}
			else if (choix.equals("n")) {
				t = new Tournoi(new FabriqJoueur(s));
			}
			t.deroulerParties();
			if ( t.gagnantTournoi() != Moulin.getVIDE() )
				out.println( "Le joueur " + t.gagnantTournoi() + " a gagné le tournoi avec "
						+ t.gagnantTournoiScore() + " victoires");
			else
				out.println("Egalité parfaite");
			out.println("Voulez-vous consulter les résultats individuellement ? (o)");
			if (s.next().equals("o")) {
				boolean cont = true;
				do {
					out.println("Entrez l'index de la partie que vous voulez vérifier ? (de 1 à nbParties) ");
					out.println(t.getTablResultats()[s.nextInt() - 1]);
					out.println("Continuer ? (o)");
					if (!s.next().equals("o"))
						cont = false;
				} while (cont);
			}
			
		}
		s.close();
	}

}
