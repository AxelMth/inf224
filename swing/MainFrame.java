// donne accès aux composants Swing
import javax.swing.*;
import java.awt.*;

public class MainFrame extends JFrame {

  private static final long serialVersionUID = 1L;

  public JTextArea area = new JTextArea();
  public Client client = null;


  public MainFrame(String titre, Client client) {
    super(titre);
    this.client = client;

    MenuBar menuBar = new MenuBar(this);
    setJMenuBar(menuBar);

    add(new JScrollPane(area), BorderLayout.SOUTH);
    add(menuBar, BorderLayout.NORTH);


    //Options de la fenetre
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    pack();
    setVisible(true);
  }

  class MenuBar extends JMenuBar {

    private static final long serialVersionUID = 2L;
    private MainFrame frame = null;
    private JMenu menu = null;
    private JMenu exit = null;


    public MenuBar(MainFrame frame) {
      super();
      this.frame = frame;

      menu = new JMenu("Menu");
      exit = new JMenu("Exit");

      add(menu);
      add(exit);
    }
  }
  }
