package Artes2;

/***************************************
* This subclass of the class Item represents a textbook object.
***************************************/
public class Textbook extends Item {
private String author;
private int numberPages;
public Textbook(String title, String author, String language, int pages) {
super(title, language);
this.author = author;
numberPages = pages;
}
public void print() {
super.print();
System.out.println("Number of Pages: " + numberPages + "pages");
System.out.println("Author: " + author);
}
}