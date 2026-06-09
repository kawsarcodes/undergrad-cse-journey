/*
Problem: Class Test Question 4 - Complete the Car subclass definition 
         to output formatted multi-line specs and combine method strings.
Expected Output:
Welcome to the Garage
Car: 
	Model: Tesla Model S,
	Type: Electric
	Price: 85000.0

Tesla Model S : Vroom
*/

class TestVehicle {
    String model;
    double price;

    public TestVehicle(String model, double price) {
        this.model = model;
        this.price = price;
    }

    public String startEngine() {
        return new String(model + " :");
    }
}

class TestCar extends TestVehicle {
    String type;

    public TestCar(String model, double price, String type) {
        super(model, price);
        this.type = type;
    }

    @Override
    public String startEngine() {
        return super.startEngine() + " Vroom";
    }

    @Override
    public String toString() {
        return "\nCar:\n" +
               "\tModel: " + model + ",\n" +
               "\tType: " + type + "\n" +
               "\tPrice: " + price + "\n";
    }
}

public class CT_Q4_Car_Extension {
    public static void main(String[] args) {
        System.out.println("Welcome to the Garage");

        TestCar car = new TestCar("Tesla Model S", 85000.0, "Electric");
        System.out.println(car);
        System.out.println(car.startEngine());
    }
}