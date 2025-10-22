import java.util.Scanner;

public class OopsIntro {
    public void run(){
        System.out.println("------------------------ OOPS INTRODUCTION -------------------");
        // OBJECT = an entity that holds data (attributes)
        //          and can perform actions (methods)
        //          It is a reference data type

        // we will create new java class for car
        Car car = new Car();
        Car car1 = new Car();
        // you will get the memory address as this is reference data type
        System.out.println(car);
        // to access things withing hte objectss
        System.out.println(car.make);
        System.out.println(car.year);
        System.out.println(car.price);
        car.price = 59000;
        System.out.println(car.price);

        System.out.println(car.isRunning);
        car.start();
        System.out.println(car.isRunning);
        car.stop();
        System.out.println(car.isRunning);

        car.drive();
        car.brake();

        // you can see that currently for two different objects also we have the same output , we will learn about constructors next and fix it
        System.out.println(car.make+" "+car.model);
        System.out.println(car1.make+" "+car1.model);

        System.out.println("------------------------constructors below--------------------------");
        // we call this constructor automatically when we intiate the object
        Student student1 = new Student("Abhishek",25,4.1);
        Student student2 = new Student("Patrick",34,1.5);

        System.out.println(student1.name+" "+student1.age+" "+student1.gpa+" "+student1.isEnrolled);
        System.out.println(student2.name+" "+student2.age+" "+student2.gpa+" "+student2.isEnrolled);

        student1.study();
        student2.study();

        System.out.println("------------------------Overloaded constructors below--------------------------");
        User user1 = new User("Spongebob");
        User user2 = new User("Patrick","Pstarz@aol.com");
        User user3 = new User("Sandy","sanDerwe@gmail.com",23);
        User user4 = new User();

        System.out.println(user1.username+" **** "+user1.email+" **** "+user1.age);
        System.out.println(user2.username+" **** "+user2.email+" **** "+user2.age);
        System.out.println(user3.username+" **** "+user3.email+" **** "+user3.age);
        System.out.println(user4.username+" **** "+user4.email+" **** "+user4.age);

        System.out.println("------------------------Array of Objects below--------------------------");
        CarNew carNew = new CarNew();


    }
}
