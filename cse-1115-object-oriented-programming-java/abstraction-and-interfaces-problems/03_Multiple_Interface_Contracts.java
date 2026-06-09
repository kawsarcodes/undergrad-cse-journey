/*
Problem(3): Leverage multiple interface implementations to build a multi-role 
            Workstation device that prints and scans content simultaneously.
Input 
Instantiate a multi-functional system appliance device.
Output
[Print Module] Queueing asset rendering: quarterly_report.pdf
[Scan Module] Digitizing physical document array matrices...
*/

interface DocumentPrinter {
    void executionPrintJob(String fileTarget);
}

interface DocumentScanner {
    void scanDocumentLayout();
}

// Resolving multiple inheritance behaviors via contract interface implementations
class OfficeWorkstation implements DocumentPrinter, DocumentScanner {

    @Override
    public void executionPrintJob(String fileTarget) {
        System.out.println("[Print Module] Queueing asset rendering: " + fileTarget);
    }

    @Override
    public void scanDocumentLayout() {
        System.out.println("[Scan Module] Digitizing physical document array matrices...");
    }
}

public class MultipleInterfaceContracts {
    public static void main(String[] args) {
        OfficeWorkstation machine = new OfficeWorkstation();
        machine.executionPrintJob("quarterly_report.pdf");
        machine.scanDocumentLayout();
    }
}