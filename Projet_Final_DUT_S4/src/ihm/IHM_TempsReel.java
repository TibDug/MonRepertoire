package ihm;

import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;

import core.ICore;

 
public class IHM_TempsReel extends JFrame implements ActionListener {
	private ICore core;
	
	private JTextField zoneDeSaisie;
    private JTextArea texteUser;
    private JTextArea texteIA;
    private final static String newline = "\n";
    private String reponse = null;
    
	private JButton boutonRetourMenu;
	private JButton boutonQuitter;
 
    public IHM_TempsReel(ICore core) throws IOException {
    	this.core = core;
    	
    	this.setTitle("TechBot Temps Reel");
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
    	panelGeneral.add(creerTexte());
    	panelGeneral.add(creerZoneDeTexte());
    	
    	panelGeneral.setAlignmentX(Component.CENTER_ALIGNMENT);
        
        panelGeneral.setBorder(BorderFactory.createEmptyBorder(10,0,10,0));
    	
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
		
        panelGestionFenetre.add(Box.createRigidArea(new Dimension(600,0)));  
		
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
    	
    	JLabel Titre = new JLabel("Chat TechBot");
        Titre.setFont(new Font("Dialog", Font.BOLD, 25));
        Titre.setAlignmentX(Component.CENTER_ALIGNMENT);
        
        GridBagConstraints TitreGBC = new GridBagConstraints();
        
        panelTitre.setBorder(BorderFactory.createEmptyBorder(0,10,20,10));
        
        panelTitre.add(Titre, TitreGBC);
        
		return panelTitre;    	
    }
    
    public JPanel creerTexte(){ 
    	//Code permettant de contenir les différentes zones de texte
        JPanel panelTexte = new JPanel();
        
        panelTexte.add(creerTexteUser());
        panelTexte.add(creerTexteIA());
        
		return panelTexte;
    }
    
    public JPanel creerTexteUser(){ 
    	//Code permettant d'afficher le texte entré
        JPanel panelTexteUser = new JPanel();
        
        TitledBorder borderTexteUser = new TitledBorder("Votre texte");
        borderTexteUser.setTitleJustification(TitledBorder.CENTER);
        borderTexteUser.setTitlePosition(TitledBorder.TOP);
        
        panelTexteUser.setBorder(borderTexteUser);
        
        texteUser = new JTextArea(15, 40);
        texteUser.setEditable(false);
        texteUser.setLineWrap(true);
        JScrollPane texteUserSP = new JScrollPane(texteUser);
        GridBagConstraints texteUserGBC = new GridBagConstraints();
        
        panelTexteUser.add(texteUserSP, texteUserGBC);
        
		return panelTexteUser;
    }
    
    public JPanel creerTexteIA(){
    	//Code permettant d'afficher le texte de l'IA
        JPanel panelTexteIA = new JPanel();
        
        TitledBorder borderTexteIA = new TitledBorder("Réponse de l'IA");
        borderTexteIA.setTitleJustification(TitledBorder.CENTER);
        borderTexteIA.setTitlePosition(TitledBorder.TOP);
        
        panelTexteIA.setBorder(borderTexteIA);
        
        texteIA = new JTextArea(15, 40);
        texteIA.setEditable(false);
        texteIA.setLineWrap(true);
        JScrollPane texteIASP = new JScrollPane(texteIA);

        GridBagConstraints texteIAGBC = new GridBagConstraints();
        
        panelTexteIA.add(texteIASP, texteIAGBC);
        
		return panelTexteIA;    
    }
    
    public JPanel creerZoneDeTexte(){
    	//Code de la zone de saisie
        JPanel panelZoneDeSaisie = new JPanel();
        
        TitledBorder borderZoneDeSaisie = new TitledBorder("Tapez ici votre texte");
        borderZoneDeSaisie.setTitleJustification(TitledBorder.CENTER);
        borderZoneDeSaisie.setTitlePosition(TitledBorder.TOP);   
        panelZoneDeSaisie.setBorder(borderZoneDeSaisie);
         
        zoneDeSaisie = new JTextField(82);
        zoneDeSaisie.addActionListener(this);
 
        GridBagConstraints zoneDeSaisieGBC = new GridBagConstraints();
        
        panelZoneDeSaisie.add(zoneDeSaisie, zoneDeSaisieGBC);
        
		return panelZoneDeSaisie;  
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
			texteUser.append(saisie() + newline);
	        zoneDeSaisie.selectAll();        
	        texteUser.setCaretPosition(texteUser.getDocument().getLength());
	       
	        reponse(saisie());
	        texteIA.append(reponse + newline);
	        texteIA.setCaretPosition(texteIA.getDocument().getLength());
	        
		}
    }

	public String saisie() {		
		return zoneDeSaisie.getText();
	}

	public void reponse(String texteReponse) {
		this.reponse = core.askAI(texteReponse);
	}
 
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
            	try {
					new IHM_TempsReel(null);
				} catch (IOException e) {
					e.printStackTrace();
				}
            }
        });
    }
}