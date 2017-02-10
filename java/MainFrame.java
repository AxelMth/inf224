// donne accès aux composants Swing
import javax.swing.*;
import java.awt.event.*;

public class MainFrame extends JFrame implements ActionListener {

   JButton doIt, close;
   JLabel label = new JLabel();

   public static void main(String argv[ ]) {
     new MainFrame();
   }

   public MainFrame() {
     add(doIt = new JButton ("Do It"));
     add(close = new JButton ("Close"));
     doIt.addActionListener(this);
     //close.addActionListener(this);
     setDefaultCloseOperation(EXIT_ON_CLOSE);
     pack();
     setVisible(true);
   }

   public void actionPerformed(ActionEvent e) {
     if (e.getSource() == doIt)
      label.setText("Done!");
     else if (e.getSource() == close)
      System.exit(0);
   }

 }
