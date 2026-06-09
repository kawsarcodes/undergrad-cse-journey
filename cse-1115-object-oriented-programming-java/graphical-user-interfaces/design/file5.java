package workWithDesign;

import javax.swing.*;

public class file5 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Two TextFields");
        frame.setSize(300, 150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        JLabel label1 = new JLabel("num1:");
        label1.setBounds(20, 20, 50, 25);
        frame.add(label1);

        JTextField textField1 = new JTextField();
        textField1.setBounds(80, 20, 150, 25);
        frame.add(textField1);

        JLabel label2 = new JLabel("num2:");
        label2.setBounds(20, 60, 50, 25);
        frame.add(label2);

        JTextField textField2 = new JTextField();
        textField2.setBounds(80, 60, 150, 25);
        frame.add(textField2);

        frame.setVisible(true);
    }
}