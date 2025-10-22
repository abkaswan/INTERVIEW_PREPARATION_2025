public class VariableScope {
    int x = 3; // Class var

    // local var will take precedence over class vars
    // use class var in case of constants or when using OOPs concepts

    public void run(){
        // variable scope = where a variable can be accessed -> local and class
        int x = 1; // Local var in this method run
        System.out.println(x);
        doSomething();
    }
    static void doSomething(){
        int x = 2; // Local var in this method dosomething
        System.out.println(x);
    }
}
