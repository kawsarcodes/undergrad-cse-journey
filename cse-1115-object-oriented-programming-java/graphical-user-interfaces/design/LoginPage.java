package workWithDesign;

import javax.swing.*;

public class LoginPage {
    public static void main(String[] args) {

        JFrame frame = new JFrame("Login Page");
        frame.setSize(350, 350);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);
        frame.setLocationRelativeTo(null);

        JLabel idLabel = new JLabel("ID:");
        idLabel.setBounds(30, 30, 80, 25);
        frame.add(idLabel);

        JTextField idField = new JTextField();
        idField.setBounds(120, 30, 160, 25);
        frame.add(idField);

        JLabel passLabel = new JLabel("Password:");
        passLabel.setBounds(30, 70, 80, 25);
        frame.add(passLabel);

        JPasswordField passField