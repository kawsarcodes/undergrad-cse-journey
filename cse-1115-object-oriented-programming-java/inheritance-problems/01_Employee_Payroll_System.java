/*
Problem(1): Design an organizational payroll hierarchy where base properties 
            flow downwards into specialized manager roles.
Input 
Base Worker: "Sajid", Base Salary: 4000
Manager: "Nadia", Base Salary: 6000, Management Bonus: 1500
Output
Sajid's Net Compensation: $4000.0
Nadia's Net Compensation: $7500.0
*/

class CorporateEmployee {
    protected String employeeName;
    protected double coreBaseSalary;

    public CorporateEmployee(String employeeName, double coreBaseSalary) {
        this.employeeName = employeeName;
        this.coreBaseSalary = coreBaseSalary;
    }

    public double calculateNetTakeHomePay() {
        return coreBaseSalary;
    }
}

class DepartmentManager extends CorporateEmployee {
    private double monthlyManagementBonus;

    public DepartmentManager(String employeeName, double coreBaseSalary, double monthlyManagementBonus) {
        super(employeeName, coreBaseSalary);
        this.monthlyManagementBonus = monthlyManagementBonus;
    }

    @Override
    public double calculateNetTakeHomePay() {
        return super.calculateNetTakeHomePay() + monthlyManagementBonus;
    }
}

public class EmployeePayrollSystem {
    public static void main(String[] args) {
        CorporateEmployee staff = new CorporateEmployee("Sajid", 4000.0);
        DepartmentManager boss = new DepartmentManager("Nadia", 6000.0, 1500.0);

        System.out.println(staff.employeeName + "'s Net Compensation: $" + staff.calculateNetTakeHomePay());
        System.out.println(boss.employeeName + "'s Net Compensation: $" + boss.calculateNetTakeHomePay());
    }
}