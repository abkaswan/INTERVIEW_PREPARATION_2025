public class ArithmeticOps {
    public void ArithmeticRun(){
        //Arithmetic operations
        int x = 10;
        int y = 2;
        int z;
        //z= x+y;
        //z= x-y;
        //z= x*y;
        //z= x/y;
        //z= x%y;

        // another method to do this instead of x = x+y;
        x+=y;
        //System.out.println(z);
        System.out.println(x);

        // Increment and Decrement Operators
        x =1;
        // instead of x = x+1 and x+=1 we can do x++;
        x++;
        x++;
        x--;
        System.out.println(x);

        // ORDER of Operations (P-E-M-D-A-S)
        double result = 3+4*(7-5)/2.0;
        System.out.println(result);
    }
}
