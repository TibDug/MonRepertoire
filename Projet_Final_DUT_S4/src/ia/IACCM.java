package ia;

import core.InterfaceIA;
import coreComponents.Core;

public abstract class IACCM extends Core{
	
	public static InterfaceIA genererIA() {
		return new IAV1();
	}
	

}
