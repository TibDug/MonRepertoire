package joueur;

import java.util.Random;
import java.util.ArrayList;

import point.Point;
import moulin.Moulin;
import partie.IJoueur;

public class IArandom implements IJoueur {
	private char pion;
	private Random rand;
	
	/**
	 * Constructeur d'une IA Random
	 */
	public IArandom() {
		rand = new Random();
	}
	
	/**
	 * Permet de savoir quel est le pion utilisé par l'IA
	 */
	public char getPion() { return this.pion; }
	
	/**
	 * Permet à l'IA de jouer de façon aléatoire au jeu du Moulin
	 * @param m le jeu du Moulin
	 */
	public void jouer(Moulin m)
	{
		if (m.getNBCoups() < Moulin.getNBJoueurs())
			this.pion = m.aQui();
		

		if ( m.getNBCoups() < Moulin.getMaxPions() ) 
	    {
			int x,y;
			do {
			x = nombreAleatoire(Moulin.getIndexMin(), Moulin.getIndexMax());
			y = nombreAleatoire(Moulin.getIndexMin(), Moulin.getIndexMax());
			
			} while(m.getPion(x, y) != Moulin.getVIDE());
				m.placer(x, y);
					
	    } else if ( (m.getNBCoups() >= Moulin.getMaxPions()) ) {
	    	ArrayList<Point> positionPions = new ArrayList<Point>();
	    	for(int i = 1; i <= Moulin.getTaille(); ++i)
	    	{
	    		for(int j = 1; j <= Moulin.getTaille(); ++j)
	    		{
	    			if ( m.getPion(i, j) == this.getPion() )
	    				positionPions.add(new Point(i,j));
	    		}
	    	}
	    	Point pionAleatoire;
	    	ArrayList<Point> deplacementsPion = new ArrayList<Point>();
	    	while (deplacementsPion.size() < 1) {
	    		pionAleatoire = positionPions.get(nombreAleatoire(0, positionPions.size() - 1));
	    		for(int k = -1; k <= 1; ++k)
	    		{
	    			for(int l = -1; l <= 1; ++l)
	    			{
	    				if ( m.peutDéplacerEn(pionAleatoire.x, pionAleatoire.y, pionAleatoire.x + k, pionAleatoire.y + l) )
	    					deplacementsPion.add(new Point(pionAleatoire.x + k, pionAleatoire.y + l));
	    			}
	    		}
	    		if (deplacementsPion.size() > 0) {
	    			Point deplAleatoire = deplacementsPion.get(nombreAleatoire(0, deplacementsPion.size() - 1));
	    			m.déplacerEn(pionAleatoire.x, pionAleatoire.y, deplAleatoire.x, deplAleatoire.y);
	    		}
	    	}
	    }
		
	}
	
	/**
	 * Permet de renvoyer un nombre aléatoire entre deux borne
	 * @param borneInf borne inférieure par rapport à laquelle on va choisir le nombre aléatoire
	 * @param borneSup borne supérieure par rapport à laquelle on va choisir le nombre aléatoire
	 * @return un nombre aléatoire entre borneInf et borneSup
	 */
	private int nombreAleatoire(int borneInf, int borneSup) 
	{
		int alea = rand.nextInt(borneSup - borneInf + 1);
		return alea + borneInf;
	}
}