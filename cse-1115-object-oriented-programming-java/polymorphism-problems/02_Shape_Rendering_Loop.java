/*
Problem(2): Implement a graphics layout renderer that calculates surface areas 
            for completely different shapes using a single uniform array loop.
Input 
Array containing: Circle(radius = 5), Rectangle(width = 4, height = 6)
Output
Rendered Item Surface Area: 78.53981633974483
Rendered Item Surface Area: 24.0
*/

class Shape {
    public double getArea() {
        return 0.0;
    }
}

class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double getArea() {
        return width * height;
    }
}

public class ShapeRenderingLoop {
    public static void main(String[] args) {
        Shape[] geometricCanvas = {
            new Circle(5.0),
            new Rectangle(4.0, 6.0)
        };

        for (Shape canvasItem : geometricCanvas) {
            System.out.println("Rendered Item Surface Area: " + canvasItem.getArea());
        }
    }
}
