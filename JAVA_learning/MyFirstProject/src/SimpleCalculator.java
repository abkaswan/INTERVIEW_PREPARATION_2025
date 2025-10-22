import java.util.Scanner;

public class SimpleCalculator {
    public void calculate(){

        Scanner scanner = new Scanner(System.in);
        double num1;
        double num2;
        char operator;
        double result;

        System.out.print("Enter the first number : ");
        num1 = scanner.nextDouble();

        System.out.print("Enter an operator (+,-,*,/,^): ");
        operator = scanner.next().charAt(0);

        System.out.print("Enter the second number : ");
        num2 = scanner.nextDouble();

        switch (operator){
            case '+' -> result = num1+num2;
            case '-' -> result = num1 - num2;
            case '*' -> result = num1 * num2;
            case '/' -> {
                if(num2 != 0){
                    result = num1 / num2;
                }else{
                    System.out.println("Error! Division by zero");
                    return;
                }
            }
            case '^' -> result = Math.pow(num1,num2);
            default -> {
                System.out.println("Error! Invalid operator");
                return;
            }
        }
        System.out.println(result);

        scanner.close();
    }
}
