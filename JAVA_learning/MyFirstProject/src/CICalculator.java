import java.util.Scanner;
public class CICalculator {
    public void run(){
        // compound interest calculator
        Scanner scanner = new Scanner(System.in);
        double principal;
        double rate;
        int timesCompounded;
        int years;
        double amount;

        System.out.print("Enter the principal amount : ");
        principal = scanner.nextDouble();
        System.out.print("Enter the interest rate(int %): ");
        rate = scanner.nextDouble()/100;
        System.out.print("Enter the number of times compounded per year: ");
        timesCompounded = scanner.nextInt();
        System.out.print("Enter the number of years: ");
        years = scanner.nextInt();

        amount = principal*Math.pow(1+rate/timesCompounded,timesCompounded*years);
//        System.out.println("The amount after "+years+" is: $"+amount);
        System.out.printf("The amount after %d years is $%.2f",years,amount);

        scanner.close();
    }
}
