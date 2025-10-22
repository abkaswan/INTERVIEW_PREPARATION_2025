public class PEmployee extends Person{
    int salary;
    PEmployee(String first,String last,int salary){
        super(first,last);
        this.salary = salary;
    }

    void showSalary(){
        System.out.println(this.first+" "+this.last+"'s salary is : $"+this.salary);
    }
}
