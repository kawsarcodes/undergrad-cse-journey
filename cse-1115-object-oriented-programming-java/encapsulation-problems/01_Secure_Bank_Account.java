/*
Problem(1): Secure bank account ledger utilizing validation checkpoints.
Input 
Account: ACC992, Initial: $500
Operations: Deposit($200), Withdraw($800), Withdraw($300)
Output
Deposit Successful.
Error: Overdraft rejected. Insufficient funds.
Withdrawal Successful.
Final Balance: $400
*/

class SecureBankAccount {
    private String accountNumber;
    private double balance;

    public SecureBankAccount(String accountNumber, double initialBalance) {
        this.accountNumber = accountNumber;
        this.balance = initialBalance >= 0 ? initialBalance : 0;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposit Successful.");
        }
    }

    public void withdraw(double amount) {
        if (amount <= 0) return;
        
        if (balance - amount >= 0) {
            balance -= amount;
            System.out.println("Withdrawal Successful.");
        } else {
            System.out.println("Error: Overdraft rejected. Insufficient funds.");
        }
    }

    public double getBalance() {
        return balance;
    }
}

public class SecureBankAccountSystem {
    public static void main(String[] args) {
        SecureBankAccount acc = new SecureBankAccount("ACC992", 500.0);
        
        acc.deposit(200.0);
        acc.withdraw(800.0);
        acc.withdraw(300.0);
        
        System.out.println("Final Balance: $" + acc.getBalance());
    }
}