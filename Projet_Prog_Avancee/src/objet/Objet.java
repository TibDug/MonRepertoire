package objet;
import java.util.ArrayList;

public class Objet {
	private String nom;
	private float poids, valeur, ratio;
	
	public Objet(float p, float v){
		poids = p;
		valeur = v;
		ratio = v/p;
	}
	
	public Objet(String n, float p, float v){
		nom = n;
		poids = p;
		valeur = v;
		ratio = v/p;
	}
	


	public float getPoids() {
		return poids;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public void setPoids(float poids) {
		this.poids = poids;
	}

	public float getValeur() {
		return valeur;
	}

	public void setValeur(float valeur) {
		this.valeur = valeur;
	}

	public float getRatio() {
		return ratio;
	}

	public void setRatio(float ratio) {
		this.ratio = ratio;
	}
	
	public static void afficherListeObjets(ArrayList<Objet> liste){
		for(Objet o : liste){
			System.out.println("objet de poids " + o.getPoids() + ", de valeur " + o.getValeur()+ " et de ratio " + o.getRatio());
		}
	}


    public String toString(){
    	return nom + " ; " + Float.toString(poids) + " ; " + Float.toString(valeur) + " ; " + Float.toString(ratio);
    }
    
}