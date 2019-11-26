package persistantdata;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import mediatheque.*;

// classe mono-instance  dont l'unique instance n'est connue que de la bibliotheque
// via une auto-déclaration dans son bloc static

public class MediathequeData implements PersistentMediatheque {
// Jean-François Brette 01/01/2018
	static {
		try {
			Mediatheque.getInstance().setData(new MediathequeData());
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	private Connection c;

	private MediathequeData() throws ClassNotFoundException, SQLException {

		Class.forName("oracle.jdbc.OracleDriver");
		this.c = DriverManager.getConnection ("jdbc:oracle:thin:@vs-oracle2:1521:ORCL","dugauquier","dug");
	}

	// renvoie la liste de tous les documents de la bibliothèque
	@Override
	public List<Document> tousLesDocuments() throws SQLException {
		List<Document> listeDoc = new ArrayList<Document>();
		
		Statement requete = c.createStatement();
		ResultSet resRequete = requete.executeQuery("SELECT * FROM DOCUMENT");
        
		if (!resRequete.next()) System.out.println("Aucun document enregistré dans la base de données");
		else {
			do {
				int id_doc = resRequete.getInt("id_doc");
				int type_doc = resRequete.getInt("type_doc");
				String titre_doc = resRequete.getString("titre_doc");
				String auteur_doc = resRequete.getString("auteur_doc");
				boolean disponible = resRequete.getBoolean("disponible");
				Document doc = creerDocument(id_doc, type_doc, titre_doc, auteur_doc, disponible);
				listeDoc.add(doc);
			}
			while (resRequete.next());	
		}
		return listeDoc;
	}
	
	private Document creerDocument(int id_doc, int type_doc, String titre_doc, String auteur_doc, boolean disponible) {
		Document doc;
		if (type_doc == 0)
			doc = new Livre(id_doc, titre_doc, auteur_doc, disponible);
		else throw new IllegalArgumentException();
		return doc;
	}

	// va récupérer le User dans la BD et le renvoie
	// si pas trouvé, renvoie null
	@Override
	public Utilisateur getUser(String login, String password) throws SQLException {
		PreparedStatement requete = c.prepareStatement("SELECT * FROM UTILISATEUR WHERE LOGIN_USER = ? AND MDP_USER = ?");
		requete.setString(1, login);
		requete.setString(2, password);
		
		ResultSet resRequete = requete.executeQuery();

		if (!resRequete.next()) System.out.println("Login ou mot de passe incorrect");
		else {
			int id_user = resRequete.getInt("id_user");
			int type_user = resRequete.getInt("type_user");
			String login_user = resRequete.getString("login_user");
			String mdp_user = resRequete.getString("mdp_user");
			Utilisateur user = new Utilisateur(id_user, type_user, login_user, mdp_user);
			return user;
		}
		return null;
	}

	// va récupérer le document de numéro numDocument dans la BD
	// et le renvoie
	// si pas trouvé, renvoie null
	@Override
	public Document getDocument(int numDocument) throws SQLException {
		PreparedStatement requete = c.prepareStatement("SELECT * FROM DOCUMENT WHERE LOGIN_USER = ?");
		requete.setInt(1, numDocument);
		ResultSet resRequete = requete.executeQuery();
        
		if (!resRequete.next()) System.out.println("Document non existant");
		else {
			int id_doc = resRequete.getInt("id_doc");
			int type_doc = resRequete.getInt("type_doc");
			String titre_doc = resRequete.getString("titre_doc");
			String auteur_doc = resRequete.getString("auteur_doc");
			boolean disponible = resRequete.getBoolean("disponible");
			Document doc = creerDocument(id_doc, type_doc, titre_doc, auteur_doc, disponible);
			return doc;
		}
		return null;
	}

	@Override
	public void nouveauDocument(int type, Object... args) {
		switch (type) {
			case 0 : 
				String titre = (String) args[0];
				String auteur = (String) args[1];
			default : System.out.println("Type inexistant");
		}
	}

}
