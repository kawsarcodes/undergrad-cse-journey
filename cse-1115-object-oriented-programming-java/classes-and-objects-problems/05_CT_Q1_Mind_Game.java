/*
Problem: Class Test Question 1 - Tracing execution order across static blocks, 
         instance blocks, and constructors during dual object allocation phases.
Expected Output:
a = -1
b = 11
c = 0
d = 3

a = 0
b = 10
c = 1
d = 2
*/

class MindGame {
    int a = 0;
    int b = 2;
    static int c = 0;
    static int d = 5;

    public MindGame() {
        a = a - 1;
        b = b + 5;
        c = c + 1;
        d = d - 1;
    }

    static {
        c = c - 1;
        d = d + c;
    }

    {
        a = c + 1;
        b = b + d;
    }

    public void displayAB() {
        System.out.println("a = " + a);
        System.out.println("b = " + b);
    }

    public void displayCD() {
        System.out.println("c = " + c);
        System.out.println("d = " + d);
    }
}

public class CT_Q1_Mind_Game {
    public static void main(String[] args) {
        MindGame m1 = new MindGame();
        m1.displayAB();
        m1.displayCD();

        System.out.println();

        MindGame m2 = new MindGame();
        m2.displayAB();
        m2.displayCD();
    }
}