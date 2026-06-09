/**
 * Topic: Encapsulation and Access Modifiers
 * Description: Demonstrates data hiding, validation gates, and visibility scopes.
 */

package encapsulation;

class Employee {
    // Hidden data fields (Strict data hiding)
    private String employeeId;
    private String name;
    private double monthlySalary;

    public Employee(String employeeId, String name, double monthlySalary) {
        this.employeeId = employeeId;
        this.name = name;
        setMonthlySalary(monthlySalary);
    }

    // Getter for ID (Read-only field)
    public String getEmployeeId() {
        return employeeId;
    }

    // Getter and Setter for Name
    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name != null && !name.trim().isEmpty()) {
            this.name = name;
        }
    }

    // Getter and Setter for Salary with defensive checks
    public double getMonthlySalary() {
        return monthlySalary;
    }

    public void setMonthlySalary(double monthlySalary) {
        if (monthlySalary > 0) {
            this.monthlySalary = monthlySalary;
        } else {
            System.out.println("Error: Salary must be greater than zero.");
        }
    }

    public double calculateAnnualSalary() {
        return this.monthlySalary * 12;
    }
}

public class EncapsulationBasics {
    public static void main(String[] args) {
        Employee emp = new Employee("EMP101", "Anisur Rahman", 4500.0);
        
        emp.setMonthlySalary(-1000.0);
        
        emp.setMonthlySalary(5000.0);
        
        System.out.println("Employee: " + emp.getName());
        System.out.println("Monthly Pay: $" + emp.getMonthlySalary());
        System.out.println("Annual Earnings: $" + emp.calculateAnnualSalary());
    }
}