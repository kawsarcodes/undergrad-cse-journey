package ButtonHandling;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class A implements ActionListener{
    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println("Save Button Clicked");
    }
}

public class file1 {
    public static void main(String[] args){

        JFrame frame = new JFrame("file: 1");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500,500);
        frame.setLayout(new FlowLayout());
        frame.setLocationRelativeTo(null);

        JButton b1 = new JButton("Print");
        b1.setSize(30,50);
        frame.add(b1);
        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Print Button Clicked");
            }
        });

        JButton b2 = new JButton("Save");
        b2.setSize(30,50);
        b2.addActionListener(new A());
        frame.add(b2);

        frame.setVisible(true);
    }
}