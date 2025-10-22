public class User {
    // overloaded constructors = Allow a class to have multiple constructors
    //                           With different parameter lists.
    //                           Enable objects to initialized in various ways.

    String username;
    String email;
    int age;

    User(){
        this.username = "Guest";
        this.email = "Not Provided";
        this.age = 0;
    }
    User(String username){
        this.username = username;
        this.email = "Not Provided";
        this.age = 0;
    }
    User(String username,String email){
        this.username = username;
        this.email = email;
        this.age = 0;
    }
    User(String username,String email,int age){
        this.username = username;
        this.email = email;
        this.age = age;
    }

}
