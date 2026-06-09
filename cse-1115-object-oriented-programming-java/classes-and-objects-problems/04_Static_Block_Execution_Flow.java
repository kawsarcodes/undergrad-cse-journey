/*
Problem(4): Track class initialization sequences and shared static field mutations 
            across a multi-class inheritance tree during runtime allocation.
Output
Creating a smartphone...
Static Block of Device
Static Block of Smartphone
Smartphone platform: Android
OS: Generic OS
OS: Universal OS
Creating Laptop...
Laptop brand: Macbook
Current os: Universal OS
*/

class Device {
    static String os = "Generic OS";
    
    static {
        System.out.println("Static Block of Device");
    }
    
    public Device() {}
}

class Smartphone extends Device {
    String platform;
    
    static {
        System.out.println("Static Block of Smartphone");
    }
    
    public Smartphone(String platform) {
        super();
        this.platform = platform;
    }
    
    public void displayInfo() {
        System.out.println("Smartphone platform: " + platform);
    }
}

class Laptop extends Device {
    String brand;
    
    public Laptop(String brand) {
        super();
        this.brand = brand;
    }
    
    public void displayInfo() {
        System.out.println("Laptop brand: " + brand);
    }
}

public class StaticBlockExecutionFlow {
    public static void main(String[] args) {
        System.out.println("Creating a smartphone...");
        Smartphone s1 = new Smartphone("Android");
        s1.displayInfo();
        
        System.out.println("OS: " + Device.os);
        Device.os = "Universal OS";
        System.out.println("OS: " + s1.os);
        
        System.out.println("Creating Laptop...");
        Laptop l1 = new Laptop("Macbook");
        l1.displayInfo();
        System.out.println("Current os: " + Device.os);
    }
}