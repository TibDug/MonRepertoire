package ihm;

import org.junit.Test;

import core.InterfaceIHM;

public class IHMTest {

	@Test
	public void test() {
		
		InterfaceIHM IHM = new IHMV1();
		IHM.affichage("Salut");
		IHM.affichage(IHM.saisie());	
		
	}

}
