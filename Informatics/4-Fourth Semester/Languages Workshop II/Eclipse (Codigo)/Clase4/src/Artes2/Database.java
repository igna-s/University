package Artes2;

import java.util.ArrayList;
import java.util.Iterator;
/*****************************************
* The database class provides a facility to store CD and video
* objects. A list of all textbooks, CDs and videos can be printed to the terminal.
****************************************/
public class Database {
private ArrayList items;
public Database() {
items = new ArrayList();
}
public void addItem(Item item) {
items.add(item);
}
/**
* Print a list of all currently stored CDs and videos to the
* text terminal.
*/
public void list() {
for(Item item: items) {
item.print();

System.out.println(); // empty line between items
}
}
}
