/*
Problem(3): Design an extensible user interface engine using compile time overloading 
            to render components with varying layers of styling configuration details.
Input 
Render basic button ("Submit")
Render styled button ("Cancel", Border: "Solid Red", Font: 14)
Output
[UI Engine Context] Drawing standard UI element: Submit
[UI Engine Context] Drawing customized element: Cancel | Border Profile: Solid Red | Text Metric: 14px
*/

class ComponentRenderer {
    public void drawElement(String label) {
        System.out.println("[UI Engine Context] Drawing standard UI element: " + label);
    }

    public void drawElement(String label, String borderStyle, int fontSize) {
        System.out.println("[UI Engine Context] Drawing customized element: " + label + 
                           " | Border Profile: " + borderStyle + " | Text Metric: " + fontSize + "px");
    }
}

public class UIComponentLogger {
    public static void main(String[] args) {
        ComponentRenderer engine = new ComponentRenderer();

        engine.drawElement("Submit");
        engine.drawElement("Cancel", "Solid Red", 14);
    }
}