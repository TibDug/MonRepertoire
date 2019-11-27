package moulin;


public class Moulin {
	private static final  int TAILLE = 3;		// largeur et hauteur
	private static final  int ALIGNES = 3;		// pour gagner
	private static final  int NBJOUEURS = 2;   	// nombre de joueurs
	private static final  int MAXPIONS = 6;		// 3 croix et 3 ronds
	private static final  int MINDUMAX = 10;		// minimum pour maxCoups
	private static final  int MAXDUMAX = 99;		// maximum pour maxCoups
	private static final  int MININDEX = 1;
	private static final  int MAXINDEX = 3;
	private static final  int MAXALIGNEMENTS = 1;
	private static final char VIDE = '.';
	
	private static final char[] SYMBOLES = {'O','X'};
	private char[][] terrain = new char[TAILLE][TAILLE];
	private int nbCoups;
	private int joueur;							// 0 pour 'O' et 1 pour 'X'
	private int maxCoups;						// nombre maximum de coups
	
	/**
	 * Constructeur du jeu du Moulin
	 * @param maxCoups le nombre maximum de coups permis pour une partie de Moulin
	 */
    public Moulin(int maxCoups) {
		assert(maxCoups >= MINDUMAX);
		assert(maxCoups <= MAXDUMAX);
		this.maxCoups = maxCoups;
		this.nbCoups = 0;
		for (int x = 0; x < TAILLE; ++x)
			for (int y=0; y< TAILLE; ++y)
				terrain[x][y] ='.';
		this.joueur = 0;
	}
    
    /**
     * Constructeur du jeu du Moulin, avec un nombre de coups par defaut minimum
     */
    public Moulin() {
    	this(MINDUMAX);
    }

	/**
	 * Constructeur du jeu du Moulin déjà commencé, avec un nombre de coup par defaut maximum
	 * @param s la grille du jeu du Moulin
	 */
	public Moulin(String s) {
		this(MAXDUMAX);
		char pion;
		final int N = TAILLE;
		int i, j=0; 					         // j est l'indice du prochain caractère traité en commencant à 0
		assert (s.length() == N*(N + 1) +1)	     // N+1 à cause des \n
		       || (s.length() == N*(N + 1) +2);  //  puis 1 ou deux chiffres pour le nombre de coups
		for (int y = N-1; y >= 0; --y) {
			for (int x = 0; x < N; ++x, ++j) {
				if (j % (N + 1) == N) {
					assert s.charAt(j) == '\n';
					++j;
				}
				pion = s.charAt(j);
				terrain[x][y] = pion;
				if (pion == 'X' || pion == 'O')
					++nbCoups;
			}
		}
		++j; // saute le dernier '\n'
		nbCoups = s.charAt(j++) - '0';
		if (s.length() == N*(N + 1) +2) {   // 2 chiffres à la fin 
			nbCoups *=10;
			nbCoups += s.charAt(j) - '0';
		}
		joueur = nbCoups%2;
	}

	/**
	 * Permet de laisser jouer l'autre joueur
	 */
	void passerAujoueurSuivant()  {
		++nbCoups;
		joueur = (joueur + 1) % NBJOUEURS;
	}
	
	/**
	 * Permet d'obtenir le nombre de coups maximum pour une partie de Moulin
	 * @return le nombre de coups maximum
	 */
	int getMaxCoups(){
		return this.maxCoups;
	}
	
	/**
	 * Permet de savoir si une case désignée par un joueur est valide
	 * @param x l'abscisse de la case désignée
	 * @param y l'ordonnée de la case désignée
	 * @return vrai si la case est valide
	 */
	public static boolean xyEstValide(int x, int y) {
		return x >=1 && y >= 1 && x<= TAILLE && y<= TAILLE;
	}
	
	/**
	 * Permet d'obtenir le nombre de coups joués lors d'une partie de Moulin
	 * @return
	 */
	public int getNBCoups() {
		return nbCoups;
	}
	
