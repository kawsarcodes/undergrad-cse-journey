/*
Problem: Spring 2024 Exam Question 1 - Spatial coordinate modeling leveraging inheritance.
Output:
Point2D constructor
X = 1, y = 2
Point2D constructor
Point3D constructor
X = 5, y = 4, z = 3
*/

class Point2D {
    int x, y;

    public Point2D(int x, int y) {
        this.x = x;
        this.y = y;
        System.out.println("Point2D constructor");
    }

    public String display() {
        return "X = " + x + ", y = " + y;
    }
}

class Point3D extends Point2D {
    int z;

    public Point3D(int x, int y, int z) {
        super(x, y);
        this.z = z;
        System.out.println("Point3D constructor");
    }

    @Override
    public String display() {
        return super.display() + ", z = " + z;
    }
}

public class Spring24_Q1_Point_Dimensions {
    public static void main(String[] args) {
        Point2D p2D = new Point2D(1, 2);
        System.out.println(p2D.display());
        
        Point3D p3D = new Point3D(5, 4, 3);
        System.out.println(p3D.display());
    }
}