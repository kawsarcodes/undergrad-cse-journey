package ButtonHandling.file;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class inputUsingFile {
    public static void main(String[] args) throws IOException {
        File file = new File("src/ButtonHandling/file/show.txt");
        FileWriter fw = new FileWriter(file,true);

        JFrame frame = new JFrame("Input Box");
        JTextField tf1;
        JButton b1;
        frame.setLayout(new FlowLayout());
        frame.setSize(300,500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);

        tf1 = new JTextField();
        tf1.setPreferredSize(new Dimension(250,50));
        frame.add(tf1);

        b1 = new JButton("Submit");
        b1.setPreferredSize(new Dimension(100,25));
        frame.add(b1);
        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String x = tf1.getText();
                try {
                    fw.write(x + "\n");
                    fw.flush();
                    System.out.println("Added Successfully");
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            }
        });

        frame.setVisible(true);
    }
}