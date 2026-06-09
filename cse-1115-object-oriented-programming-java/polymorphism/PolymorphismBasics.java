/**
 * Topic: Polymorphism Foundations
 * Description: Demonstrates static binding (overloading) vs dynamic binding (overriding).
 */

package polymorphism;

class MathOperations {
    // Compile-time Polymorphism (Method Overloading)
    public int multiply(int a, int b) {
        return a * b;
    }

    public double multiply(double a, double b) {
        return a * b;
    }

    public int multiply(int a, int b, int c) {
        return a * b * c;
    }
}

class Animal {
    public void makeSound() {
        System.out.println("The animal makes a generic sound.");
    }
}

class Dog extends Animal {
    @Override
    public void makeSound() {
        System.out.println("The dog barks: Woof! Woof!");
    }
}

class Cat extends Animal {
    @Override
    public void makeSound() {
        System.out.println("The cat meows: Meow!");
    }
}

public class PolymorphismBasics {
    public static void main(String[] args) {
        MathOperations math = new MathOperations();
        System.out.println("Int Product: " + math.multiply(5, 4));
        System.out.println("Double Product: " + math.multiply(2.5, 4.0));
        System.out.println("Three Int Product: " + math.multiply(2, 3, 4));

        System.out.println("\n--- Testing Overriding via Dynamic Method Dispatch ---");
        Animal myDog = new Dog();
        Animal myCat = new Cat();

        myDog.makeSound();
        myCat.makeSound();
    }
}