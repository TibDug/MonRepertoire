package ihm;
	 
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.border.*;

import core.ICore;


public class IHM_Training extends JFrame implements ActionListener {
	private ICore core;
	
    JLabel result;
    String currentClasse;
	private JButton boutonRetourMenu;
	private JButton boutonQuitter;
 
    public IHM_Training(ICore core) throws IOException {
    	this.core = core;
    	
    	this.setTitle("TechBot Training");
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setUndecorated(true);
    	this.setResizable(false);
        centerWindow(this);
        
        JPanel panelFrame = new JPanel();
 
        panelFrame.add(creerPanelGeneral());
        panelFrame.setBorder(new LineBorder(Color.black));
        
        this.add(panelFrame);
        
        this.pack();
        this.setVisible(true);
    }
    
    public JPanel creerPanelGeneral() throws IOException {
    	JPanel panelGeneral = new JPanel();
    	
    	panelGeneral.setLayout(new BoxLayout(panelGeneral, BoxLayout.PAGE_AXIS));
    	
    	panelGeneral.add(creerGestionFenetre());
    	panelGeneral.add(creerTitre());
    	panelGeneral.add(creerTexteAClassifier());
    	panelGeneral.add(creerClasses());
    	panelGeneral.add(creerConfirmation());
    	
    	panelGeneral.setAlignmentX(Component.CENTER_ALIGNMENT);
        
        panelGeneral.setBorder(BorderFactory.createEmptyBorder(10,20,20,20));
    	
		return panelGeneral;    	
    }
    
    private JPanel creerGestionFenetre() throws IOException {
    	//Code des boutons retour menu et quitter
    	JPanel panelGestionFenetre = new JPanel();
    	
    	Image imageRetour = ImageIO.read(new File("Ressources/Retour.png"));
    	Image iconeRetour = imageRetour.getScaledInstance(35, 35, Image.SCALE_DEFAULT);
    	boutonRetourMenu = new JButton(new ImageIcon(iconeRetour));
    	boutonRetourMenu.setBackground(Color.white);
    	boutonRetourMenu.setPreferredSize(new Dimension(35, 35));
    	boutonRetourMenu.setFocusable(false);
    	boutonRetourMenu.addActionListener(this);
        
        panelGestionFenetre.add(boutonRetourMenu);
		
        panelGestionFenetre.add(Box.createRigidArea(new Dimension(250,0)));  
		
        Image imageQuitter = ImageIO.read(new File("Ressources/Quitter.png"));
    	Image iconeQuitter = imageQuitter.getScaledInstance(35, 35, Image.SCALE_DEFAULT);
    	boutonQuitter = new JButton(new ImageIcon(iconeQuitter));
    	boutonQuitter.setBackground(Color.red);
    	boutonQuitter.setPreferredSize(new Dimension(35, 35));
		boutonQuitter.setFocusable(false);
		boutonQuitter.addActionListener(this);
		
		panelGestionFenetre.add(boutonQuitter);		

		panelGestionFenetre.setAlignmentX(Component.CENTER_ALIGNMENT);
        
        return panelGestionFenetre;
	}

	public JPanel creerTitre() {
    	//Code du titre
    	JPanel panelTitre = new JPanel();
        
        JLabel labelTitre = new JLabel("TechBot Training");
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
        
        JButton boutonSkip = new JButton("Skip");
        boutonSkip.setFocusable(false);
        
		panelConfirmation.add(boutonSkip);
		
		panelConfirmation.add(Box.createRigidArea(new Dimension(100,0)));  
		
		JButton boutonOk = new JButton("Ok");
		boutonOk.setFocusable(false);
		
		panelConfirmation.add(boutonOk);

        panelConfirmation.setAlignmentX(Component.CENTER_ALIGNMENT);
        panelConfirmation.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        
        return panelConfirmation;
    }
 
    public void centerWindow(Window frame) {
        Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (int) ((dimension.getWidth() - frame.getWidth()) / 3.5);
        int y = (int) ((dimension.getHeight() - frame.getHeight()) / 3.5);
        frame.setLocation(x, y);
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
    	if (e.getSource() == boutonRetourMenu) {
    		this.dispose();
			try {
				new IHM_Menu(core);
			} catch (IOException e1) {
				e1.printStackTrace();
			}
    	}
		else if (e.getSource() == boutonQuitter) {
			this.dispose();
		}
		else {
			this.dispose();
		}		
    }
 
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
				try {
					new IHM_Training(null);
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
            }
        });
    }
}