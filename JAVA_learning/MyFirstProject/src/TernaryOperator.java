public class TernaryOperator {
    public void fun(){
        // ternary Operator ? = return 1 or 2 values if a condition is true
        // variable = (condition)?ifTrue : ifFalse;
        // simpler version of if else statement

        int score = 70;
        String passOrFail = (score>=60)?"Pass":"FAIL";
        System.out.println(passOrFail);

        int number = 3;
        String evenOrOdd = (number%2==0)?"EVEN":"ODD";
        System.out.println(evenOrOdd);

        int hours = 13;
        String timeOfDay = (hours<12)?"A.M.":"P.M.";
        System.out.println(timeOfDay);

        int income = 60000;
        double taxRate = (income>=40000)?0.25:0.15;
        System.out.println(taxRate);

    }
}
