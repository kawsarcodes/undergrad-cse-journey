package workWithDesign;

import javax.swing.*;
import java.awt.*;

class ScReen extends JFrame{

    JLabel text ;
    Font style ;

    JLabel text1 ;
    Font style1 ;

    ScReen(){
        super("My file 3");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300,501);
        setLocationRelativeTo(null);

        setLayout(new FlowLayout());

        text = new JLabel("Hiiii ... ...");
        style = new Font("Monaco",Font.ITALIC,40);
        text.setFont(style);
        add(text);

        text1 = new JLabel("Hello ... ...");
        style1 = new Font("Monaco",Font.BOLD,40);
        text1.setFont(style1);
        add(text1);

        setVisible(true);
    }
}

public class file3 {
    public static void main(String[] args) {
        new ScReen();
    }
}