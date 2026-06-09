/*
Problem(2): Model a database connectivity layer structure utilizing abstract 
            setters to handle initialization tasks across database flavors.
Input 
Establish paths to MySQL and Oracle database endpoints.
Output
Establishing secure channel port mapping strings...
[MySQL Engine] Connection initialized targeting connection string: jdbc:mysql://localhost:3306/production
Establishing secure channel port mapping strings...
[Oracle Engine] Connection initialized targeting connection string: jdbc:oracle:thin://host:1521/main
*/

abstract class DatabaseDriver {
    protected String connectionString;

    // Abstract classes can have constructors utilized by subclass super initializers
    public DatabaseDriver(String connectionString) {
        this.connectionString = connectionString;
    }

    public void displayPreConnectionTelemetry() {
        System.out.println("Establishing secure channel port mapping strings...");
    }

    public abstract void openConnectionPipeline();
}

class MySqlDriver extends DatabaseDriver {
    public MySqlDriver(String connectionString) {
        super(connectionString);
    }

    @Override
    public void openConnectionPipeline() {
        super.displayPreConnectionTelemetry();
        System.out.println("[MySQL Engine] Connection initialized targeting connection string: " + connectionString);
    }
}

class OracleDriver extends DatabaseDriver {
    public OracleDriver(String connectionString) {
        super(connectionString);
    }

    @Override
    public void openConnectionPipeline() {
        super.displayPreConnectionTelemetry();
        System.out.println("[Oracle Engine] Connection initialized targeting connection string: " + connectionString);
    }
}

public class DatabaseDriverLayer {
    public static void main(String[] args) {
        DatabaseDriver activeDriver = new MySqlDriver("jdbc:mysql://localhost:3306/production");
        activeDriver.openConnectionPipeline();

        System.out.println();

        activeDriver = new OracleDriver("jdbc:oracle:thin://host:1521/main");
        activeDriver.openConnectionPipeline();
    }
}