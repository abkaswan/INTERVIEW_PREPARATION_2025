import java.util.InputMismatchException;
import java.util.Scanner;

public class Exception {
    public void run(){
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.println(1 / 0);
        }
        catch (ArithmeticException e){
            System.out.println("You can't divide by zero!");
        }

        System.out.println("************************");
        try{
            System.out.print("Enter a number : ");
            int number = scanner.nextInt();
            System.out.println(number);
        }
        catch (InputMismatchException e){
            System.out.println("That wasn't a number!");
        }
        catch (ArithmeticException e){
            System.out.println("You can't divide by zero !");
        }
        catch(java.lang.Exception e){
            System.out.println("Something went wrong.");
        }
        finally {
            scanner.close();
            // finally is often used for cleanup (cleaning up your program once you are done with it.)
            // you cna close scanner like we are doing it here because we don't want to close it if there are exception
            // other times if you open a file in try block and want to close it
            System.out.println("This always executes.");
        }

        // there is also try with resources. if you will hover over try yo uwill see , if you use that it will close the scanner by itself , no need to do it from our side.


    }
}
