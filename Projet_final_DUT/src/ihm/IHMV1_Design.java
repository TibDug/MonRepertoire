package ihm;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.TitledBorder;

import core.InterfaceIHM;
 
public class IHMV1_Design extends JFrame implements ActionListener, InterfaceIHM {
	
	private JTextField zoneDeSaisie;
    private JTextArea texteUser;
    private JTextArea texteIA;
    private final static String newline = "\n";
    private String reponse = null;
 
    public IHMV1_Design() {
    	this.setTitle("IA Support");
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setResizable(false);
        centerWindow(this);       

        this.add(creerTitre(), BorderLayout.PAGE_START);
        this.add(creerZoneDeTexte(), BorderLayout.PAGE_END); 
        this.add(creerTexteUser(), BorderLayout.LINE_START);
        this.add(creerTexteIA(), BorderLayout.LINE_END);        
        
        this.pack();
        this.setVisible(true);
    }
    
    public JPanel creerTitre() {
    	//Code du titre
        JPanel panelTitre = new JPanel();
    	
    	JLabel Titre = new JLabel("INTELLIGENCE ARTIFICIELLE SUPPORT");
        Titre.setFont(new Font("Dialog", Font.BOLD, 25));
        Titre.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        Titre.setAlignmentX(Component.CENTER_ALIGNMENT);
        
        GridBagConstraints TitreGBC = new GridBagConstraints();
        
        panelTitre.add(Titre, TitreGBC);
        
		return panelTitre;    	
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
    
    public void centerWindow(Window frame) {
        Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (int) ((dimension.getWidth() - frame.getWidth()) / 3.5);
        int y = (int) ((dimension.getHeight() - frame.getHeight()) / 3.5);
        frame.setLocation(x, y);
    }
 
    @Override
    public void actionPerformed(ActionEvent evt) {
    	texteUser.append(saisie() + newline);
        zoneDeSaisie.selectAll();        
        texteUser.setCaretPosition(texteUser.getDocument().getLength());
       
        texteIA.append(reponse + newline);
        texteIA.setCaretPosition(texteUser.getDocument().getLength());
    }
    
    @Override
	public String saisie() {		
		return zoneDeSaisie.getText();
	}

	@Override
	public void affichage(String param) {
		this.reponse = param;
	}
 
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
            	new IHMV1_Design();
            }
        });
    }
}
