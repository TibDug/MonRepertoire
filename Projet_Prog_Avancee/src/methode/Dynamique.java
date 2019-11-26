package methode;
import java.util.ArrayList;

import maths.CalculMax;
import maths.CalculPGCD;
import objet.Objet;
import sac.Sac;

public class Dynamique {
	
	public static Sac remplirSacDynamique(float poidsMax, ArrayList<Objet> objetsO){
		Sac sac = new Sac(poidsMax);
		ArrayList<Objet> objets = objetsO;
		
		int facteur = conversion(objets, sac);
		for(Objet o : objets)
			o.setPoids(o.getPoids() * facteur);
		
		sac.setPoidsMax(sac.getPoidsMax() * facteur);
		
		float M[][] = new float[objets.size()][(int)sac.getPoidsMax()+1];
		for(int i = 0; i < objets.size(); ++i){
			
			for(int j = 0; j <= sac.getPoidsMax(); ++j){
				if(i == 0){
					if(objets.get(0).getPoids() <= j){
						M[0][j] = (int)objets.get(0).getValeur();
						}
					else{
						M[0][j] = 0;
					}
				}
				else{
					if(objets.get(i).getPoids() <= j){
						M[i][j] = CalculMax.max(objets.get(i).getValeur() + M[i-1][j-(int)objets.get(i).getPoids()], M[i-1][j]);
						
					}
					else{
						M[i][j] = M[i-1][j];
					}
				}
			}
			

		}
		
		System.out.println("affichage de la matrice finale, avec un pas de 1/" + facteur + " : ");
		for(int i = 0; i < objets.size(); ++i){
			for(int j = 0; j < (int)sac.getPoidsMax()+1; ++j){
				System.out.print("\t" +M[i][j]);
			}
			System.out.println();
		}
		sac = objetsAjoutesDynamique(M, objets, sac);

		sac.setPoidsMax(sac.getPoidsMax()/facteur);
		
		for(Objet o : sac.getObjetsIn()){
			o.setPoids(o.getPoids()/facteur);
		}
		
		return sac;
		
		
	}
	
	private static Sac objetsAjoutesDynamique (float[][] m, ArrayList<Objet> objets, Sac sac){
		int j = (int) sac.getPoidsMax();
		int i = objets.size()-1;
		while (m[i][j] == m[i][j-1])
			j--;
		while (j > 0){
			while (i > 0 && (m[i][j] == m[i - 1][j])){
				i--;
			}
			j = j - (int) objets.get(i).getPoids();
			if (j >= 0) {
				sac.ajouterObjet(objets.get(i));
			}
			--i;
		}
		
		
		
		return sac;
	}
	
	public static int conversion(ArrayList<Objet> objets, Sac sac){
		float limiteBasse = 1;
		for(Objet o : objets)
			if(o.getPoids()%1 < limiteBasse && o.getPoids()%1 != 0)
				limiteBasse = o.getPoids()%1;
		if(sac.getPoidsMax()%1 < limiteBasse && sac.getPoidsMax()%1 != 0)
			limiteBasse = sac.getPoidsMax()%1;
		int r = 1;
		while((limiteBasse * r)%1 != 0){
			r *= 10;
		}
		return r/CalculPGCD.PGCD((int) (limiteBasse * r), 10);
	}

}
