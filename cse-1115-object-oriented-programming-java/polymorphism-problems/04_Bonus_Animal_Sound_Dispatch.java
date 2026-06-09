/*
Problem: Practice explicit polymorphic downcasting and upcasting via conditional runtime choice allocations.
Input 
Selection menu item option target choice: 4 (Crow selection loop)
Output
Crow goes caw-caw
The Crow is flying
*/

import java.util.Scanner;

class SystemAnimal {
    public void makeSound() {
        System.out.println("Animal makes a generic acoustic signal sound.");
    }
}

class Dog extends SystemAnimal {
    @Override
    public void makeSound() { System.out.println("Dog goes bow-wow"); }
}

class Cow extends SystemAnimal {
    @Override
    public void makeSound() { System.out.println("Cow goes moo-moo"); }
}

class Cat extends SystemAnimal {
    @Override
    public void makeSound() { System.out.println("Cat goes meow-meow"); }
}

class Crow extends SystemAnimal {
    @Override
    public void makeSound() { System.out.println("Crow goes caw-caw"); }
    public void executeFlight() { System.out.println("The Crow is flying up through air vectors."); }
}

public class BonusAnimalSoundDispatch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Select an animal: 1. Dog | 2. Cow | 3. Cat | 4. Crow");
        System.out.print("Enter choice numeric value: ");
        int choice = input.nextInt();
        
        SystemAnimal targetSelection = null;

        if (choice == 1) targetSelection = new Dog();
        else if (choice == 2) targetSelection = new Cow();
        else if (choice == 3) targetSelection = new Cat();
        else if (choice == 4) targetSelection = new Crow();

        if (targetSelection != null) {
            targetSelection.makeSound();
            
            if (targetSelection instanceof Crow) {
                Crow typedCrowInstance = (Crow) targetSelection;
                typedCrowInstance.executeFlight();
            }
        } else {
            System.out.println("Invalid type entry.");
        }
        
        input.close();
    }
}