package appli;

import core.ICore;
import coreComponents.Core;
import ihm.IHM_Implementation;

public class Main {

	public static void main(String[] args) {
		ICore core = new Core();
		System.out.println(core);
		System.out.println();
		core.init();
		System.out.println(core);
		System.out.println();
		core.launch();
		System.out.println(core);
	}

}
