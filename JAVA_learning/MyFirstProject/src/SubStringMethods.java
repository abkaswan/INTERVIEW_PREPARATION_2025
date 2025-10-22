import java.util.Scanner;

public class SubStringMethods {
    public void fun(){
        // .substring() = a method used to extract a portion of a string .substring(start,end)
        Scanner scanner = new Scanner(System.in);
        String email;
        String username;
        String domain;

        // step 1 : email slicer program
        email = "abkakshi@gmail.com";
        username = email.substring(0,8);
        // String domain = email.substring(9,18);
        // or we can just give the starting index and end index it will take by default if you wnat to go to last index
        domain = email.substring(9);
        System.out.println("user : "+username+" and domain : "+domain);

        // step 2 : make it flexible -- instead of manually entering indices we can determine what this number should be using another string method
        System.out.print("Enter your email: ");
        email = scanner.nextLine();

        if(email.contains("@")) {
            username = email.substring(0, email.indexOf("@"));
            domain = email.substring(email.indexOf("@") + 1);
            System.out.println("user : " + username + " and domain : " + domain);
        }
        else{
            System.out.println("Emails must contain @");
        }
        scanner.close();
    }
}
