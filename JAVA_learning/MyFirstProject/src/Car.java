public class Car {

    String make = "Ford";
    String model = "Mustang";
    int year = 2025;
    double price = 58000.99;
    boolean isRunning = false;
    String color;
    Engine engine;

    Car(){

    }
    // so this way when constructing a car obj we will also be constructing a engine object.
    Car(String model,int year,String engineType){
        this.model = model;
        this.year = year;
        this.engine = new Engine(engineType);
    }
    Car(String make,String model, int year,String color){
        this.make = make;
        this.model = model;
        this.year = year;
        this.color = color;
    }
    void startCompo(){
        this.engine.start();
        System.out.println("The "+this.model+" is running.");
    }
    @Override
    public String toString(){
        return this.color+" "+this.year+" "+this.make+" "+this.model;
    }

    void start(){
        isRunning = true;
        System.out.println("You start the engine");
    }
    void stop(){
        isRunning = false;
        System.out.println("You stop the engine");
    }
    void drive(){
        System.out.println("You drive the "+model);
    }
    void brake(){
        System.out.println("You break the "+model);
    }
}
