/*
Problem(2): Design an immutable system configuration class to protect critical environment data from runtime mutations.
Input 
Config: "Production", "192.168.1.1"
Output
Environment: Production
IP Address: 192.168.1.1
*/

final class SystemConfiguration {
    private final String environment;
    private final String databaseIp;

    public SystemConfiguration(String environment, String databaseIp) {
        this.environment = environment;
        this.databaseIp = databaseIp;
    }

    public String getEnvironment() {
        return environment;
    }

    public String getDatabaseIp() {
        return databaseIp;
    }
}

public class ImmutableDataClass {
    public static void main(String[] args) {
        SystemConfiguration config = new SystemConfiguration("Production", "192.168.1.1");
        
        System.out.println("Environment: " + config.getEnvironment());
        System.out.println("IP Address: " + config.getDatabaseIp());
    }
}