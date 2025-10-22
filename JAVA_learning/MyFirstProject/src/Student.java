public class Student {
    // constructor = a special method to initialize objects , you can pass arguments to a constructor , and set up initial values
    String name="Spongebob";
    int age;
    double gpa;
    boolean isEnrolled;

    // here this refers to the object we are currently working with like for student1's time it would be student1 , student2's time it would be student2
    Student(String name,int age, double gpa){
        this.name = name;
        this.age = age;
        this.gpa = gpa;
        this.isEnrolled = true;
    }

    // instance method (or constructor) , java automatically gives you access to the current object through a hidden reference called this.
    void study(){
        System.out.println(name+" is studying.");
    }
}
