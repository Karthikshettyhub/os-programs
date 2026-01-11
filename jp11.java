public class MyThread extends Thread {
public MyThread() {
super();
}
public void run() {
System.out.println("Child Thread is running.");
}
}

Create another class inside package
Main.java
public class Main {
public static void main(String[] args) {
MyThread child = new MyThread(); // Create an object of MyThread
child.start(); // Start the thread
}
}
