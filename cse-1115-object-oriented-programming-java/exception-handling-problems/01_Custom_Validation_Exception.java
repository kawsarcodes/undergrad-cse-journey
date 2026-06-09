/*
Problem(1): Build an internal verification framework that raises a custom, 
            domain-specific domain exception when an underage profile attempts registration.
Input 
Register profile with age = 15
Output
Registration Aborted: Age falls below the mandatory criteria limit.
Executing downstream system cleanup...
*/

// Custom checked exception definition
class AgeBoundaryException extends Exception {
    public AgeBoundaryException(String contextualAlertMessage) {
        super(contextualAlertMessage);
    }
}

class GatekeeperService {
    public static void processUserEnrollment(int customerAge) throws AgeBoundaryException {
        if (customerAge < 18) {
            throw new AgeBoundaryException("Age falls below the mandatory criteria limit.");
        }
        System.out.println("Profile successfully validated and committed to storage.");
    }
}

public class CustomValidationException {
    public static void main(String[] args) {
        try {
            GatekeeperService.processUserEnrollment(15);
        } catch (AgeBoundaryException exception) {
            System.out.println("Registration Aborted: " + exception.getMessage());
        } finally {
            System.out.println("Executing downstream system cleanup...");
        }
    }
}