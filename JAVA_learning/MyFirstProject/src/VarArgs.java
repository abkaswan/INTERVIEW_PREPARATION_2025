public class VarArgs {
    public void fun(){
        // variable arguments => VarArgs = allow a method to accept a varying # of arguments ,  makes methods more flexible , no need for overload methods , java will pack the arguments into an array ....(ellipsis)
        System.out.println(add(1,2,3,4));
        System.out.println(average(1,2,3,4,5,6,7));
        System.out.println(average());
    }
    // instead of this we can create one method that acceps varying number of arguments

    // static double add (int a, int b){return a+b;}
    // static double add (int a, int b, int c ){return a+b+c;}
    // static double add (int a, int b, int c , int d ){return a+b+c+d;}
    // static double add (int a, int b , int c , int d , int e ){return a+b+c+d+e;}

    // creating VarArgs fn for sum
    static int add(int... numbers){
        int sum = 0;
        for(int number : numbers){
            sum+=number;
        }
        return sum;
    }
    // creating VarArgs fn for average
    static double average(double... numbers){
        double sum = 0;
        if(numbers.length==0){
            return 0;
        }
        for(double number : numbers){
            sum+=number;

        }
        return sum/numbers.length;
    }
}
