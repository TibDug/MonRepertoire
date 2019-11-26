package factory;

import core.InterfaceIHM;
import core.InterfaceIHMFactory;
import ihm.IHMV1;

public class IHMFactory implements InterfaceIHMFactory {

	public InterfaceIHM creerIHM(){
		return new IHMV1();
	}
}
