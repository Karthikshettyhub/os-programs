class DivisionByZeroException extends Exception {
DivisionByZeroException(String msg) {
super(msg);
}
}
public class CustomException {
public static void main(String[] args) {
int a = 10;
int b = 0;
try {
if (b == 0) {
throw new DivisionByZeroException("Division by zero is not
allowed");
}
int result = a / b;
System.out.println("Result: " + result);

}
catch (DivisionByZeroException e) {
System.out.println(e.getMessage());
}
finally {
System.out.println("Program execution completed");
}
}
}
