package ButtonHandling;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class display extends JFrame implements ActionListener{

    JButton b1,b2,b3;
    Container con;

    public display(){

        setSize(300,500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        setLocationRelativeTo(null);

        con = getContentPane();

        b1 = new JButton("MAKE RED");
        add(b1);

        b2 = new JButton("MAKE YELLOW");
        add(b2);

        b3 = new JButton("MAKE BLUE");
        add(b3);

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == b1){
            con.setBackground(Color.RED);
        } else if (e.getSource() == b2) {
            con.setBackground(Color.YELLOW);
        } else if (e.getSource() == b3) {
            con.setBackground(Color.BLUE);
        }
    }
}

public class changeBackgroundColorWithDifferentApproach {
    public static void main(String[] args){
        new display();
    }
}