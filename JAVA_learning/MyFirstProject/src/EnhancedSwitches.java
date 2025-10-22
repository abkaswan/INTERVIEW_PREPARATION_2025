import java.util.Scanner;

public class EnhancedSwitches {
    public void free(){
        // Enhanced switches = a replacement to many else if statements (java 14 feature)

        // example for many else if statements
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the day fo the week : ");
        String day = scanner.nextLine();

//        if(day.equals("Monday")){
//            System.out.println("It is a weekday");
//        }else if(day.equals("Tuesday")){
//            System.out.println("It is a weekday");
//        }else if(day.equals("Wednesday")){
//            System.out.println("It is a weekday");
//        }else if(day.equals("Thursday")){
//            System.out.println("It is a weekday");
//        }else if(day.equals("Friday")){
//            System.out.println("It is a weekday");
//        }else if(day.equals("Saturday")){
//            System.out.println("It is the weekend");
//        }else if(day.equals("Sunday")){
//            System.out.println("It is the weekend");
//        }else{
//            System.out.println("Not a valid day");
//        }

        switch(day){
            case "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" -> System.out.println("It is a weekday 😫");
            case "Saturday", "Sunday" -> System.out.println("It is the weekend 😎");
            default -> System.out.println(day + " is not a valid day");
        }

        scanner.close();
    }
}
