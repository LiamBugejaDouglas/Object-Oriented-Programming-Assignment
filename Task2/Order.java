package Task2;
import java.util.Comparator;

//OrderBook class subclass of Crypto
public class Order extends Crypto{

    //Private varaibles
    private String transID;
    private String userID;
    private String function;
    private String type;
    private float quantity;
    private float sellBuyPrice;// ask bid
    private float total;
    private float volumeExecuted;
    private String status;

    //Constructing OrderBook with specified variables
    public Order(String transID, String userID, String function, String type, float quantity, String name, float valueDollar, float sellBuyPrice, float total, String symbol, float volumeExecuted, String status){

        //super keyword used to call parent class method
        super(name, valueDollar, symbol);
        this.transID = transID;
        this.userID = userID;
        this.function = function;
        this.type = type;
        this.quantity = quantity;
        this.sellBuyPrice = sellBuyPrice;
        this.total = total;
        this.volumeExecuted = volumeExecuted;
        this.status = status;

    }

    //Default constructor
    public Order(){

    }

    //Setting the getter methods
    public String getTransID(){

        return transID;
    }

    public String getUserID(){

        return userID;
    }

    public String getFunction(){

        return function;
    }

    public String getType(){

        return type;
    }

    public float getQuantity(){

        return quantity;
    }

    public float getSellBuyPrice(){

        return sellBuyPrice;
    }

    public float getTotal(){

        return total;
    }

    public float getVolumeExecuted(){

        return volumeExecuted;
    }

    public String getStatus(){

        return status;
    }

    //Setting the setter methods
    public void setTransID(String transID){

        this.transID = transID;
    }

    public void setUserID(String userID){

        this.userID = userID;
    }

    public void setFunction(String function){

        this.function = function;
    }

    public void setType(String type){

        this.type = type;
    }

    public void setQuantity(float quantity){

        this.quantity = quantity;
    }

    public void setSellBuyPrice(float sellBuyPrice){

        this.sellBuyPrice = sellBuyPrice;
    }

    public void setTotal(float total){

        this.total = total;
    }

    public void setVolumeExecuted(float volumeExecuted){

        this.volumeExecuted= volumeExecuted;
    }

    public void setStatus(String status){

        this.status = status;
    }

    //Setting the toString method
    public String toString(){

        //supr keyword used to call parent class method
        return "\nTransID: " + transID + "\nFunction: " + function + "\nType: " + type + super.toString() + "\nQuantity: " + quantity + "\nSell/Buy Price of 1 coin: $" + sellBuyPrice + "\nTotal Price in Dollar: $" + total + "\nVolume Executed: $" + volumeExecuted + "\nStatus: " + status; 
    }

    public static Comparator<Order> OrderPrice = new Comparator<Order>(){

        public int compare(Order o1, Order o2){

            float OrderO1 = o1.getTotal();
            float OrderO2 = o2.getTotal();

            int final1 = (int) OrderO1;
            int final2 = (int) OrderO2;

            return final1-final2;
        }
    };
}