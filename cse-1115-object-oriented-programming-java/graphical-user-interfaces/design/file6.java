package workWithDesign;

import javax.swing.*;

public class file6 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Subscription Check");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        JLabel questionLabel = new JLabel("Subscribed to NovoNex?");
        questionLabel.setBounds(50, 30, 200, 25);
        frame.add(questionLabel);

        JCheckBox yesCheckBox = new JCheckBox("Yes");
        yesCheckBox.setBounds(50, 60, 100, 25);
        frame.add(yesCheckBox);

        JCheckBox noCheckBox = new JCheckBox("No");
        noCheckBox.setBounds(150, 60, 100, 25);
        frame.add(noCheckBox);

        frame.setVisible(true);
    }
}