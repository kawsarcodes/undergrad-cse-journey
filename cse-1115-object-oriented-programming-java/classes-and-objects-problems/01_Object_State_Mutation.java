/*
Problem(1): Track and manage product inventory states dynamically. 
            Ensure quantity changes are validated and compute running total values.
Input 
Product: Laptop, Price: 1200.0, Initial Stock: 10
Operations: Update Stock (+5), Sell (3), Try Over-sell (20)
Output
Initial Value: $12000.0
Updated Stock: 15
Sale Successful. Remainder Stock: 12
Error: Insufficient stock available. Transaction abandoned.
Final Valuation: $14400.0
*/

class InventoryItem {
    private String sku;
    private String itemName;
    private double unitPrice;
    private int quantityInStock;

    public InventoryItem(String sku, String itemName, double unitPrice, int quantityInStock) {
        this.sku = sku;
        this.itemName = itemName;
        this.unitPrice = unitPrice;
        this.quantityInStock = quantityInStock >= 0 ? quantityInStock : 0;
    }

    public void restock(int amount) {
        if (amount > 0) {
            this.quantityInStock += amount;
        }
    }

    public boolean processSale(int count) {
        if (count > 0 && count <= this.quantityInStock) {
            this.quantityInStock -= count;
            return true;
        }
        return false;
    }

    public double calculateInventoryValue() {
        return this.unitPrice * this.quantityInStock;
    }

    public int getQuantityInStock() {
        return this.quantityInStock;
    }
}

public class ObjectStateMutation {
    public static void main(String[] args) {
        InventoryItem item = new InventoryItem("LAP-99", "Gaming Laptop", 1200.0, 10);
        System.out.println("Initial Value: $" + item.calculateInventoryValue());

        item.restock(5);
        System.out.println("Updated Stock: " + item.getQuantityInStock());

        if (item.processSale(3)) {
            System.out.println("Sale Successful. Remainder Stock: " + item.getQuantityInStock());
        }

        if (!item.processSale(20)) {
            System.out.println("Error: Insufficient stock available. Transaction abandoned.");
        }

        System.out.println("Final Valuation: $" + item.calculateInventoryValue());
    }
}