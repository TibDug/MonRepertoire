package ihm;

import java.util.Scanner;

import core.InterfaceIHM;

public class IHMV1 implements InterfaceIHM{
	
	private Scanner sc;
	//private String message = null;

	public IHMV1() {
		this.sc = new Scanner(System.in);
	}
	
	public String saisie() {
		return sc.nextLine();
	}
	
	public void affichage(String param) {		
		 System.out.println(param);		
	}

	
	
}
