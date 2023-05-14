package Task2;

//Admin subclass of Person
public class Admin extends Person{

    private String adminID;
    //Constructing Admin with specified variables
    public Admin(String ID, String adminID, String name, String surname){

        //super keyword used to call parent class method
        super (ID, name, surname);
        this.adminID=adminID;
    }

    //Default Constructor
    public Admin(){

    }

    //Getters
    
    public String getAmdinID(){

        return adminID;
    }

    //Setters

    public void setAdminID(String adminID){

        this.adminID=adminID;
    }

    //Setting the the toString()
    public String toString(){

        //super used to call parent class method.
        return "AdminID: " + adminID + super.toString();
    }
}