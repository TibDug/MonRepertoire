package mediatheque;

public class Utilisateur {

	private int id;
	private int type;
	private String login;
	private String mdp;

	public Utilisateur(int id_user, int type_user, String login_user, String mdp_user) {
		this.id = id_user;
		this.type = type_user;
		this.login = login_user;
		this.mdp = mdp_user;
	}
	
}
