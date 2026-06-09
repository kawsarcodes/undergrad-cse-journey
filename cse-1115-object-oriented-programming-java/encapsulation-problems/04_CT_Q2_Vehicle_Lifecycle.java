/*
Problem: Class Test Question 2 - Tracing order of multiple static blocks, 
         anonymous instance blocks, and constructor variations.
Expected Output:
Initializing Vehicle class...
Making sure of initialization...
Initializing an instance of the Vehicle class...
Creating a default vehicle.
The vehicle emits a honking sound.
model=null brand=Unknown
Initializing an instance of the Vehicle class...
Creating a customized vehicle of brand: Ford and model: F-150
The vehicle emits a custom honking sound: Loud horn sound
model=F-150 brand=Ford
*/

class Vehicle {
    private String brand;
    private String model;

    static {
        System.out.println("Initializing Vehicle class...");
    }

    {
        System.out.println("Initializing an instance of the Vehicle class...");
    }

    public Vehicle() {
        System.out.println("Creating a default vehicle.");
        brand = "Unknown";
    }

    public Vehicle(String brand, String model) {
        System.out.println("Creating a customized vehicle of brand: " + brand + " and model: " + model);
        this.brand = brand;
        this.model = model;
    }

    public void honk() {
        System.out.println("The vehicle emits a honking sound.");
    }

    public void honk(String sound) {
        System.out.println("The vehicle emits a custom honking sound: " + sound);
    }

    static {
        System.out.println("Making sure of initialization...");
    }

    public void info() {
        System.out.println("model=" + model + " brand=" + brand);
    }
}

public class CT_Q2_Vehicle_Lifecycle {
    public static void main(String[] args) {
        Vehicle defaultVehicle = new Vehicle();
        defaultVehicle.honk();
        defaultVehicle.info();

        System.out.println();

        Vehicle truck = new Vehicle("Ford", "F-150");
        truck.honk("Loud horn sound");
        truck.info();
    }
}