/*
Problem: Verification of implicit multilevel super-constructor resolution hierarchies.
Output:
Parent - Vehicle is created
Child of Bike - Suzuki is created
*/

class BaseVehicle {
    public BaseVehicle() {
        System.out.println("Parent - Vehicle is created");
    }
}

class Bike extends BaseVehicle {
    // Implicit default constructor invokes super() automatically
}

class Suzuki extends Bike {
    public Suzuki() {
        super();
        System.out.println("Child of Bike - Suzuki is created");
    }
}

public class MultilevelChainTrace {
    public static void main(String[] args) {
        new Suzuki();
    }
}