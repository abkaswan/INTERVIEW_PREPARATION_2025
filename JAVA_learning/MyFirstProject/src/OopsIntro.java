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

        CarNew[] cars = {new CarNew("Mustang","Red"),
                new CarNew("Corvette","Blue"),
                new CarNew("Charger","Yellow")};

        for(CarNew carNew : cars){
            carNew.color = "black";
            carNew.drive();
        }

        System.out.println("------------------------Static Keyword--------------------------");
        Friend friend1 = new Friend("Spongebob");
        Friend friend2 = new Friend("Abhishek");
        Friend friend3 = new Friend("Monika");
        Friend friend4 = new Friend("Rahul");

        System.out.println(friend1.name);

        // here you can see that this is 1 for both if we don't use static keyword in Friend class file
        // System.out.println(friend1.numOfFriends);
        // System.out.println(friend2.numOfFriends);

        System.out.println(Friend.numOfFriends);
        Friend.showFriends();

        // round is a utility method you don't need to create Math object like Math math = new Math();
        // Math.round(3.99);

        System.out.println("------------------------ Inheritence --------------------------");
        // Inheritance = One class inherits the attributes and methods
        //               From another class.
        //               Child <- Parent <- GrandParent


        Dog dog = new Dog();
        Cat cat = new Cat();
        Plant plant = new Plant();


        System.out.println("Dog is alive : "+dog.isAlive);
        System.out.println("Cat is alive : "+cat.isAlive);

        dog.eat();
        cat.eat();

        System.out.println(dog.lives);
        System.out.println(cat.lives);

        dog.speak();
        cat.speak();
        plant.photoSynthesize();

        System.out.println("------------------------ Super keyword --------------------------");
        // Super = Refers to the parent class (subclass <- superclass)
        //         Used in constructors and method overriding
        //         Calls the parent constructor to initialize attributes2
        Person person = new Person("Jack","Sparrow");
        PStudent pStudent = new PStudent("Harry","Potter",4);
        PEmployee pEmployee = new PEmployee("Rubeus","Hagrid",50000);
        person.showName();
        pStudent.showName();
        pStudent.showGPA();
        pEmployee.showSalary();


        System.out.println("------------------------ Method Overriding --------------------------");
        // Method overriding = When a subclass provides its own
        //                     implementation of a method that is already defined.
        //                     Allows for code reusability and give specific implementation.

        Dog dog1 = new Dog();
        Cat cat1 = new Cat();
        Fish fish1 = new Fish();

        dog1.move();
        cat1.move();
        fish1.move();

        System.out.println("------------------------ toString method --------------------------");
        // .toString() = Method inherited from the Object class.
        //               Used to return a string representation of an object.
        //               By default , it returns a hash code as a unique identifier.
        //               It can be overridden to provide meaningful details.

        // if you will go to this Object.java class , you will see that this is a super class , here toString method is used to return a string representation of an object if you were to output it directly using System.out.println
        // Object object = new Object();
        Car car2 = new Car("Foka","Mstanasdf",2092,"Red");
        Car car3 = new Car("Cheverolet","Corvette",2053,"White");

        System.out.println(car2);
        System.out.println(car3);

        System.out.println("------------------------ Abstraction  --------------------------");
        // abstract = Used to define abstract classes and methods.
        //            Abstraction is the process of hiding implementation details
        //            and showing only the essential features.
        //            Abstract classes CAN'T be instantiated directly
        //            Can contain 'abstract' methods (which must be implemented)
        //            Can contain 'concrete' methods (which are inherited)

        // so if you uncomment this , you will see the error that we can't create the shape class, can't instantiate it
        // Shape shape = new Shape();
        Circle circle = new Circle(3);
        Triangle triangle = new Triangle(4,5);
        Rectangle rectangle = new Rectangle(6,7);

        circle.display();
        triangle.display();
        rectangle.display();

        System.out.println(circle.area());
        System.out.println(triangle.area());
        System.out.println(rectangle.area());

        System.out.println("------------------------ INTERFACE  --------------------------");
        // Interface = a blueprint for a class that specifies a set of abstract methods
        //             that implementing classes MUST define.
        //             Supports multiple inheritance - like behaviour.

        Rabbit rabbit = new Rabbit();
        Hawk hawk = new Hawk();
        Fish fish = new Fish();

        rabbit.flee();
        hawk.hunt();
        fish.flee();
        fish.hunt();

        System.out.println("------------------------ POLYMORPHISM  --------------------------");
        // Polymorphism = "POLY" = "MANY"
        //                 "MORPH" = "SHAPE"
        //                 Objects can identify as other objects.
        //                 Objects can be treated as objects of a common superclass.
        

    }

}
