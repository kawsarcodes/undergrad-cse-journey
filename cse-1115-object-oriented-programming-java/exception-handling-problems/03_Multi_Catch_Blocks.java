/*
Problem(3): Build a fault-tolerant processing layer capable of routing distinct 
            mitigation strategies based on the exact type of exception raised.
Input 
Scenario A: Trigger NullPointerException via uninitialized array access loop.
Scenario B: Trigger ArrayIndexOutOfBoundsException via illegal array index targets.
Output
Execution Alert: Attempted to process operations on a null instance reference.
Execution Alert: Attempted to fetch an invalid offset index point from the data array array bounds.
*/

class TelemetryAnalyzer {
    public static void scanDataArray(int[] dataset, int targetingOffsetIndex) {
        try {
            int isolatedMetricValue = dataset[targetingOffsetIndex];
            System.out.println("Metric checkpoint cleared: " + isolatedMetricValue);
        } catch (NullPointerException exception) {
            System.out.println("Execution Alert: Attempted to process operations on a null instance reference.");
        } catch (ArrayIndexOutOfBoundsException exception) {
            System.out.println("Execution Alert: Attempted to fetch an invalid offset index point from the data array array bounds.");
        }
    }
}

public class MultiCatchBlocks {
    public static void main(String[] args) {
        TelemetryAnalyzer.scanDataArray(null, 2);

        int[] validDataPoints = {10, 20, 30};
        TelemetryAnalyzer.scanDataArray(validDataPoints, 99);
    }
}