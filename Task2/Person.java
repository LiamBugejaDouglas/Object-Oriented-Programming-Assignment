package Task2;

//Abstract class Person, used so admins and traders can be subclassed by it.
public abstract class Person{

    //Private variables
    private String ID;
    private String name;
    private String surname;
    
    //Constructing Person with specified variables
    public Person(String ID, String name, String surname){

        this.ID = ID;
        this.name = name;
        this.surname = surname;
    }

    //Default Constructor
    public Person(){

    }

    //Setting the getter methods
    public String getID(){

        return ID;
    }

    public String getName(){

        return name;
    }

    public String getSurname(){

        return surname;
    }

    //Setting the setters methods
    public void setID(String ID){

        this.ID = ID;
    }

    public void setName(String name){

        this.name = name;
    }

    public void setSurname(String surname){

        this.surname = surname;
    }

    //Setting the toString method.
    public String toString(){

        return "\nID: " + ID + "\nName: " + name + "\nSurname: " + surname;
    }
}
