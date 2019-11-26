package main;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


import maths.TriObjetsRatio;
import methode.Dynamique;
import methode.Gloutonne;
import methode.PSE;
import objet.Objet;
import sac.Sac;

public class SacADos {
	

	float poidsMax = 30;
	Sac sac;
	ArrayList<Objet> objets;
	
	public SacADos(String chemin, float poidsMax){

		this.poidsMax = poidsMax;
		objets = lireObjets(chemin);
		afficherObjets();
	}
	
	
	public SacADos(){
		objets = lireObjets("src\\objets.txt");
		afficherObjets();
		
	}
	
	public ArrayList<Objet> lireObjets(String filename){
		ArrayList<Objet> l = new ArrayList<Objet>();
		
		
		try (BufferedReader br = new BufferedReader(new FileReader(filename))) {

			String sCurrentLine;
			while ((sCurrentLine = br.readLine()) != null) {
				String[] parties = sCurrentLine.split(";");
				if(parties.length != 3)
					continue;
				l.add(new Objet(parties[0].trim(), Float.parseFloat(parties[1].trim()), Float.parseFloat(parties[2].trim())));
			}

		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
		return l;
	}
	
	
	public void methodeGloutonne(){ // si Gloutonne est sélectionnée, construction du sac à partir de Gloutonne grâce à cette fonction
		System.out.println("on lance la méthode gloutonne  : ");
		sac = new Sac(poidsMax);
		TriObjetsRatio.triObjetsRatio(objets);
		
		sac =  Gloutonne.remplirSacGlouton(sac, objets);
		afficherSolution();
	}
	
	public void methodeDynamique(){ // si Dynamique est sélectionnée, construction du sac à partir de Dynamique grâce à cette fonction
		System.out.println("on lance la méthode dynamique  : ");
		sac = new Sac(poidsMax);
		sac =  Dynamique.remplirSacDynamique(poidsMax, objets);
		afficherSolution();
	}
	
	public void methodePSE(){  // si PSE est sélectionnée, construction du sac à partir de PSE grâce à cette fonction
		System.out.println("on lance la méthode PSE  : ");
		sac = new Sac(poidsMax);
		PSE exemple = new PSE();
		exemple.setObjets(objets);
		sac =  exemple.genererSolutions(poidsMax);
		afficherSolution();
	}
	
	public void afficherSolution(){
		System.out.println("\n======================================");
		System.out.println("===============SOLUTION===============");
		System.out.println("======================================\n");
		System.out.println("Les objets contenus dans la solution finale sont les suivants :");
		for(Objet o : sac.getObjetsIn())
			System.out.println(o);
		System.out.println("\nLe poids final du sac est de " + sac.getPoidsActuel() + " et la valeur totale contenue est de " + sac.getValeurActuelle() + "\n\n");
	} 
	
	public void afficherObjets(){
		System.out.println("Voici les objets dont nous disposons :");
		for(Objet o : objets)
			System.out.println(o);
		
		System.out.println("\n");
	}

}
