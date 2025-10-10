import java.util.Scanner;

public class LessonDemo {
    public void run(){
        // THIS IS MY FIRST JAVA PROGRAM
        /*
            this
            is
            my
            multi-line comment
        */
        System.out.println("----lesson 1 : intro ------");
        System.out.print("me you talking to me?\n");
        System.out.println("I like burger!");
        System.out.print("wow it's good!\n");
        // shortcut for system.out.println is sout for intellij

        // variables = a reusable container for a value
        //             a variable behaves as if it was the value it contains

        // (a) primitive = simple value stored directly in memory (stack)
        // (b) reference = memory address (stack) that points to the (heap)

        // primitive vs reference
        // int          string
        // double       array
        // char         object
        // boolean

        // 2 steps to create a variable
        // (a) declaration
        // (b) assignment

        int year = 2025;
        int quantity = 1;
        int age = 30;

        double price = 19.99;
        double gpa = 3.5;
        double temperature = -12.5;

        char grade = 'A';
        char symbol = '!';
        char currency = '$';

        boolean isStudent = true;
        boolean forSale = false;
        boolean isOnline = true;

        String name = "Bro Code";
        String food = "pizza";
        String email = "fake112@gmail.com";
        String car = "Mustang";
        String color = "red";

        System.out.println("------lesson 2 : variables-----");
        System.out.println("You are "+age+" years old");
        System.out.println("Your gpa is "+ gpa);
        System.out.println("Your average letter grade is : "+grade);
        if(isStudent){
            System.out.println("You are a student");
        }
        else{
            System.out.println("You are not a student");
        }
        System.out.println("Your email is "+email);
        // now we will combine two or more variables in one print statement
        System.out.println("Your choice is a "+ color + " " + year + " " + car);
        System.out.println("The price is "+currency+price);
        if(forSale){
            System.out.println("There is a "+car+" for sale");
        }
        else{
            System.out.println("The "+car+" is not for sale");
        }

        System.out.println("------lesson 3 : user input -------");
        // how to accept user Input we will learn
        // scanner => it is a object that allows us to accept user input in java -- we need to import it from utilities
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your name: ");
        // nextLine reads a string of characters including any spaces , if you don't want any spaces you can use next()
        String user = scanner.nextLine();
        // to read integer we use nextInt
        System.out.print("Enter your age : ");
        int ageUser = scanner.nextInt();
        // for double we will use below : nextDouble
        System.out.print("What is your gpa : ");
        double gpaUser = scanner.nextDouble();
        // for boolean use nextBoolean
        System.out.print("Are you a student ? (true/false): ");
        boolean isUserStudent = scanner.nextBoolean();

        System.out.println("Hello "+ user);
        System.out.println("You are "+ ageUser +" years old");
        System.out.println("Your gpa is : "+gpaUser);
        if(isUserStudent){
            System.out.println("You are enrolled as a student!");
        }
        else{
            System.out.println("You are Not enrolled");
        }

        // common issues , try to print int then string
        // what happens is that it will give wrong output because when we type in a number 25 and hit enter (\n) within the input buffer there is still a newLine character even though 25 has been picked by nextInt()
        // so nextLine method is picking up that newLine character and using that as the input
        // we need to get rid of the newLine char ,
        // method : after accepting the age do scanner.nextLine() and then accept any other string
        System.out.print("Enter your age: ");
        int newage = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter your favorite color : ");
        String newcolor = scanner.nextLine();

        System.out.println("You are "+newage+" years old");
        System.out.println("You like the color "+newcolor);

        //exercise : calculate area of a rectangle
        double width = 0;
        double height = 0;
        double area = 0;

        System.out.print("Enter the width: ");
        width = scanner.nextDouble();
        System.out.print("Enter the height: ");
        height = scanner.nextDouble();

        area = width*height;
        System.out.println("The area is: "+area+"cm^2");

        // if you don't close a scanner it can lead to unexpected behaviour so best practice is this.
        scanner.close();
    }
}
