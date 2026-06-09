package ButtonHandling;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class addition extends JFrame{

    JLabel num1l, num2l, sumll;
    JTextField num1tf,num2tf,sumtf;
    JButton sumb;

    addition(){
        super("Addition Calculator");
        setLayout(null);
        setSize(400,300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        num1l = new JLabel("Number 1: ");
        num1l.setBounds(30,30,80,25);
        add(num1l);

        num1tf = new JTextField("");
        num1tf.setBounds(120,30,160,25);
        add(num1tf);

        num2l = new JLabel("Number 2: ");
        num2l.setBounds(30,70,80,25);
        add(num2l);

        num2tf = new JTextField("");
        num2tf.setBounds(120,70,160,25);
        add(num2tf);

        sumll = new JLabel("Sum: ");
        sumll.setBounds(30,110,80,25);
        add(sumll);

        sumtf = new JTextField("");
        sumtf.setBounds(120,110,160,25);
        add(sumtf);

        sumb = new JButton("Sum");
        sumb.setBounds(150,150,80,25);
        add(sumb);
        sumb.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int x = Integer.parseInt(num1tf.getText());
                int y = Integer.parseInt(num2tf.getText());

                int z = x + y;

                sumtf.setText(z + "");
            }
        });

        JButton resetb = new JButton("Reset");
        resetb.setBounds(150,190,80,25);
        add(resetb);
        resetb.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                num1tf.setText("");
                num2tf.setText("");
                sumtf.setText("");
            }
        });

        setVisible(true);
    }
}

public class AdditionCalculator {
    public static void main(String[] args){
        new addition();
    }
}