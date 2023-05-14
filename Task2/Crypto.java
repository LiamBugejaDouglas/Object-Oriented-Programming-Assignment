package Task2;

public class Crypto{

    //Private variables
    private String name;
    private float valueDollar;
    private String symbol;

    //Constructing Crypto with specified variables
    public Crypto(String name, float valueDollar, String symbol){

        this.name = name;
        this.valueDollar = valueDollar;
        this.symbol = symbol;
    }


    //Default Constructor
    public Crypto(){

    }

    //Setting the getter methods
    public String getName(){

        return name;
    }

    public float getValDollar(){

        return valueDollar;
    }

    public String getSymbol(){

        return symbol;
    }

    //Setting the setter methods
    public void setName(String name){

        this.name = name;
    }

    public void setValDollar(float valueDollar){

        this.valueDollar = valueDollar;

    }

    public void setSymbol(String symbol){

        this.symbol = symbol;
    }

    //Setting the toString method
    public String toString(){

        return "\nSymbol and name of coin: "+ symbol + " " + name + "\nMarket value of coin in Dollar: $" + valueDollar;
    }

}