/*
Problem(4): Extend base classes to specialized variations while utilizing 
            the 'toString()' blueprint override for clean terminal diagnostics.
Output
Welcome to the Garage
Car : 
	Model: Tesla Model S
	Type: Electric
	Price: 85000.0
Tesla Model S : Vroom
*/

class Vehicle {
    String model;
    double price;
    
    public Vehicle(String model, double price) {
        this.model = model;
        this.price = price;
    }
    
    public String startEngine() {
        return new String(model + " :");
    }
}

class Car extends Vehicle {
    String type;
    
    public Car(String model, double price, String type) {
        super(model, price);
        this.type = type;
    }
    
    @Override
    public String toString() {
        return ("Car :" + "\n\tModel: " + model + "\n\tType: " + type + "\n\tPrice: " + price);
    }
    
    @Override
    public String startEngine() {
        return new String(model + " : Vroom");
    }
}

public class VehicleInheritanceToString {
    public static void main(String[] args) {
        System.out.println("Welcome to the Garage");
        
        Car car = new Car("Tesla Model S", 85000.0, "Electric");
        System.out.println(car);
        System.out.println(car.startEngine());
    }
}