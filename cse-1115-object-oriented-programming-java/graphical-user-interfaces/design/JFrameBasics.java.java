package workWithDesign;

import javax.swing.*;

public class file1 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Test Project");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setSize(300,500);
        frame.setLocationRelativeTo(null);

        JButton b1 = new JButton("Click me");
        frame.add(b1);
    }
}