/**
 * Topic: Complete Classes and Objects Foundations
 * Description: Demonstrates memory allocation rules, constructor overloading, 
 * copy constructors, static vs instance scope, and the 'this' keyword.
 */

class Student {
    // Instance fields (Allocated on Heap memory per object)
    private int id;
    private String name;
    private double gpa;

    // Static/Class field (Allocated once in Method Area, shared across all objects)
    public static String universityName = "State Engineering University";
    public static int totalStudentsEnrolled = 0;

    // 1. Default/No-Argument Constructor
    public Student() {
        this.id = 0;
        this.name = "Unknown";
        this.gpa = 0.0;
        totalStudentsEnrolled++;
    }

    // 2. Parameterized Constructor (Using 'this' to resolve variable shadowing)
    public Student(int id, String name, double gpa) {
        this.id = id;
        this.name = name;
        this.gpa = gpa;
        totalStudentsEnrolled++;
    }

    // 3. Copy Constructor (Demonstrates explicit reference duplication)
    public Student(Student otherStudent) {
        this.id = otherStudent.id;
        this.name = otherStudent.name;
        this.gpa = otherStudent.gpa;
        totalStudentsEnrolled++;
    }

    // Instance method
    public void displayProfile() {
        System.out.println("[" + id + "] " + name + " | GPA: " + gpa + " | Campus: " + universityName);
    }

    // Static method (Can only access static variables directly)
    public static void displayEnrollmentMetrics() {
        System.out.println("Global Analytics -> Total Active Enrolled Students: " + totalStudentsEnrolled);
    }
}

public class ClassesAndObjectsBasics {
    public static void main(String[] args) {
        // Checking static context before instantiating objects
        Student.displayEnrollmentMetrics();

        // Instantiating objects via different constructors
        Student student1 = new Student();
        Student student2 = new Student(101, "Rahman Ali", 3.85);
        
        // Creating a clone using the copy constructor
        Student student3 = new Student(student2);

        System.out.println("\n--- Initializing Student Directory ---");
        student1.displayProfile();
        student2.displayProfile();
        student3.displayProfile();

        // Verifying shared static state
        System.out.println("\n--- Verifying Static Metric System ---");
        Student.displayEnrollmentMetrics();
    }
}