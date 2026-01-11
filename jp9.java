public class MyClass {
public void display() {
System.out.println("This is a class from the mypack package.");
}
}
Create another class inside the package
MainClass.java

public class MainClass {
public static void main(String[] args) {
MyClass obj = new MyClass(); // using class from package
obj.display();
}
}
