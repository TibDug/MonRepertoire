package ihm;

import java.io.IOException;

import core.ICore;

public class IHM_Implementation implements Runnable {
	
	private ICore core;

	public IHM_Implementation (ICore core) {
		this.core = core;
	}
	
	@Override
	public void run() {
		try {
			new IHM_Menu(core);
		} catch (IOException e) {
			e.printStackTrace();
		}		
	}
}
