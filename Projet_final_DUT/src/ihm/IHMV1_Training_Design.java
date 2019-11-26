package ihm;
	 
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import java.util.*;


public class IHMV1_Training_Design extends JFrame implements ActionListener {
    JLabel result;
    String currentClasse;
 
    public IHMV1_Training_Design() {
    	this.setTitle("Entraînement IA");
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    	this.setResizable(false);
        centerWindow(this);     
 
        this.add(creerPanelGeneral());
        
        this.pack();
        this.setVisible(true);
    }
    
    public JPanel creerPanelGeneral() {
    	JPanel panelGeneral = new JPanel();
    	
    	panelGeneral.setLayout(new BoxLayout(panelGeneral, BoxLayout.PAGE_AXIS));
    	
    	panelGeneral.add(creerTitre());
    	panelGeneral.add(creerTexteAClassifier());
    	panelGeneral.add(creerClasses());
    	panelGeneral.add(creerConfirmation());
    	panelGeneral.add(creerRetourMenu());
    	
    	panelGeneral.setAlignmentX(Component.CENTER_ALIGNMENT);
        
        panelGeneral.setBorder(BorderFactory.createEmptyBorder(20,20,20,20));
    	
		return panelGeneral;    	
    }
    
    public JPanel creerTitre() {
    	//Code du titre
    	JPanel panelTitre = new JPanel();
        
        JLabel labelTitre = new JLabel("ENTRAINEMENT DE L'IA");
        labelTitre.setFont(new Font("Dialog", Font.BOLD, 25));
        labelTitre.setAlignmentX(Component.CENTER_ALIGNMENT);
        labelTitre.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        
        panelTitre.add(labelTitre);
        
        return panelTitre;
    }
    
    public JPanel creerTexteAClassifier() {
    	//Code de la phrase d'instruction et de la zone de texte contenant le texte à classifier
    	JPanel panelTexte = new JPanel();
    	
    	panelTexte.setLayout(new BoxLayout(panelTexte, BoxLayout.PAGE_AXIS));
        
        JLabel labelTexte = new JLabel("Voici le texte à classifier :");
        labelTexte.setAlignmentX(Component.CENTER_ALIGNMENT);
        labelTexte.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        
        panelTexte.add(labelTexte);
        
        JTextArea texte = new JTextArea(12, 40);
        texte.setEditable(false);
        texte.setLineWrap(true);
        texte.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        JScrollPane scrollPane = new JScrollPane(texte);
                
        panelTexte.add(scrollPane, texte);
        
        return panelTexte;
    }
    
    public JPanel creerClasses() {
    	//Code de la phrase d'instruction et de la comboBox contenant les classes existantes dans les données
    	JPanel panelClasses = new JPanel();
    	
    	panelClasses.setLayout(new BoxLayout(panelClasses, BoxLayout.PAGE_AXIS));
        
        JLabel labelClasses = new JLabel("Sélectionnez la classe correspondante");
        labelClasses.setAlignmentX(Component.CENTER_ALIGNMENT);
        labelClasses.setBorder(BorderFactory.createEmptyBorder(20,10,10,10));
        
        panelClasses.add(labelClasses); 
        
        String[] classes = {
                 "Nourriture",
                 "Jeux",
                 "Animaux",
                 "Films",
                 "Sports",
                 "Etudes",
                 "Travail",
                 "Bizarre",
                 "Monuments"
        }; 
        currentClasse = classes[0]; 
        JComboBox listeClasses = new JComboBox(classes);
        listeClasses.setEditable(false);
        //listeClasses.addActionListener(this);
        listeClasses.setAlignmentX(Component.CENTER_ALIGNMENT);        
        listeClasses.setBorder(BorderFactory.createEmptyBorder(0,10,10,10));
        
        panelClasses.add(listeClasses);
        
        return panelClasses;
    }
    
    public JPanel creerConfirmation() {
    	//Code des boutons Ok et Skip
        JPanel panelConfirmation = new JPanel();
        
        panelConfirmation.setLayout(new FlowLayout());        
        JButton boutonSkip = new JButton("Skip");
        
		panelConfirmation.add(boutonSkip);
		
		panelConfirmation.add(Box.createRigidArea(new Dimension(100,0)));  
		
		JButton boutonOk = new JButton("Ok");
		
		panelConfirmation.add(boutonOk);		

        panelConfirmation.setAlignmentX(Component.CENTER_ALIGNMENT);
        panelConfirmation.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        
        return panelConfirmation;
    }
    
    public JPanel creerRetourMenu() {
    	//Code du bouton Menu
        JPanel panelRetourMenu = new JPanel();
               
        JButton boutonMenu = new JButton("Retour MENU");
        
        panelRetourMenu.add(boutonMenu);		

        panelRetourMenu.setAlignmentX(Component.CENTER_ALIGNMENT);
        panelRetourMenu.setBorder(BorderFactory.createEmptyBorder(30,10,10,10));
        
        return panelRetourMenu;
    }
 
    public void centerWindow(Window frame) {
        Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (int) ((dimension.getWidth() - frame.getWidth()) / 3.5);
        int y = (int) ((dimension.getHeight() - frame.getHeight()) / 3.5);
        frame.setLocation(x, y);
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
    	// /!\ A REMPLIR /!\
    }
 
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
            	new IHMV1_Training_Design();
            }
        });
    }
}