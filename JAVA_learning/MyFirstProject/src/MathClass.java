import java.util.Scanner;

public class MathClass {
    public void run(){
        System.out.println(Math.PI);
        System.out.println(Math.E);

        double result;
        result = Math.pow(2,5);
        result = Math.abs(-5);
        result = Math.sqrt(9);
        // round will round the number to nearest whole integer
        result = Math.round(3.234);
        // to always round up - ceiling method
        result = Math.ceil(3.234);
        // to always round down - floor method
        result = Math.floor(343.45);
        result = Math.max(19,45);
        result = Math.min(456,234);
        System.out.println(result);

        // Hypotenuse c = Math.sqrt(a^2+b^2);
        Scanner scanner = new Scanner(System.in);
        double a;
        double b;
        double c;
        System.out.print("Enter the length of side A: ");
        a = scanner.nextDouble();
        System.out.print("Enter the length of side B: ");
        b = scanner.nextDouble();
        c = Math.sqrt(Math.pow(a,2)+Math.pow(b,2));
        System.out.println("The hypotenuse (side c) is : "+c+"cm");


        // circumference  =  2*Math.PI*radius;
        // area = Math.PI*Math.pow(radius,2);
        // volume = (4.0/3.0)*Math.PI*Math.pow(radius,3)
        double radius;
        double circumference;
        double area;
        double volume;

        System.out.print("Enter the radius: ");
        radius = scanner.nextDouble();

        circumference = 2*Math.PI*radius;
        area = Math.PI*Math.pow(radius,2);
        volume = (4.0/3.0)*Math.PI*Math.pow(radius,3);

        System.out.println("The circumference is : "+circumference+"cm");
        System.out.println("The area is : "+area+"cm^2");
        System.out.println("The volume is : "+volume+"cm^3");

        // use printf instead of println , we could display jsut the few digits like for circumference , area or volume , try the below and compare the outputs
        System.out.printf("The circumference is : %.1fcm\n",circumference);
        System.out.printf("The area is : %.1fcm^2\n",area);
        System.out.printf("The volume is : %.1fcm^3\n",volume);

        // printf() = is a method used to format output
        // %[flags][width][.precision][specifier-character]
        String name = "Spongebob";
        char firstLetter = 'S';
        int age = 30;
        double height = 60.5;
        boolean isEmployed = true;

        System.out.printf("Hello %s\n",name);
        System.out.printf("Your name starts with a %c\n",firstLetter);
        System.out.printf("You are %d years old.\n",age);
        System.out.printf("You are %f inches tall\n",height);
        System.out.printf("Employed: %b\n",isEmployed);

        System.out.printf("%s is %d years old\n",name,age);
        scanner.close();

        // precision = control the decimals using this , without this it noramlly prints 6 digits after the number
        double price1 = 9000.99;
        double price2 = 100000.123;
        double price3 = -534000.01;
        // try .1, .2, .3 all you will see the results
        System.out.printf("%+.2f\n",price1);
        System.out.printf("%,.2f\n",price2);
        System.out.printf("%(.2f\n",price3);
        System.out.printf("% .2f\n",price3);

        // [flags]
        // + = ouput a plus
        // , = comma grouping separator
        // ( = negative numbers are enclosed in ()
        // space = display a minus if negative, space if positive


        // [width]
        // 0 = zero padding
        // number = right justified padding
        // negative number = left justified padding

        int id1 = 1;
        int id2 = 23;
        int id3 = 456;
        int id4 = 7890;

        System.out.printf("%4d\n",id1);
        System.out.printf("%-4d\n",id2);
        System.out.printf("%04d\n",id3);
        System.out.printf("%04d\n",id4);

    }
}
