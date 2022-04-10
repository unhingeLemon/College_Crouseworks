import javax.swing.JButton;
import javax.swing.JFrame;


public class GUI extends JFrame{
    JButton ok;

    public GUI(){
        super("Sample Title");
        setLayout(null);

        ok = new JButton("ok");

        ok.setBounds(0,0,80,40);
        add(ok);

        setSize(200,200);
        setVisible(true);
    }

    public static void main(String args[]) {
        new GUI();
    }
}