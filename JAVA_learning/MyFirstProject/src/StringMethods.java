public class StringMethods {
    public void run(){
        String name = "Bro Code";
        int length = name.length();
        System.out.println(length);

        // what is the char at that index
        char letter = name.charAt(0);
        System.out.println(letter);

        // what is the first occurence of ahy char
        int index = name.indexOf('r');
        System.out.println(index);

        int lastIndex = name.lastIndexOf('o');
        System.out.println(lastIndex);

        name = name.toUpperCase();
        System.out.println(name);

        name = name.toLowerCase();
        System.out.println(name);

        // use trim to remove white spaces in a string -- use some name where there is white space and see
        name = name.trim();
        System.out.println(name);

        // replace the char with any other , let's replace o's with a's
        name = name.replace('o','a');
        System.out.println(name);

        System.out.println(name.isEmpty());

        // if our name contains any spaces
        if(name.contains(" ")){
            System.out.println("your name contains spaces.");

        }
        else {
            System.out.println("your name doesn't contains spaces.");
        }

        // if two strings are equal
        // if we use equalsIgnoreCase that ignores case sensitivity
        if(name.equals("password")){
            System.out.println("Your name can't be password");
        }
        else{
            System.out.println("Hello "+name);
        }
    }
}
