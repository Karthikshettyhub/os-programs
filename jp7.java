public interface Resizable {
void resizeWidth(int width);
void resizeHeight(int height);
}
Create the Rectangle Class:
public class Rectangle implements Resizable {
private int width;
private int height;
public Rectangle(int width, int height) {
this.width = width;
this.height = height;
}

public void resizeWidth(int width) {
this.width = width;
}

public void resizeHeight(int height) {
this.height = height;

}
public void display() {
System.out.println("Rectangle: Width = " + width + ", Height = " +
height);
}
public static void main(String[] args) {
Rectangle rect= new Rectangle(5, 7);
System.out.println("Original Rectangle:");
rect.display();
// Resize the rectangle
rect.resizeWidth(8);
rect.resizeHeight(10);
System.out.println("Resized Rectangle:");
rect.display();
}
}
