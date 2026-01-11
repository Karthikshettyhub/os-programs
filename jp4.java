package project;
class Shape {
public void draw() {
System.out.println("Drawing a generic shape");
}
public void erase() {
System.out.println("Erasing a generic shape");
}
}
class Circle extends Shape {
public void draw() {
System.out.println("Drawing a circle");
}
public void erase() {
System.out.println("Erasing a circle");
}
}
class Triangle extends Shape {
public void draw() {
System.out.println("Drawing a triangle");
}
public void erase() {
System.out.println("Erasing a triangle");
}
}
class Square extends Shape {
public void draw() {
System.out.println("Drawing a square");
}
public void erase() {
System.out.println("Erasing a square");
}
}

public class Main {
public static void main(String[] args) {
Shape cir = new Circle();
Shape tri = new Triangle();
Shape squ = new Square();
// Demonstrate polymorphism by calling draw() and
erase() on different shapes
cir.draw();
cir.erase();
tri.draw();
tri.erase();
squ.draw();
squ.erase();
}
}
