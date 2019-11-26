package maths;
import java.util.ArrayList;

import objet.Objet;

public class TriObjetsRatio {

	public static void triObjetsRatio(ArrayList<Objet> listeObj){
		for(int i = 0; i < listeObj.size()-1; ++i){
			for(int j = 0; j < listeObj.size()-1-i; ++j){
				if(listeObj.get(j).getRatio() > listeObj.get(j+1).getRatio()){
					Objet temp = listeObj.get(j);
					listeObj.remove(j);
					listeObj.add(j+1, temp);
				}
			}
		}
	}

	
}
