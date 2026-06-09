/*
Problem(2): Verify and track the exact sequence of initialization calls down 
            a deep class tree when an object is instantiated.
Input 
Instantiate a SmartAppliance object
Output
[System initialization log] Base Device default constructor executed.
[System initialization log] Appliance specific constructor executed.
[System initialization log] SmartAppliance specialized constructor executed.
*/

class BaseDevice {
    public BaseDevice() {
        System.out.println("[System initialization log] Base Device default constructor executed.");
    }
}

class HouseholdAppliance extends BaseDevice {
    public HouseholdAppliance() {
        super();
        System.out.println("[System initialization log] Appliance specific constructor executed.");
    }
}

class SmartAppliance extends HouseholdAppliance {
    public SmartAppliance() {
        super();
        System.out.println("[System initialization log] SmartAppliance specialized constructor executed.");
    }
}

public class ConstructorExecutionOrder {
    public static void main(String[] args) {
        new SmartAppliance();
    }
}