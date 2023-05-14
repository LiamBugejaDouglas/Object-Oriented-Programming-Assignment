package Task2;

import java.util.*;

public class Users {
    
    //Creating a private ArrayList
    private ArrayList <Person> persons;

    //Constructing a persons ArrayList
    public Users(){

        persons = new ArrayList<Person>();
    }

    //Get size of ArrayLsit
    public int getSize(){

        return persons.size();
    }

    //Add person to ArrayLsit
    public void addPerson(Person person){

        persons.add(person);
    }

    //Remove person from ArrayLsit
    public void removePerson(Person person){

        persons.remove(person);
    }

    //Clear persons ArrayList
    public void clearPersons(){

        persons.clear();
    }

    //Print person by index
    public void getPerson(int i){

        System.out.println(persons.get(i));
    }

    //Get person by index
    public Person getPersonByIndex(int i){

        return persons.get(i);
    }

    //Print persons in the ArrayList of type Trader
    public void printTraders(){

        for(Person tempPerson: persons){
            if(tempPerson instanceof Trader){

                System.out.println(tempPerson.toString());
            }
        }
    }

    //Print persons in ArrayList of type Admin
    public void printAdmins(){

        for(Person tempPerson: persons){
            if(tempPerson instanceof Admin){

                System.out.println(tempPerson.toString());
            }
        }
    }

    //Print all users in ArrayList
    public void printUsers(){

        for(Person person: persons){

            System.out.println(person.toString());
        }
    }

    //Get user by variable ID
    public Person getUserbyID(String ID){

        for(Person person : persons){

            if(person.getID().equals(ID)){

                return person;
            }
        }

        return null;
    }
}
