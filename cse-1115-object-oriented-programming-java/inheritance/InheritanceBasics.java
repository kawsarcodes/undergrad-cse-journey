/**
 * Topic: Inheritance Foundations (Single and Multilevel)
 * Description: Demonstrates how subclassing extends parent features and uses 'super'.
 */

package inheritance;

class Vehicle {
    protected String brand;
    protected int maxSpeed;

    public Vehicle(String brand, int maxSpeed) {
        this.brand = brand;
        this.maxSpeed = maxSpeed;
    }

    public void displaySpecifications() {
        System.out.println("Brand: " + brand + " | Max Speed: " + maxSpeed + " km/h");
    }
}

// Single Inheritance
class Car extends Vehicle {
    private int seatingCapacity;

    public Car(String brand, int maxSpeed, int seatingCapacity) {
        super(brand, maxSpeed);
        this.seatingCapacity = seatingCapacity;
    }

    public void displayCarDetails() {
        super.displaySpecifications();
        System.out.println("Seating Capacity: " + seatingCapacity);
    }
}

// Multilevel Inheritance (Vehicle -> Car -> ElectricCar)
class ElectricCar extends Car {
    private int batteryCapacityKw;

    public ElectricCar(String brand, int maxSpeed, int seatingCapacity, int batteryCapacityKw) {
        super(brand, maxSpeed, seatingCapacity);
        this.batteryCapacityKw = batteryCapacityKw;
    }

    public void displayElectricDetails() {
        super.displayCarDetails();
        System.out.println("Battery Range Metrics: " + batteryCapacityKw + " kWh");
    }
}

public class InheritanceBasics {
    public static void main(String[] args) {
        System.out.println("--- Testing Single Inheritance ---");
        Car standardCar = new Car("Toyota", 180, 5);
        standardCar.displayCarDetails();

        System.out.println("\n--- Testing Multilevel Inheritance ---");
        ElectricCar evCar = new ElectricCar("Tesla", 250, 5, 85);
        evCar.displayElectricDetails();
    }
}