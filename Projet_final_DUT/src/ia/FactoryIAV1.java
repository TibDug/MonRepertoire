package ia;

import core.InterfaceIA;
import factory.IFactoryIA;

public class FactoryIAV1 implements IFactoryIA {

	@Override
	public InterfaceIA genererIA() {
		return new IAV1();
	}

}
