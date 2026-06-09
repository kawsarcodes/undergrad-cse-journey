/*
Problem: Calculate areas and perimeters of various fields based on dynamic runtime dimensions.
Input 
Field 1: Length = 10, Width = 5
Field 2: Length = 20, Width = 10
Output
Area: 50.0, Perimeter: 30.0
Area: 200.0, Perimeter: 60.0
*/

import java.util.Scanner;

class Field {
    private double length;
    private double width;

    public Field(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public double calculateArea() {
        return length * width;
    }

    public double calculatePerimeter() {
        return 2 * (length + width);
    }

    public void displaySpecifications() {
        System.out.println("----------------------------------------------");
        System.out.println("Area: " + calculateArea() + " | Perimeter: " + calculatePerimeter());
        System.out.println("----------------------------------------------");
    }
}

public class FieldDimensionsCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter length of first field: ");
        double length1 = scanner.nextDouble();
        System.out.print("Enter width of first field: ");
        double width1 = scanner.nextDouble();
        
        System.out.print("Enter length of second field: ");
        double length2 = scanner.nextDouble();
        System.out.print("Enter width of second field: ");
        double width2 = scanner.nextDouble();

        Field field1 = new Field(length1, width1);
        Field field2 = new Field(length2, width2);

        field1.displaySpecifications();
        field2.displaySpecifications();
        
        scanner.close();
    }
}