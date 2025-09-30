import java.awt.*;
import javax.swing.*;

public class Main {

	// **********************
	// *** Standar Values ***
	// **********************

	static Dimension dim;
	static BorderLayout layout;

	// **************
	// *** JButton ***
	// **************

	static JButton lineal;
	static JButton aditivo;
	static JButton multi_const;
	static JButton multi_congru;
	static JButton goback;

	// **************
	// *** JLabel ***
	// **************

	static JLabel selec;
	static JLabel semilla;
	static JLabel iteracion;

	// **************
	// *** JPanel ***
	// **************

	static JPanel topPanel;
	static JPanel centerPanel;
	static JPanel mainPanel;

	// **************
	// *** JFrame ***
	// **************

	static JFrame frame;

	// *********************
	// *** Main function ***
	// *********************

	public static void main(String[] args) {

	// Set System propierties

		System.setProperty("sun.java2d.uiScale", "2.0"); // Escala al 200%

	// Standar Values
		dim    = new Dimension(640, 480);
		layout = new BorderLayout();

	// JButton
		lineal       = new JButton("Lineal");
		aditivo      = new JButton("Aditivo");
		multi_const  = new JButton("Multiplicador Constante");
		multi_congru = new JButton("Multiplicador Congruencial");

		goback = new JButton("Selección del Método");

	// JLabel
		selec     = new JLabel("Selecciona el Método");
		semilla   = new JLabel("Semilla");
		iteracion = new JLabel("Iteraciones");

		selec.setAlignmentX(Component.CENTER_ALIGNMENT);
		lineal.setAlignmentX(Component.CENTER_ALIGNMENT);
		aditivo.setAlignmentX(Component.CENTER_ALIGNMENT);
		multi_const.setAlignmentX(Component.CENTER_ALIGNMENT);
		multi_congru.setAlignmentX(Component.CENTER_ALIGNMENT);

	// JPanel
		topPanel = new JPanel();
		centerPanel = new JPanel();
		mainPanel = new JPanel(new BorderLayout());

		topPanel.add(goback);

		centerPanel.setLayout(new BoxLayout(centerPanel, BoxLayout.Y_AXIS));

		centerPanel.add(selec);
		centerPanel.add(Box.createVerticalStrut(10));

		centerPanel.add(lineal);
		centerPanel.add(Box.createVerticalStrut(10));

		centerPanel.add(aditivo);
		centerPanel.add(Box.createVerticalStrut(10));

		centerPanel.add(multi_const);
		centerPanel.add(Box.createVerticalStrut(10));

		centerPanel.add(multi_congru);
		centerPanel.add(Box.createVerticalStrut(10));

		mainPanel.add(topPanel, BorderLayout.NORTH);
		mainPanel.add(centerPanel, BorderLayout.CENTER);

	// JFrame Config
		frame = new JFrame("Simulación Unidad 2");
		
		frame.setSize(dim);
		frame.setResizable(true);

		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		frame.add(mainPanel);

		frame.setVisible(true);
	}
}