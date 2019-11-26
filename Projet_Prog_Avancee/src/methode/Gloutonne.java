package methode;
import java.util.ArrayList;

import objet.Objet;
import sac.Sac;

public class Gloutonne {

	public static Sac remplirSacGlouton(Sac sac, ArrayList<Objet> listeObj){

		for(int i = listeObj.size()-1; i >= 0; --i)
			sac.ajouterObjet(listeObj.get(i));
			
		
		return sac;
	}
	
	
}
