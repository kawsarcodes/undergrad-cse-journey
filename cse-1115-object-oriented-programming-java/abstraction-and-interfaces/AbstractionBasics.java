/**
 * Topic: Abstract Classes vs Interfaces
 * Description: Demonstrates partial abstraction (Abstract Class) vs 100% abstract contracts (Interface).
 */

package abstraction;

// Abstract Class: Can have state (fields) and concrete methods
abstract class Appliance {
    protected boolean isPoweredOn;
    protected String modelName;

    public Appliance(String modelName) {
        this.modelName = modelName;
        this.isPoweredOn = false;
    }

    public void turnOn() {
        isPoweredOn = true;
        System.out.println(modelName + " is now powered operational.");
    }

    // Abstract method: No body, forcing children to implement distinct logic
    public abstract void performCoreFunction();
}

// Interface: Pure contract definition (Before Java 8, 100% abstract)
interface SmartConnectable {
    void connectToWifi(); // Abstract method public by default
}

// Concrete Class inheriting structure and implementing functional contract interfaces
class SmartWashingMachine extends Appliance implements SmartConnectable {
    
    public SmartWashingMachine(String modelName) {
        super(modelName);
    }

    @Override
    public void performCoreFunction() {
        System.out.println("Running hydro-spin wash cycles.");
    }

    @Override
    public void connectToWifi() {
        System.out.println(modelName + " linked to home automation hub stream successfully.");
    }
}

public class AbstractionBasics {
    public static void main(String[] args) {
        // Appliance machine = new Appliance("Generic"); // Error: Cannot instantiate abstract type directly
        
        SmartWashingMachine washer = new SmartWashingMachine("Samsung EcoBubble");
        washer.turnOn();
        washer.connectToWifi();
        washer.performCoreFunction();
    }
}