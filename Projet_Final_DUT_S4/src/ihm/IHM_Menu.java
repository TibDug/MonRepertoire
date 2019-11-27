package ihm;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.LineBorder;

import core.ICore;

public class IHM_Menu extends JFrame implements ActionListener {
	private ICore core;
	
	private JButton boutonApplication; 
	private JButton boutonEntrainement;
	private JButton boutonQuitter;

	public IHM_Menu(ICore core) throws IOException {
		this.core = core;
		
    	this.setTitle("TechBot Menu");
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
	
	private JPanel creerPanelGeneral() throws IOException {
		JPanel panelGeneral = new JPanel();
    	
    	panelGeneral.setLayout(new BoxLayout(panelGeneral, BoxLayout.PAGE_AXIS));
    	
    	panelGeneral.add(creerGestionFenetre());
    	panelGeneral.add(creerTitre());
    	panelGeneral.add(creerBoutonsSelection());
    	
    	panelGeneral.setAlignmentX(Component.CENTER_ALIGNMENT);
        
        panelGeneral.setBorder(BorderFactory.createEmptyBorder(10,35,35,35));
    	
		return panelGeneral;    	
	}
	
	private JPanel creerGestionFenetre() throws IOException {
    	//Code des boutons retour menu et quitter
    	JPanel panelGestionFenetre = new JPanel();
		
        panelGestionFenetre.add(Box.createRigidArea(new Dimension(180,0)));  
		
        Image imageQuitter = ImageIO.read(new File("Ressources/Quitter.png"));
    	Image iconeQuitter = imageQuitter.getScaledInstance(35, 35, Image.SCALE_DEFAULT);
    	boutonQuitter = new JButton(new ImageIcon(iconeQuitter));
    	boutonQuitter.setBackground(Color.red);
    	boutonQuitter.setPreferredSize(new Dimension(35, 35));
		boutonQuitter.setFocusable(false);
		boutonQuitter.addActionListener(this);
		
		panelGestionFenetre.add(boutonQuitter);		
        
        return panelGestionFenetre;
	}

	private JPanel creerTitre() {
		JPanel panelTitre = new JPanel();
        
        JLabel labelTitre = new JLabel("MENU");
        labelTitre.setFont(new Font("Dialog", Font.BOLD, 25));
        labelTitre.setAlignmentX(Component.CENTER_ALIGNMENT);
        labelTitre.setBorder(BorderFactory.createEmptyBorder(10,10,30,10));
        
        panelTitre.add(labelTitre);
        
        return panelTitre;
	}
	
	private JPanel creerBoutonsSelection() {
        JPanel panelSelection = new JPanel(new GridLayout(3,1));
        
        boutonApplication = new JButton("Application");
        boutonApplication.setPreferredSize(new Dimension(200, 40));
        boutonApplication.setFocusable(false);
        boutonApplication.setFont(new Font("Dialog", Font.BOLD, 25));
        boutonApplication.addActionListener(this);
        
		panelSelection.add(boutonApplication);
		
		panelSelection.add(Box.createRigidArea(new Dimension(0,25)));  

		boutonEntrainement = new JButton("Entraînement");
        boutonEntrainement.setPreferredSize(new Dimension(200, 40));
        boutonEntrainement.setFocusable(false);
		boutonEntrainement.setFont(new Font("Dialog", Font.BOLD, 25));
        boutonEntrainement.addActionListener(this);
		
		panelSelection.add(boutonEntrainement);		

        panelSelection.setAlignmentX(Component.CENTER_ALIGNMENT);
        panelSelection.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        
        return panelSelection;
	}

	public void centerWindow(Window frame) {
        Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (int) ((dimension.getWidth() - frame.getWidth()) / 3.5);
        int y = (int) ((dimension.getHeight() - frame.getHeight()) / 3.5);
        frame.setLocation(x, y);
    }
	
	@Override
	public void actionPerformed(ActionEvent e) {
		this.dispose();
		if (e.getSource() == boutonApplication) {
			try {
				new IHM_TempsReel(core);
			} catch (IOException e2) {
				e2.printStackTrace();
			}
		}
		else if (e.getSource() == boutonEntrainement) {
			try {
				new IHM_Training(core);
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		}
		else {
			this.dispose();
		}
	}

    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
            	try {
					new IHM_Menu(null);
				} catch (IOException e) {
					e.printStackTrace();
				}
            }
        });
    }
}