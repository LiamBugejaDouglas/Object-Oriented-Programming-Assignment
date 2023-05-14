package Task2;
import java.util.*;

public class OrderBook{

    //Creating a private ArrayList
    private ArrayList <Order> orders;

    //Constructing a order ArrayList
    public OrderBook(){

        orders = new ArrayList <Order>();
    }

    //Get size of order ArrayList
    public int getSize(){

        return orders.size();
    }

    //Add order to ArrayList
    public void addOrder(Order order){

        orders.add(order);
    }

    //Remove order from ArrayList
    public void removeOrder(Order order){

        orders.remove(order);
    }

    //Clear ArrayList
    public void clearOrderBook(){

        orders.clear();
    }

    //Get transaction by transaction ID
    public Order getTransactionByID(String transID){

        for(Order order : orders){
            if(order.getTransID().equals(transID)){

                return order;
            }
        }

        return null;
    }

    //Print all orders in ArrayList
    public void printOrders(){

        for(Order order : orders){

            System.out.println(order.toString());
        }
    }

    //Print all buy orders in ArrayList
    public void printBuyOrders(){

        for(Order tempOrder : orders){
            if(tempOrder.getFunction().equals("Buy")){

                System.out.println(tempOrder.toString());
            }
        }
    }

    //Print all sell orders in ArrayList
    public void printSellOrders(){

        for(Order tempOrder : orders){
            if(tempOrder.getFunction().equals("Sell")){

                System.out.println(tempOrder.toString());
            }
        }
    }

    public void setTotal(){

        for(Order tempOrder: orders){

            float total = tempOrder.getQuantity() * tempOrder.getSellBuyPrice();
            tempOrder.setTotal(total);
        }
    }

    public void sort(){

        Collections.sort(orders, Order.OrderPrice);
    }

    public void setTransactions(){

        for(Order tempOrder1: orders){
            if(tempOrder1.getFunction().equals("Sell")){

                for(Order tempOrder2: orders){
                    if(tempOrder2.getFunction().equals("Buy")){

                        if(tempOrder1.getSymbol().equals(tempOrder2.getSymbol())){

                            if(tempOrder1.getType().equals("Market") && tempOrder2.getType().equals("Market")){

                                if((tempOrder1.getQuantity()-tempOrder2.getQuantity()>=0f || tempOrder2.getQuantity()-tempOrder1.getQuantity()>=0f) && (tempOrder1.getQuantity()!=0f || tempOrder2.getQuantity()!=0f)){

                                    if(tempOrder1.getQuantity() > tempOrder2.getQuantity()){

                                        tempOrder1.setVolumeExecuted(tempOrder2.getTotal());
                                        tempOrder2.setVolumeExecuted(tempOrder2.getTotal());
                                        
                                        float setQuantity = tempOrder1.getQuantity() - tempOrder2.getQuantity();

                                        tempOrder1.setQuantity(setQuantity);
                                        tempOrder2.setQuantity(0f);

                                        tempOrder1.setStatus("Partial");
                                        tempOrder2.setStatus("Complete");
                                    }
                                    else if(tempOrder1.getQuantity()<tempOrder2.getQuantity()){

                                        tempOrder1.setVolumeExecuted(tempOrder1.getTotal());
                                        tempOrder2.setVolumeExecuted(tempOrder1.getTotal());

                                        float setQuantity = tempOrder2.getQuantity() - tempOrder1.getQuantity();

                                        tempOrder1.setQuantity(0f);
                                        tempOrder2.setQuantity(setQuantity);

                                        tempOrder1.setStatus("Complete");
                                        tempOrder2.setStatus("Partial");
                                    }
                                    else{

                                        tempOrder1.setVolumeExecuted(tempOrder1.getTotal());
                                        tempOrder2.setVolumeExecuted(tempOrder2.getTotal());

                                        tempOrder1.setQuantity(0f);
                                        tempOrder2.setQuantity(0f);

                                        tempOrder1.setStatus("Complete");
                                        tempOrder2.setStatus("Complete");
                                    }
                                }
                                
                            }
                            else if(tempOrder1.getType().equals("Limit") && tempOrder2.getType().equals("Limit")){

                                if(tempOrder1.getSellBuyPrice()-tempOrder2.getSellBuyPrice()<=0f){

                                    if((tempOrder1.getQuantity()-tempOrder2.getQuantity()>=0f || tempOrder2.getQuantity()-tempOrder1.getQuantity()>=0f) && (tempOrder1.getQuantity()!=0f || tempOrder2.getQuantity()!=0f)){

                                        if(tempOrder1.getQuantity() > tempOrder2.getQuantity()){

                                            tempOrder1.setVolumeExecuted(tempOrder2.getTotal());
                                            tempOrder2.setVolumeExecuted(tempOrder2.getTotal());
                                            
                                            float setQuantity = tempOrder1.getQuantity() - tempOrder2.getQuantity();
    
                                            tempOrder1.setQuantity(setQuantity);
                                            tempOrder2.setQuantity(0f);
    
                                            tempOrder1.setStatus("Partial");
                                            tempOrder2.setStatus("Complete");
                                        }
                                        else if(tempOrder1.getQuantity()<tempOrder2.getQuantity()){
    
                                            tempOrder1.setVolumeExecuted(tempOrder1.getTotal());
                                            tempOrder2.setVolumeExecuted(tempOrder1.getTotal());
    
                                            float setQuantity = tempOrder2.getQuantity() - tempOrder1.getQuantity();
    
                                            tempOrder1.setQuantity(0f);
                                            tempOrder2.setQuantity(setQuantity);
    
                                            tempOrder1.setStatus("Complete");
                                            tempOrder2.setStatus("Partial");
                                        }
                                        else{
    
                                            tempOrder1.setVolumeExecuted(tempOrder1.getTotal());
                                            tempOrder2.setVolumeExecuted(tempOrder2.getTotal());
    
                                            tempOrder1.setQuantity(0f);
                                            tempOrder2.setQuantity(0f);
    
                                            tempOrder1.setStatus("Complete");
                                            tempOrder2.setStatus("Complete");
                                        }
                                    }
                                }
                            }
                        }
                    } 
                }
            }
        }
    }

    //Cancel incomplete orders
    public void cancelTransactions(){

        for(Order order: orders){

            if(order.getStatus().equals("Active") || order.getStatus().equals("Partial")){

                order.setStatus("Cancelled");
            }
        }
    }
}