	/**
	 * Permet d'obtenir le type du pion présent sur une case
	 * @param x abscisse de la case dont on veut savoir le pion
	 * @param y ordonnée de la case dont on veut savoir le pion
	 * @return le type de pion présent sur la case
	 */
	public char getPion(int x, int y) {
		assert(xyEstValide(x, y));
		return terrain[x-1][y-1];
	}

	/**
	 * Permet de placer un pion sur une case
	 * @param x abscisse de la case sur laquelle on veut placer le pion
	 * @param y ordonnée de la case sur laquelle on veut placer le pion
	 */
	public void placer(int x, int y) {
		assert(getPion(x, y) == VIDE);
		assert(getNBCoups() < MAXPIONS);
		terrain[x-1][y-1] = aQui();
		passerAujoueurSuivant();		
	}
	
	/**
	 * Permet de déplacer un pion d'une case à une autre
	 * @param x1 abscisse de la case sur laquelle se trouve le pion
	 * @param y1 ordonnée de la case sur laquelle se trouve le pion
	 * @param x2 abscisse de la case sur laquelle doit se déplacer le pion
	 * @param y2 ordonnée de la case sur laquelle doit se déplacer le pion
	 */
	public void déplacerEn(int x1, int y1, int x2, int y2) {
		assert peutDéplacerEn(x1, y1, x2, y2);
		terrain[x2-1][y2-1] = terrain[x1-1][y1-1];
		terrain[x1-1][y1-1] = VIDE;
		passerAujoueurSuivant();		
	}
	
	/**
	 * Permet de savoir quel joueur doit jouer
	 * @return le symbole correspond au joueur dont c'est le tour
	 */
	public char aQui() {
		return SYMBOLES[joueur];
	}

	/**
	 * Permet d'afficher la grille du jeu du Moulin
	 */
	@Override
	public String toString() {
		final int N = TAILLE;
		StringBuilder s = new StringBuilder(N*(N+1)+1);
		for (int y = N; y >= 1; --y) {
			for (int x = 1; x <= N; ++x)
				s.append(getPion(x, y));
			s.append("\n");
		}
		s.append(getNBCoups());
		return s.toString();
	}


	/**
	 * permet de vérifier s'il y a un alignement sur la grille du Moulin, à partir d'une case
	 * @param x abscisse de la case pour laquelle on vérifie s'il y a un alignement
	 * @param y ordonnée de la case pour laquelle on vérifie s'il y a un alignement
	 * @return vrai s'il y a un alignment
	 */
	public boolean alignement(int x, int y) {
		final int N =TAILLE;
		final int NBDIR = 4;
		int[] dx = {1, 1, 0, -1};
		int[] dy = {0, 1, 1, 1};
		char pion = getPion(x, y);
		if (pion == VIDE)
			return false;
		int nbPionsAAligner = 0;
		// on va considérer toutles les lignes (xi,yi) autour de (x,y)
		// de longueur ALIGNES
		int k,			// indique à la fois la distance par rapport à (x,y)
						// en nombre de case et le sens de déplacement
						// négatif si on est reparti en arrière depuis (x,y)
		d, 				// direction
		xi, yi;			// les pions en (xi,yi) doivent etre comme en (x,y)
		// si on ne compte pas la case (x,y) elle-même on doit trouver
		// ALIGNES - 1 pions identiques
		// pour une direction donnée, dans un sens ou un autre
		for (d = 0; d < NBDIR; ++d) {
			for (nbPionsAAligner = ALIGNES - 1, k = 1; nbPionsAAligner > 0;) {
				xi = x + k*dx[d];
				yi = y + k*dy[d];
				if (!xyEstValide(xi, yi))
					if (k < 0)		  // on est déjà dans l'autre sens
						break;
					else {
						k = -1;	  // on part dans l'autre sens
						continue;
					}
				if (getPion( xi, yi) != pion)
						break;
				else {
					--nbPionsAAligner;
					if (nbPionsAAligner == 0)  // ALIGNEMENT !
						return true;
					if (k < 0)
						--k;
					else ++k;
				}
			}
		}
		return false;
	}

