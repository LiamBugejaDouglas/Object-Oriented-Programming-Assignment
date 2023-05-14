package Task2;

public class Test {
    public static void main(String [] args){

        //Instantiating 3 different crypto types
        Crypto c1 = new Crypto("Bitcoin", 35000f, "B");
        Crypto c2 = new Crypto("Ether", 3000f, "E");
        Crypto c3 = new Crypto("Cardano", 500f, "C");

        //Instantiating 2 Traders and 1 admin
        Trader t1 = new Trader("1324TR", "Jack", "Galea",1900.12f, 12f, 21f, 78f, true);
        Trader t2 = new Trader("1719TR", "Daniel", "Grech", 10000.02f, 15f,12f,98f, true);
        Admin a1 = new Admin("1324AD", "AD001","Liam","Douglas");

        //Instantiating 5 orders
        //                           transID, userID,   function, type, quantity,  name,     valueDollar, sellBuyPrice, total, symbol, volumeExecuted, status  

        Order o1 = new Order("OB001", t1.getID(), "Buy", "Market", 5f, c1.getName(), c1.getValDollar(), c1.getValDollar(), 0f, c1.getSymbol(), 0f, "Active");
        Order o2 = new Order("OB002", t2.getID(), "Sell", "Market", 5f, c1.getName(), c1.getValDollar(), c1.getValDollar(), 0f, c1.getSymbol(), 0f, "Active");
        Order o3 = new Order("OB003", t2.getID(), "Sell", "Limit", 20f, c3.getName(), c3.getValDollar(), 600f, 0f, c3.getSymbol(), 0f, "Active");
        Order o4 = new Order("OB004", t1.getID(),"Buy", "Limit", 10f, c3.getName(), c3.getValDollar(), 700f, 0f, c3.getSymbol(), 0f, "Active");

        Order o5 = new Order("OB005", t2.getID(),"Buy", "Market", 3f, c2.getName(), c2.getValDollar(), c2.getValDollar(), 0f, c2.getSymbol(), 0f, "Active");
        
        Order o6 = new Order("OB006", t1.getID(),"Buy", "Limit", 5f, c3.getName(), c3.getValDollar(), 700f, 0f, c3.getSymbol(), 0f, "Active");

        //Instantiating Users and Orders ArrayLists
        Users us = new Users();
        OrderBook or = new OrderBook();

        //Add traders and admins in Users ArrayList
        us.addPerson(t1);
        us.addPerson(t2);
        us.addPerson(a1);

        //Add orders in Order ArrayList
        or.addOrder(o1);
        or.addOrder(o2);
        or.addOrder(o3);
        or.addOrder(o4);
        or.addOrder(o5);
        or.addOrder(o6);

        //Setting the total transaction value
        or.setTotal();

        //Printing Users
        us.printUsers();

        //Printing Orders.
        or.printOrders();

        //Sorting by price acsending order
        or.sort();

        //or.printOrders();

        //Completing transactions
        or.setTransactions();

        //or.printOrders();
        
        //Cancelling incomplete orders
        or.cancelTransactions();

        //Printing orders
        or.printOrders();
    }
}