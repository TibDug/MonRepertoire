package joueur;

import moulin.Moulin;
import partie.IJoueur;

public class IAminmax implements IJoueur {
	private char pion;
	private static final int INFINI = 10000;
	private static final int PROFONDEUR_DEFAUT = 2;
	
	/**
	 * Permet de savoir quel est le pion utilisé par l'IA
	 */
	public char getPion() { return this.pion; }
	
	/**
	 * Permet à l'IA de jouer au Moulin avec la profondeur par defaut,
	 * en respenctant l'algorithme Min-Max
	 * @param m le jeu du Moulin
	 */
	public void jouer(Moulin m) { jouer(m, PROFONDEUR_DEFAUT); }
	
	/**
	 * Permet à l'IA de jouer au jeu du Moulin avec une profondeur définie,
	 * en respectant l'algorithme Min-Max
	 * @param m le jeu du Moulin
	 * @param profondeur la profondeur de l'algorithme Min-Max appliqué à l'IA
	 */
	public void jouer(Moulin m, int profondeur)
	{
		if (m.getNBCoups() < Moulin.getNBJoueurs())
			this.pion = m.aQui();
		int max = -INFINI;
		int tmp; 
		int maxX = 0, maxY = 0, maxX2 = 0, maxY2 = 0;
		int i, j;
		Moulin copyM = new Moulin (m.toString());

		for(i = 1; i <= Moulin.getTaille(); ++i)
	    {
			for(j = 1; j <= Moulin.getTaille(); ++j)
			{
				if ( (copyM.getNBCoups() < Moulin.getMaxPions()) &&   
					 (copyM.getPion(i, j) == Moulin.getVIDE()) ) 
	            {
	                	  
					copyM.placer(i, j); 
					tmp = min(copyM, profondeur - 1);
	                      
					if(tmp > max)
					{
						max = tmp;
						maxX = i;
						maxY = j;
					}
					copyM = new Moulin (m.toString());
	            
	            } else if ( (copyM.getNBCoups() >= Moulin.getMaxPions()) && copyM.getPion(i, j) == copyM.aQui() ) {
	            	for (int k = -1; k <= 1; ++k) {
	            		for (int l = -1; l <= 1; ++l) {
	            			if (copyM.peutDéplacerEn(i, j, i+k, j+l)) {
	            				
	            				copyM.déplacerEn(i, j, i+k, j+l);
	            				tmp = min(copyM, profondeur - 1);
	  	                      
	        					if(tmp > max)
	        					{
	        						max = tmp;
	        						maxX = i;
	        						maxY = j;
	        						maxX2 = i+k;
	        						maxY2 = j+l;
	        					}
	        					copyM = new Moulin (m.toString());
	            			}
	            		}
	            	}
	            }
			}
	    }
		
		if (copyM.getNBCoups() < Moulin.getMaxPions())
			m.placer(maxX, maxY);
		else
			m.déplacerEn(maxX, maxY, maxX2, maxY2);

	}


	/**
	 * Permet de prévoir le meilleur coup de l'adversaire
	 * @param m le jeu du Moulin
	 * @param profondeur la profondeur de l'algorithme Min-Max appliqué à l'IA
	 * @return la valuation de min
	 */
	private int min(Moulin m, int profondeur)
	{
		if( profondeur == 0 || m.alignement() )
		{
			return eval(m);
		}

		int min = INFINI;
		int i,j,tmp;
		Moulin copyM = new Moulin (m.toString());
		
		for(i = 1; i <= Moulin.getTaille(); ++i)
	    {
			for(j = 1; j <= Moulin.getTaille(); ++j)
			{
				if ( (copyM.getNBCoups() < Moulin.getMaxPions()) &&
					 (copyM.getPion(i, j) == Moulin.getVIDE()) ) 
	            {
	                	  
					copyM.placer(i, j);
					tmp = max(copyM, profondeur - 1);
	                      
					if(tmp < min)
					{
						min = tmp;
					}
					copyM = new Moulin (m.toString());
	            
	            } else if ( (copyM.getNBCoups() >= Moulin.getMaxPions()) && copyM.getPion(i, j) == copyM.aQui() ) {
	            	for (int k = -1; k <= 1; ++k) {
	            		for (int l = -1; l <= 1; ++l) {
	            			if (copyM.peutDéplacerEn(i, j, i+k, j+l)) {
	            				
	            				copyM.déplacerEn(i, j, i+k, j+l);
	            				tmp = min(copyM, profondeur - 1);
	  	                      
	            				if(tmp < min)
	        					{
	        						min = tmp;
	        					}
	        					copyM = new Moulin (m.toString());
	            			}
	            		}
	            	}
	            }
			}
	    }
	    return min;
	     
	}

