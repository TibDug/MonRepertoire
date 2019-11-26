package maths;

public class CalculPGCD {

	public static int PGCD(int a, int b){
		int r = a;
		while(r != 0){
			r = a%b;
			a = b;
			b = r;
			
		}
		return Math.abs(a);
	}
	
}
