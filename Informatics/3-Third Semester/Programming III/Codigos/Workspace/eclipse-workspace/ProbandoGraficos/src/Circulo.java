
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Circulo extends JFrame {
    public static void main(String[] args) {
        new Circulo();
    }

    public Circulo() {
        this.setTitle("Círculo");
        this.setSize(200, 200);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        this.setVisible(true);
    }

    public void paint(Graphics g) {
        g.setColor(Color.MAGENTA);
        g.fillOval(50, 50, 100, 100);
    }
}
