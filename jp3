public class Employee {
private int id;
private String name;
private double salary;

// Constructor
public Employee(int id, String name, double salary) {
this.id = id;
this.name = name;
this.salary = salary;
}

// Getter methods
public int getId() {
return id;
}

public String getName() {
return name;
}

public double getSalary() {
return salary;
}

// Method to raise the salary by a given percentage
public void raiseSalary(double percent) {
if (percent > 0) {
double increase = salary * (percent / 100);
salary += increase;
System.out.println(name + "'s salary has been increased by " +
percent + "%. New salary: $" + salary);
} else {
System.out.println("Invalid percentage. Salary not increased.");
}
}
public static void main(String[] args) {
// Creating an Employee object
Employee employee1 = new Employee(1, "John Doe", 50000.0);
// Displaying employee information
System.out.println("Employee Information:");
System.out.println("ID: " + employee1.getId());
System.out.println("Name: " + employee1.getName());
System.out.println("Salary: $" + employee1.getSalary());

// Raising salary by 10%
employee1.raiseSalary(10);

// Displaying updated salary
System.out.println("Updated Salary: $" + employee1.getSalary());
}
}
