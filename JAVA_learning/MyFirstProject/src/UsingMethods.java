public class UsingMethods {
    public static void use(){
        //method = a block of reusable code that is executed when called ()

        String name = "patrick";
        int age = 55;

        happyBirthday(name,age);

        // method to create a square of number
        System.out.println(square(2));
        System.out.println(cube(2));
        System.out.println(getFullName("Abhishek","Kaswan"));

        age = 21;
        if(ageCheck(age)){
            System.out.println("You may sign up !");
        }
        else {
            System.out.println("You must be 18+ to sign up. ");
        }
    }
    static void happyBirthday(String bBoy,int age){
        System.out.println("Happy Birthday to you! ");
        System.out.printf("Happy Birthday dear %s\n",bBoy);
        System.out.printf("You are %d years old!\n",age);
        System.out.println("Happy Birthday to you!\n");
    }
    static double square(double number){
        return number * number;
    }
    static double cube(double n){
        return n*n*n;
    }
    static String getFullName(String first,String last){
        return first+" "+last;
    }
    static boolean ageCheck(int age){
        if(age>=18)
            return true;
        else
            return false;
    }
}
