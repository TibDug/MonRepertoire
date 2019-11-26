package sac;
import java.util.ArrayList;

import objet.Objet;

public class Sac {
	private ArrayList<Objet> objetsIn;
	float poidsMax;
	
	
	
	
	
	public Sac(){
		objetsIn = new ArrayList<Objet>();
		poidsMax = 0;
	}
	
	public Sac(float poidsMax2){
		objetsIn = new ArrayList<Objet>();
		poidsMax = poidsMax2;

	}
	
	public boolean ajouterObjet(Objet o){
		if(getPoidsActuel()+o.getPoids() > poidsMax)
			return false;
		objetsIn.add(o);
		return true;
	}

	public ArrayList<Objet> getObjetsIn() {
		return objetsIn;
	}

	public void setObjetsIn(ArrayList<Objet> objetsIn) {
		this.objetsIn = objetsIn;
	}

	public float getPoidsMax() {
		return poidsMax;
	}

	public void setPoidsMax(float poidsMax) {
		this.poidsMax = poidsMax;
	}

	public float getPoidsActuel() {
		float r = 0;
		for(Objet o : objetsIn)
			r += o.getPoids();
		return r;
	}

	
	
	
	public String toString(){
		String ret = "";
		for(Objet o : objetsIn){
			ret += "poids : " + o.getPoids() + " ; valeur : " + o.getValeur() + " ; ratio : " + o.getRatio();
		}
		return ret;
	}

	public float getValeurActuelle() {
		float r = 0;
		for(Objet o : objetsIn)
			r += o.getValeur();
		return r;
	}
	
}
