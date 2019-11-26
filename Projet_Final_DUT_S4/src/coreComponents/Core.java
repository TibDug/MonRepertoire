package coreComponents;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;

import core.ICore;
import core.InterfaceIA;

public class Core implements ICore {

	static{
		instance = new Core();
		
	}
	private final String initFile;
	private static Core instance;
	private List<Class<? extends Runnable>> ihm;
	private InterfaceIA classifierAI;
	
	
	public Core() {
		initFile = "init";
		ihm = new ArrayList<Class<? extends Runnable>>();
		
	}

	//WARNING : N'EST PAS THREAD-SAFE !!!!!
	
	//TODO: TESTS
	
	
	//Cette fonction initialise la liste des components, puis charge dans l'ordre les components précisés
	@Override
	public void init() {
		try {
			List<Class<?>> loadedComponents = getComponentsFromFile(initFile);
		
		for(Class<?> c : loadedComponents){
			try {
				if(aiCheck(c) && this.classifierAI == null){
					//TODO: Code sale, peut-on faire autrement qu'un cast ???
					this.classifierAI = (InterfaceIA) c.newInstance();
				}
				else if(runnableCheck(c)){
					//TODO: Code sale, peut-on faire autrement qu'un cast ???
					this.ihm.add((Class<? extends Runnable>) c);
				}
				else{
					throw new UnknownComponentTypeException();
				}
				
			} catch (UnknownComponentTypeException e) {
				System.err.println("Le CoreComponent : " + c.toString() + "n'a pas pu être lancé");
				e.printStackTrace();
			} catch (InstantiationException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
		}
	} catch (IOException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();
	}
}
	
	private boolean aiCheck(Class<?> c){
		return InterfaceIA.class.isAssignableFrom(c);
	}
	
	//vérifie si la classe passée en argument est runnable et si elle a un constructeur public content un argument de type ICore
	private boolean runnableCheck(Class<?> c) {
		try {
			return Runnable.class.isAssignableFrom(c) && c.getConstructor(ICore.class) != null;
		} catch (NoSuchMethodException e) {
			System.err.println("pas de constructeur publique avec ICore en argument");
		} catch (SecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return false;
		
	}



	//Cette fonction charge tous les Components précisés dans le fichier d"initialisation
	private List<Class<?>> getComponentsFromFile(String string) throws IOException {
		List<Class<?>> liste = new ArrayList<Class<?>>();
		for(String s : Files.readAllLines(FileSystems.getDefault().getPath(string))){
				try {
					liste.add(Class.forName(s));
				} catch (ClassNotFoundException e) {
					System.err.println(e);
				}
		}
		return liste;
	}

	

	@Override
	public String askAI(String s) {
		return this.classifierAI.genererReponse(s);
	}

	public static ICore getInstance() {
		return instance;
	}



	@Override
	//Démarre les Runnable donnés dans le fichier init
	public void launch() {
		for(Class<? extends Runnable> c : ihm){
			try {
				System.out.println("on lance un thread avec " + c);
				new Thread(c.getConstructor(ICore.class).newInstance(this)).start();
			} catch (InstantiationException | IllegalAccessException | IllegalArgumentException
					| InvocationTargetException | NoSuchMethodException | SecurityException e) {
				System.err.println("impossible d'instancier l'ihm : " + c.getName());
				e.printStackTrace();
			}
		}
		
	}

	@Override
	public String toString(){
		String r = "IA : "+ classifierAI +"\nIHM : ";
		for(Class<? extends Runnable> c : ihm){
			r += "\n" + c.getName();
		}
		return r;
	}
	
	
	
	
}