	/**
	 * Permet de prévoir de meilleur coup pour l'IA
	 * @param m le jeu du Moulin
	 * @param profondeur la profondeur de l'algorithme Min-Max appliqué à l'IA
	 * @return la valuation de max
	 */
	private int max(Moulin m, int profondeur)
	{
		if( profondeur == 0 || m.alignement() )
		{
			return eval(m);
		}

	    int max = -INFINI;
	    int i,j,tmp;
	    Moulin copyM = new Moulin (m.toString());
			
		for(i = 1; i <= Moulin.getTaille(); ++i)
		{
			for(j = 1; j <= Moulin.getTaille(); ++j)
			{
				if ( (copyM.getNBCoups() < Moulin.getMaxPions()) &&   
					 (copyM.getPion(i, j) == Moulin.getVIDE()) ) 
				{
		                	  
					copyM.placer(i, j); 
					tmp = min(copyM, profondeur - 1);
		                      
					if(tmp > max)
					{
						max = tmp;
					}
					copyM = new Moulin (m.toString());
		            
				} else if ( (copyM.getNBCoups() >= Moulin.getMaxPions()) && copyM.getPion(i, j) == copyM.aQui() ) {
		            for (int k = -1; k <= 1; ++k) {
		           		for (int l = -1; l <= 1; ++l) {
		           			if (copyM.peutDéplacerEn(i, j, i+k, j+l)) {
		            				
		           				copyM.déplacerEn(i, j, i+k, j+l);
		           				tmp = min(copyM, profondeur - 1);
		  	                      
		           				if(tmp > max)
		       					{
		       						max = tmp;
		       					}
		        				copyM = new Moulin (m.toString());
		           			}
		           		}
		           	}
				}
			}
		}
	    return max;
	     
	}

	/**
	 * Compte le nombre de séries de n pions alignés de chacun des joueurs
	 * @param m le jeu du Moulin
	 * @param n le nombre de pions alignés que l'on veut controler
	 * @return la valuation relative au nombre de série de chacun des joueurs
	 */
	private int ptn_nb_series(Moulin m, int n)
	{ 
	     int compteur1, compteur2, series_j1, series_j2, i, j;

	     compteur1 = 0;
	     compteur2 = 0;
	     series_j1 = 0;
	     series_j2 = 0;
	     
	     for(i = 1; i <= Moulin.getTaille(); ++i)
	     {
	          if(m.getPion(i, i) == this.getPion())
	          {
	               compteur1++;

	               if(compteur1 == n)
	               {
	                    series_j1++;
	               }
	          }
	          else if(m.getPion(i, i) != this.getPion())
	          {
	               compteur2++;

	               if(compteur2 == n)
	               {
	                    series_j2++;
	               }
	          }
	     }

	     compteur1 = 0;
	     compteur2 = 0;

	     for(i = 1; i <= Moulin.getTaille(); ++i)
	     {
	          if(m.getPion(i, 4-i) == this.getPion())
	          {
	               compteur1++;

	               if(compteur1 == n)
	               {
	                    series_j1++;
	               }
	          }
	          else if(m.getPion(i, 4-i) != this.getPion())
	          {
	               compteur2++;

	               if(compteur2 == n)
	               {
	                    series_j2++;
	               }
	          }
	     }

	     //En ligne
	     for(i = 1; i <= Moulin.getTaille(); ++i)
	     {
	          compteur1 = 0;
	          compteur2 = 0;
	        
	          for(j = 1; j <= Moulin.getTaille(); ++j)
	          {
	               if(m.getPion(i, j) == this.getPion())
	               {
	                    compteur1++;

	                    if(compteur1 == n)
	                    {
	                         series_j1++;
	                    }
	               }
	               else if(m.getPion(i, j) != this.getPion())
	               {
	                    compteur2++;

	                    if(compteur2 == n)
	                    {
	                         series_j2++;
	                    }
	               }
	          }

	          compteur1 = 0;
	          compteur2 = 0;

	          for(j = 1; j <= Moulin.getTaille(); ++j)
	          {
	               if(m.getPion(j, i) == this.getPion())
	               {
	                    compteur1++;

	                    if(compteur1 == n)
	                    {
	                         series_j1++;
	                    }
	               }
	               else if(m.getPion(j, i) != this.getPion())
	               {
	                    compteur2++;

	                    if(compteur2 == n)
	                    {
	                         series_j2++;
	                    }
	               }
	          }
	     }
	     return series_j1 - series_j2;
	}
	
	/**
	 * Permet d'évaluer le jeu du Moulin, en cherchant s'il y a un alignement,
	 * ou qui est plus enclin à gagner, en fonction des pions déjà placés
	 * @param m le jeu du Moulin
	 * @return la valuation du jeu du Moulin
	 */
	private int eval(Moulin m)
	{
		
		if ( m.alignement() )
		{
			if( m.aQui() != this.getPion() )
			{
				return 1000 - m.getNBCoups();
			}
			else 
			{
				return -1000 + m.getNBCoups();
			}
		}
	     
		int pnt = ptn_nb_series(m, 2);
		if (pnt > Moulin.getMaxAlignements() ) { pnt = 10; }

		if ( m.getNBCoups() >= Moulin.getMaxPions() ) {
			
			for(int i = 1; i <= Moulin.getTaille(); ++i)
			{
				for(int j = 1; j <= Moulin.getTaille(); ++j)
				{
					if (m.getPion(i, j) == m.aQui())
					{
						for (int k = -1; k <= 1; ++k)
						{
			           		for (int l = -1; l <= 1; ++l)
			           		{
			           			if (m.peutDéplacerEn(i, j, i+k, j+l))
			           			{
			           				++pnt;
			           			}
			           		}
						}
					}
				}
				
			}
		}
		
		if (m.aQui() == this.getPion())
			return pnt;
		else
			return -pnt;
		
	}


	
}