	/**
	 * Vérifie s'il y a un aligmement sur la totalité de la grille du Moulin
	 * @return vrai s'il y a un alignement
	 */
	public boolean alignement() {
		int N = TAILLE;
		for (int y = N; y >= 1; --y)
			for (int x = 1; x <= N; ++x)
				if (alignement(x, y))
					return true;
		return false;
	}
	
	/**
	 * Vérifie si le déplacement d'un pion est possible
	 * @param x1 abscisse de la case sur laquelle se trouve le pion
	 * @param y1 ordonnée de la case sur laquelle se trouve le pion
	 * @param x2 abscisse de la case sur laquelle doit se déplacer le pion
	 * @param y2 ordonnée de la case sur laquelle doit se déplacer le pion
	 * @return vrai si le déplacement est possible
	 */
	public boolean peutDéplacerEn(int x1, int y1, int x2, int y2) {
		char pion = getPion(x1, y1);
		return xyEstValide(x1, y1) && xyEstValide(x2, y2) 
				&& pion != VIDE 
				&& getPion(x2, y2) == VIDE
				&& pion == aQui()
				&& casesJoignables(x1,y1,x2,y2);
	}
	
	/**
	 * Vérifie si un pion peut être posé sur une case
	 * @param x abscisse de la case sur laquelle le pion doit être posé
	 * @param y ordonnée de la case sur laquelle le pion doit être posé
	 * @return vrai si le pion peut être posé sur la case en question
	 */
	public boolean peutPoserEn(int x, int y) {
		return xyEstValide(x, y) && getPion(x,y) == VIDE;
	}
	
	/**
	 * Vérifie s'il est possible de se déplacer d'une case à une autre
	 * @param x1 abscisse de la première case
	 * @param y1 ordonnée de la première case
	 * @param x2 abscisse de la seconde case
	 * @param y2 ordonnée de la seconde case
	 * @return vrai si le déplacement est possible
	 */
	boolean casesJoignables(int x1, int y1, int x2, int y2) {
		int N = TAILLE;
		if (y1 == x1 || y1 == N+1 - x1 ) // grandes diagonales
			return Math.abs(x2 - x1) <= 1 && Math.abs(y2 - y1) <= 1;
		else return Math.abs(x2 - x1) + Math.abs(y2 - y1) == 1;
	}

	/**
	 * Vérifie si la partie de Moulin est terminée
	 * @return vrai si la partie est terminée
	 */
	public boolean estFinie() {
		return this.nbCoups == this.maxCoups || alignement();
	}

	/**
	 * Permet de connaître la taille de la grille du Moulin
	 * @return la taille de la grille
	 */
	public static int getTaille() {	return TAILLE; }
	
	/**
	 * Permet de connître le nombre maximum de pions que la grille du Moulin peut supporter
	 * @return le nombre maximum de pions que la grille peut supporter
	 */
	public static int getMaxPions() { return MAXPIONS; }
	
	/**
	 * Permet d'obtenir le caractère correspondant à une cas vide sur la grille du Moulin
	 * @return le caractère correspondant à une cas vide sur la grille
	 */
	public static char getVIDE() { return VIDE; }
	
	/**
	 * Permet d'obtenir le nombre maximum d'alignements tolérés lors d'une partie de Moulin
	 * @return le nombre maximum d'alignements tolérés
	 */
	public static int getMaxAlignements() { return MAXALIGNEMENTS; }
	
	/**
	 * Permet d'obtenir la taille de la grille du Moulin
	 * @return la taille de la grille
	 */
	public static int getIndexMax() { return MAXINDEX; }
	
	/**
	 * Permet d'obtenir la valeur minimale de l'index de la grille du Moulin
	 * @return la valeur minimale de l'index de la grille
	 */
	public static int getIndexMin() { return MININDEX; }
	
	/**
	 * Permet d'obtenir le nombre de joueurs tolérés lors d'une partie de Moulin
	 * @return le nombre de joueurs tolérés
	 */
	public static int getNBJoueurs() { return NBJOUEURS; }
	
	/**
	 * permet d'obtenir les symboles utilisés pour le jeu du Moulin
	 * @return les symboles utilisés pour le Moulin (X et O)
	 */
	public static char[] getSymbols() { return SYMBOLES; }
}