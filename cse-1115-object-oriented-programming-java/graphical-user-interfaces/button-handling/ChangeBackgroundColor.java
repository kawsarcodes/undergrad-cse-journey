package ButtonHandling;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class color extends JFrame {

    JButton b1,b2,b3;
    Container con;

    public color(){

        setSize(300,500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        setLocationRelativeTo(null);

        con = getContentPane();

        b1 = new JButton("MAKE RED");
        add(b1);
        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                con.setBackground(Color.RED);
            }
        });

        b2 = new JButton("MAKE YELLOW");
        add(b2);
        b2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                con.setBackground(Color.YELLOW);
            }
        });

        b3 = new JButton("MAKE BLUE");
        add(b3);
        b3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                con.setBackground(Color.BLUE);
            }
        });

        setVisible(true);
    }
}

public class ChangeBackgroundColor {
    public static void main(String[] args){
        new color();
    }
}