package workWithDesign;

import javax.swing.*;
import java.awt.*;

class sscreen extends JFrame{
        JLabel text;
        Font style;

        sscreen(){
            super("My file 2");
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            setVisible(true);
            setSize(300,500);
            setLocationRelativeTo(null);

            text = new JLabel("Hiiii ... ...");
            add(text);
            style = new Font("Monaco",Font.ITALIC,40);
            text.setFont(style);
        }
}

public class file2 {
    public static void main(String[] args) {
        new sscreen();
    }
}