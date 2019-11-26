package persistantdata;

import mediatheque.Document;
import mediatheque.EmpruntException;
import mediatheque.Utilisateur;

public class Livre implements Document {
	
	private int id;
	private String titre;
	private String auteur;
	private boolean disponible;

	public Livre(int id_doc, String titre_doc, String auteur_doc, boolean disponible) {
		this.id = id_doc;
		this.titre = titre_doc;
		this.auteur = auteur_doc;
		this.disponible = disponible;
	}

	@Override
	public void emprunter(Utilisateur a) throws EmpruntException {
		
	}

	@Override
	public void retour() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public Object[] affiche() {
		// TODO Auto-generated method stub
		return null;
	}
	
}
