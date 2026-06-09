/*
Problem(2): Design an optimized User Registration model that uses constructor chaining 
            via 'this()' to safely supply fallback default arguments for profile types.
Input 
User 1: "admin", "admin@root.com", "Administrator"
User 2: "guest_user", "guest@visit.com" (No role provided)
Output
Profile 1: admin [admin@root.com] Tier: Administrator
Profile 2: guest_user [guest@visit.com] Tier: Regular Client
*/

class UserProfile {
    private String username;
    private String email;
    private String userRole;

    // Target Master Constructor
    public UserProfile(String username, String email, String userRole) {
        this.username = username;
        this.email = email;
        this.userRole = userRole;
    }

    // Overloaded Constructor chaining to master via fallback defaults
    public UserProfile(String username, String email) {
        this(username, email, "Regular Client");
    }

    public void displayProfile() {
        System.out.println("Profile: " + username + " [" + email + "] Tier: " + userRole);
    }
}

public class ConstructorChaining {
    public static void main(String[] args) {
        UserProfile adminProfile = new UserProfile("admin", "admin@root.com", "Administrator");
        UserProfile guestProfile = new UserProfile("guest_user", "guest@visit.com");

        adminProfile.displayProfile();
        guestProfile.displayProfile();
    }
}