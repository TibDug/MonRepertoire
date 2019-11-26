package main;

public class Main {

	public static void main(String[] args) {
		SacADos sad;
		if(args.length < 3){
			System.out.println("Demonstration : ");
			sad = new SacADos();
			sad.methodeGloutonne();
			sad.methodeDynamique();
			sad.methodePSE();
			return;
		}
		sad = new SacADos(args[0], Float.parseFloat(args[1]));
		switch(args[2]){
			case "gloutonne" :
				
				sad.methodeGloutonne();
				break;
			case "dynamique" :

				
				sad.methodeDynamique();
				break;
			case "PSE" :

				
				sad.methodePSE();
				break;
			default :

				
				break;
				
		}
	}
	

}
