// The People Class
class People {

    private String name;
    private int age;
    private String gender;

    // Setters
    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    // Getters
    public String getName() {
        return this.name;
    }

    public int getAge() {
        return this.age;
    }

    public String getGender() {
        return this.gender;
    }
}

// The Student Class that inherits from people
class Student extends People {
    private double grade;

    // Setter
    public void setGrade(double grade) {
        this.grade = grade;
    }

    // Getter
    public double getGrade() {
        return this.grade;
    }

}

// The Teacher Class that inherits from people
class Teacher extends People {
    private double salary;

    // Setter
    public void setSalary(double salary) {
        this.salary = salary;
    }

    // Getter
    public double getSalary() {
        return this.salary;
    }

}

// Main Class
public class S2_Technical_A {

    public static void main(String args[]) {
        // Student 1
        Student student1 = new Student();
        student1.setName("Mark");
        student1.setAge(20);
        student1.setGender("Male");
        student1.setGrade(100);

        // Student 2
        Student student2 = new Student();
        student2.setName("Angelo");
        student2.setAge(21);
        student2.setGender("Male");
        student2.setGrade(99.5);

        // Teacher
        Teacher teacher = new Teacher();
        teacher.setName("Capili");
        teacher.setAge(30);
        teacher.setGender("Male");
        teacher.setSalary(100000);

        // Output the result:
        System.out.println("Student 1:\n");
        System.out.println("Name: " + student1.getName());
        System.out.println("Age: " + student1.getAge());
        System.out.println("Gender: " + student1.getGender());
        System.out.println("Grade: " + student1.getGrade() + "\n");

        System.out.println("Student 2:\n");
        System.out.println("Name: " + student2.getName());
        System.out.println("Age: " + student2.getAge());
        System.out.println("Gender: " + student2.getGender());
        System.out.println("Grade: " + student2.getGrade() + "\n");

        System.out.println("Teacher:\n");
        System.out.println("Name: " + teacher.getName());
        System.out.println("Age: " + teacher.getAge());
        System.out.println("Gender: " + teacher.getGender());
        System.out.println("Salary: " + teacher.getSalary() + "\n");

    }
}