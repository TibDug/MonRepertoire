package methode;
import java.util.ArrayList;


import objet.Objet;
import sac.Sac;

public class PSE {

	
	private ArrayList<Objet> objets;
	private int borneInf;
	
	
	public Sac genererSolutions(float poidsMax) {
		Sac sac = new Sac(poidsMax);
		return rec(sac, objets.size());
		
	}
	
	
	
	private Sac rec(Sac sac , int numObjet){
		float borneSup = 0, poidsActuel = 0;
		for (Objet o : sac.getObjetsIn()){
			borneSup += o.getValeur();
			poidsActuel+=o.getPoids();
		}
		for(Objet o : objets)
			borneSup += o.getValeur();
		if(poidsActuel > sac.getPoidsMax()){
			return sac;
		}
		if(numObjet > 0){
			for(int i = objets.size() - numObjet; i < objets.size()-1; ++i){
				borneSup += objets.get(i).getValeur();
			}			
			if (borneSup < borneInf){	//test de borne supérieure
				return sac;
			}			
			Sac sacCopie = new Sac(sac.getPoidsMax());
			Sac sacCopie2 = new Sac(sac.getPoidsMax());
			sacCopie.getObjetsIn().addAll(sac.getObjetsIn());

			sacCopie2.getObjetsIn().addAll(sac.getObjetsIn());
			Sac rec1 = rec(sacCopie, numObjet-1);
			sacCopie2.getObjetsIn().add(objets.get(numObjet-1));
			Sac rec2 = rec(sacCopie2, numObjet-1);
			if(rec1.getValeurActuelle() > rec2.getValeurActuelle())
				return rec1;
			return rec2;
		}
		else{
			
			
			
			return sac;
			
		}
	}
	
	public static ArrayList<Objet> PSERec(ArrayList<Objet> objets, int poidsRestant){
		if(objets.size() == 1){
			if(objets.get(0).getPoids() > poidsRestant)
				objets.remove(0);
			return objets;
		}
		
		
		if(objets.get(0).getPoids() > poidsRestant){
			objets.remove(0);
			return PSERec(objets, poidsRestant);
		}
		else{
			Objet o = objets.remove(0);
			ArrayList<Objet> r = PSERec(objets, poidsRestant-(int)o.getPoids());
			r.add(0, o);
			return r;
		}
	}
	
	
	
	
	
	public ArrayList<Objet> getObjets() {
		return objets;
	}
	public void setObjets(ArrayList<Objet> objets) {
		this.objets = objets;
	}
	
	public PSE(){
		
		objets = new ArrayList<Objet>();
	}

	
	
}
