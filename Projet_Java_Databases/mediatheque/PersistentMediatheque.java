package mediatheque;

import java.sql.SQLException;
import java.util.List;

public interface PersistentMediatheque {
// Jean-François Brette 01/01/2018
	List<Document> tousLesDocuments() throws SQLException;

	Document getDocument(int numDocument) throws SQLException;

	Utilisateur getUser(String login, String password) throws SQLException;
	
	void nouveauDocument(int type, Object... args );

}
