package Artes2;
/*****************************************
* The Item class represents an item.
* This class serves as a superclass for more specific items.
*****************************************/
public class Item {
private String title;
private boolean available;
private String comment;
private String language;
public Item(String title, String language) {
this.title = title;
available = true;
this.language = language;
comment = "<no comment>";
}
public void setComment(String comment) {
this.comment = comment;
}
public boolean available() {
return available;
}
public void print() {
System.out.print("Title: " + title);
if(available) System.out.println("*");
else System.out.println();
System.out.println("Comment: " + comment);
System.out.println("Language: " + language);
}
}