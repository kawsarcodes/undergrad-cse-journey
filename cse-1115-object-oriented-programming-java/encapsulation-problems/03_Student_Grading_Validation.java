/*
Problem(3): Track student grades ensuring score assignments fall strictly between 0 and 100.
Input 
Initial Score: 85
Updates: Set(105), Set(-15), Set(92)
Output
Error: Invalid score value. Rejecting update.
Error: Invalid score value. Rejecting update.
Current Letter Grade: A
*/

class StudentRecord {
    private String studentName;
    private int numericScore;

    public StudentRecord(String studentName, int initialScore) {
        this.studentName = studentName;
        setNumericScore(initialScore);
    }

    public void setNumericScore(int score) {
        if (score >= 0 && score <= 100) {
            this.numericScore = score;
        } else {
            System.out.println("Error: Invalid score value. Rejecting update.");
        }
    }

    public char calculateLetterGrade() {
        if (numericScore >= 90) return 'A';
        if (numericScore >= 80) return 'B';
        if (numericScore >= 70) return 'C';
        if (numericScore >= 60) return 'D';
        return 'F';
    }
}

public class StudentGradingValidation {
    public static void main(String[] args) {
        StudentRecord student = new StudentRecord("Tariq", 85);
        
        student.setNumericScore(105);
        student.setNumericScore(-15);
        student.setNumericScore(92);
        
        System.out.println("Current Letter Grade: " + student.calculateLetterGrade());
    }
}