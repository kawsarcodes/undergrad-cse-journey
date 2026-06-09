/*
Problem(3): Demonstrate the difference between a shallow copy reference leak and 
            a deep copy memory isolation block using custom Address objects.
Input 
Original User: Name: John, City: New York
Shallow Copy Modification: City -> Los Angeles
Deep Copy Modification: City -> Chicago
Output
--- Testing Shallow Copy Leakage ---
Original City after shallow clone mutation: Los Angeles
Shallow City: Los Angeles

--- Testing Deep Copy Memory Isolation ---
Original City after deep clone mutation: Los Angeles
Deep City: Chicago
*/

class Address {
    public String city;

    public Address(String city) {
        this.city = city;
    }
}

class Customer {
    public String name;
    public Address address;

    public Customer(String name, Address address) {
        this.name = name;
        this.address = address;
    }

    // Deep Copy Constructor Implementation
    public Customer(Customer other) {
        this.name = other.name;
        this.address = new Address(other.address.city);
    }
}

public class DeepVsShallowCopy {
    public static void main(String[] args) {
        Address sharedHome = new Address("New York");
        Customer customerOriginal = new Customer("John", sharedHome);

        // 1. Triggering a Shallow Copy (Copying references only)
        Customer customerShallow = new Customer(customerOriginal.name, customerOriginal.address);
        
        System.out.println("--- Testing Shallow Copy Leakage ---");
        customerShallow.address.city = "Los Angeles";
        System.out.println("Original City after shallow clone mutation: " + customerOriginal.address.city);
        System.out.println("Shallow City: " + customerShallow.address.city);

        // 2. Triggering a Deep Copy (Isolating memory footprints)
        Customer customerDeep = new Customer(customerOriginal);
        
        System.out.println("\n--- Testing Deep Copy Memory Isolation ---");
        customerDeep.address.city = "Chicago";
        System.out.println("Original City after deep clone mutation: " + customerOriginal.address.city);
        System.out.println("Deep City: " + customerDeep.address.city);
    }
}