/**
 * Topic: Exception Handling Architecture
 * Description: Demonstrates checked vs unchecked exceptions, call stack propagation, and the finally block.
 */

package exceptionhandling;

import java.io.FileReader;
import java.io.IOException;

public class ExceptionHandlingBasics {

    // Checked Exception: Compiler forces handling via try-catch or throws declaration
    public static void readConfigurationFile() throws IOException {
        FileReader reader = new FileReader("non_existent_config.txt");
        reader.read();
        reader.close();
    }

    // Unchecked Exception: Runtime anomaly (ArithmeticException)
    public static int executeIntegerDivision(int numerator, int denominator) {
        return numerator / denominator;
    }

    public static void main(String[] args) {
        System.out.println("--- Testing Unchecked Exception Boundary ---");
        try {
            int result = executeIntegerDivision(10, 0);
            System.out.println("Result: " + result);
        } catch (ArithmeticException exception) {
            System.out.println("Intercepted Runtime Anomaly: Cannot divide by zero calculation limits.");
        }

        System.out.println("\n--- Testing Checked Exception & Finally Sequence ---");
        try {
            readConfigurationFile();
        } catch (IOException exception) {
            System.out.println("Intercepted Compile-time Anomaly: Configuration target disk file missing.");
        } finally {
            System.out.println("Critical System Notice: Running mandatory telemetry and cleanup procedures.");
        }
    }
}