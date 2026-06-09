/*
Problem: Encapsulate book entry items with defensive mutation gates (Getters and Setters).
Input 
Book instance updates: Title="OOP Java", Author="Deitel", Price=120.50
Output
Title: OOP Java
Author: Deitel
Price: $120.50
*/

class Book {
    private String title;
    private String author;
    private double price;

    public Book(String title, String author, double price) {
        this.title = title;
        this.author = author;
        this.price = price;
    }

    public String getTitle() { return title; }
    public void setTitle(String title) { this.title = title; }

    public String getAuthor() { return author; }
    public void setAuthor(String author) { this.author = author; }

    public double getPrice() { return price; }
    public void setPrice(double price) { this.price = price; }

    public void displayRecordDetails() {
        System.out.println("\nTitle: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: $" + price);
        System.out.println("----------------------------------------------");
    }
}

public class BookCatalogManagement {
    public static void main(String[] args) {
        Book book1 = new Book("Title1", "Author1", 132.23);
        Book book2 = new Book("Title2", "Author2", 99.99);

        book1.displayRecordDetails();
        book2.displayRecordDetails();
    }
}