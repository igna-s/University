package Artes;
/*****************************************
* The Textbook class represents a textbook object.
****************************************/
public class Textbook {
private String title;
private String author;
private String language;
private int numberPages;
private boolean available;
private String comment;
/**
* Initialize the Book.
*/
public Textbook(String title, String author, String language, int pages) {
this.title = title;
this.author = author;
this.language = language;
numberPages = pages;
available = true;

comment = "<no comment>";
}
/**
* Enter a comment for this Book.
*/
public void setComment(String comment) {
this.comment = comment;
}
/**
* Return the flag indicating whether this book is available.
*/
public boolean getAvailable() {
return available;
}
/**
* Print details about this book to the text terminal.
*/
public void print() {
System.out.print("Title: " + title);
if(available) System.out.println("*");
else System.out.println();
System.out.println("Comment: " + comment);
System.out.println("Language: " + language);
System.out.println("Number Pages: " + numberPages + " pages");
System.out.println("Author: " + author);
}
}