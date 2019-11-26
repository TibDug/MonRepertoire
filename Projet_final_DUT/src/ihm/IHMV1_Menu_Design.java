package ihm;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class IHMV1_Menu_Design extends JFrame implements ActionListener {
	
	private JButton boutonApplication = new JButton("Application");
	private JButton boutonEntrainement = new JButton("Entraînement");

	public IHMV1_Menu_Design() {
    	this.setTitle("Menu");
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    	this.setResizable(false);
        centerWindow(this);     
 
        this.add(creerPanelGeneral());
        
        this.pack();
        this.setVisible(true);
    }
	
	private JPanel creerPanelGeneral() {
		JPanel panelGeneral = new JPanel();
    	
    	panelGeneral.setLayout(new BoxLayout(panelGeneral, BoxLayout.PAGE_AXIS));
    	
    	panelGeneral.add(creerTitre());
    	panelGeneral.add(creerBoutonsSelection());
    	
    	panelGeneral.setAlignmentX(Component.CENTER_ALIGNMENT);
        
        panelGeneral.setBorder(BorderFactory.createEmptyBorder(20,50,50,50));
    	
		return panelGeneral;    	
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
        
        boutonApplication.setPreferredSize(new Dimension(200, 40));
        boutonApplication.setFont(new Font("Dialog", Font.BOLD, 25));
        boutonApplication.addActionListener(this);
        
		panelSelection.add(boutonApplication);
		
		panelSelection.add(Box.createRigidArea(new Dimension(0,25)));  

        boutonEntrainement.setPreferredSize(new Dimension(200, 40));
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
		if (e.getSource() == boutonApplication)
			new IHMV1_Design();
		else
			new IHMV1_Training_Design();
	}

    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
            	new IHMV1_Menu_Design();
            }
        });
    }
}
