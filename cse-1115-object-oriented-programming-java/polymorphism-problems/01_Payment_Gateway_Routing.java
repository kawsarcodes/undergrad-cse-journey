/*
Problem(1): Build a flexible payment router where checkout steps morph 
            dynamically based on the payment type instance.
Input 
Process Checkout via CreditCard instance with amount $500
Process Checkout via Bkash instance with amount $150
Output
Processing credit card payment of $500.0 (Applying a 2% checkout fee).
Processing bKash mobile wallet payment of $150.0 instantly.
*/

class PaymentMethod {
    public void executeTransaction(double amount) {
        System.out.println("Processing a generic transaction of $" + amount);
    }
}

class CreditCardPayment extends PaymentMethod {
    @Override
    public void executeTransaction(double amount) {
        double processingFee = amount * 0.02;
        System.out.println("Processing credit card payment of $" + amount + " (Applying a 2% checkout fee).");
    }
}

class BkashPayment extends PaymentMethod {
    @Override
    public void executeTransaction(double amount) {
        System.out.println("Processing bKash mobile wallet payment of $" + amount + " instantly.");
    }
}

public class PaymentGatewayRouting {
    public static void main(String[] args) {
        PaymentMethod[] transactions = {
            new CreditCardPayment(),
            new BkashPayment()
        };

        double[] amounts = {500.0, 150.0};

        for (int i = 0; i < transactions.length; i++) {
            transactions[i].executeTransaction(amounts[i]);
        }
    }
}