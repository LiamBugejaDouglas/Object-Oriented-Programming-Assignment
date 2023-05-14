package Task2;

public class Trader extends Person{
    
    //Private variables
    private float balanceDol;
    private float balanceBitc;
    private float balanceEther;
    private float balanceCard;
    private boolean isApproved;

    //Constructing Trader with specified variables
    public Trader (String ID, String name, String surname, float balanceDol, float balanceBitc, float balanceEther, float balanceCard, boolean isApproved){

        //super keyword used to call parent class method
        super (ID, name, surname);
        this.balanceDol = balanceDol;
        this.balanceBitc = balanceBitc;
        this.balanceEther = balanceEther;
        this.balanceCard = balanceCard;
        this.isApproved = isApproved;
    }

    //Default Constructor
    public Trader(){

    }

    //Setting the getter methods
    public float getBalanceDol(){

        return balanceDol;
    }

    public float getBalanceBitc(){

        return balanceBitc;
    }

    public float getBalanceEther(){

        return balanceEther;
    }

    public float getBalanceCard(){

        return balanceCard;
    }

    public boolean getisApproved(){

        return isApproved;
    }

    //Setting the setter methods
    public void setBalanceDol(float balanceDol){

        this.balanceDol = balanceDol;
    }

    public void setBalanceBitc(float balanceBitc){

        this.balanceBitc = balanceBitc;
    }

    public void setBalanceEther(float balanceEther){

        this.balanceEther = balanceEther;
    }

    public void setBalanceCard(float balanceCard){

        this.balanceCard = balanceCard;
    }

    public void setIsApproved(boolean isApproved){

        this.isApproved = isApproved;
    }

    //Setting the toString methods
    public String toString(){

        //super.toString calls tha parent class method
        return super.toString() + "\nBalance Dollar: $" + balanceDol + "\nBalance Bitcoin: B" + balanceBitc + "\nBalance Etherum: E" + balanceEther + "\nBalance Cardano: C" + balanceCard + "\nApproved by Admin: " + isApproved;
    }
}