package workWithDesign;

import javax.swing.*;
import java.awt.*;

class Display extends JFrame{

    JLabel text = new JLabel("Hiiii ... ...");
    Font style = new Font("Monaco",Font.ITALIC,40);

    JLabel text1 = new JLabel("Hello ... ...");
    Font style1 = new Font("Monaco",Font.BOLD,40);

    JButton button1 ;
    Font bstyle ;

    Display(){
        super("My file 4");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        setSize(1000,501);
        setLocationRelativeTo(null);

        text.setFont(style);
        text.setBounds(150,10,300,140);
        add(text);

        text1.setFont(style1);
        text1.setBounds(150,150,300,140);
        add(text1);

        button1 = new JButton("Press me");
        button1.setBounds(150,350,300,140);
        add(button1);
        bstyle = new Font("Monaco",Font.HANGING_BASELINE,40);
        button1.setFont(bstyle);
        button1.setForeground(Color.CYAN);
        button1.setBackground(Color.magenta);

        setVisible(true);
    }
}

public class file4 {
    public static void main(String[] args) {
        new Display();
    }
}