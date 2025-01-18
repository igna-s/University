package Artes2;
/*
* This subclass of Item represents multi-media resources.
******************************************/
public class MultiMediaItem extends Item {
private int playingTime;
public MultiMediaItem(String title, String language, int time) {
super(title, language);
playingTime = time;
}
public void print() {
super.print();
System.out.println("Playing Time: " + playingTime + "mins");
}
}
