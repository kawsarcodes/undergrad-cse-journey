/*
Problem: Overloaded explicit parameter routing via structural 'super(...)' initialization gates.
Output:
Parent - Vehicle GsrX is created 454.
Child of Vehicle - Bike is created
Parent - Vehicle R15M is created 999.
Child of Vehicle - 56 Bike is creaded
*/

class VehicleTemplate {
    public VehicleTemplate() {
        System.out.println("Parent - Vehicle is created.");
    }

    public VehicleTemplate(String name, int n) {
        System.out.printf("Parent - Vehicle %s is created %d.\n", name, n);
    }
}

class SportBike extends VehicleTemplate {
    public SportBike() {
        super("GsrX", 454);
        System.out.println("Child of Vehicle - Bike is created");
    }

    public SportBike(int p) {
        super("R15M", 999);
        System.out.printf("Child of Vehicle - %d Bike is creaded\n", p);
    }
}

public class SuperConstructorChaining {
    public static void main(String[] args) {
        new SportBike();
        new SportBike(56);
    }
}