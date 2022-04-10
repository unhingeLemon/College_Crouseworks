
import java.util.*;
import java.io.*;
import java.sql.*;

//SCHEMA 

//FLIGHT DATA SCHEMA---
// int flightCode,
// String flyFrom,
// String flyTo,
// String time,
// double price


//CUSTOMER DATA SCHEMA
// customer ID
// Number of:
	// 	child
	// 	adult
	// 	infants
// Total Passengers
// GrandTotal

//These will data will come from flight data:
// flightCode
// flyfrom
// flyto
// Time and date of flight





public class Backend {
    // This will be the accesor ng front end
    // They just need to instantiate the Backend class
    // Backend.flightDatas.LinkedListOperations
    // Backend.customerFlightData.LinkedListOperations
    // Backend.addFlight()
    // Backend.createFlight()
    // Backend.customerAuth.register
    // Backend.customerAuth.register
    public ArrayList<flightData> flightDatas = new ArrayList<flightData>();
    public ArrayList<reservation> reservations = new ArrayList<reservation>();
    public ArrayList<userSchema> userSchemas = new ArrayList<userSchema>();
    
   
     
 

    public String[][] populateArray(){
        String[][] arr1 = new String[flightDatas.size()][5];
        int j = 0;
        Iterator<flightData> iter = flightDatas.iterator();
        while(iter.hasNext()){
            System.out.println("wew");
            flightData f =  iter.next();
            arr1[j][0] = String.valueOf(f.flightCode);
            arr1[j][1] = f.flyFrom;
            arr1[j][2] = f.flyTo;
            arr1[j][3] = f.time;
            arr1[j][4] = Double.toString(f.price);
            j++;
        }
        return arr1;
    }
    
    public String[][] populateMyFlights(String custId){
        flightDatas.removeAll(flightDatas);
        reservations.removeAll(reservations);
        readFiles();
        
        String[][] arr1 = new String[reservations.size()][5];
        
        
       
        reservation f;
        int i = 0;
        int rows=0;
        while(reservations.size() > i){
            
            f =  reservations.get(i);
            if(custId.equals(f.customerId)){
                arr1[rows][0] = f.reservationCode;
                flightData z = getFlightData(f.flightCode);
                arr1[rows][1] = z.flyFrom;
                arr1[rows][2] = z.flyTo;
                arr1[rows][3] = z.time;
                arr1[rows][4] = f.grandTotal;
                rows++;
            } 
        
            
            i++;
        }
        return arr1;
    }
    
    
    
    public void readFiles(){
        // Read the txt. file and store it to the linked lists
        
        
        // for flight list
        try {
          File fileFlight = new File("src\\main\\java\\flightData.txt");
          Scanner reader = new Scanner(fileFlight);
       
          while (reader.hasNextLine()) {
              String code = reader.nextLine();
              String from = reader.nextLine();
              String to = reader.nextLine();
              String time = reader.nextLine();
              double price = Double.parseDouble(reader.nextLine());
              flightData newData = new flightData( code,from,to,time,price);
              flightDatas.add(newData);
        }

        } catch (Exception e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        
        
        // for customer list
        
       try {
       File fileReserve = new File("src\\main\\java\\reservationData.txt");
       Scanner reader = new Scanner(fileReserve);
       reader.nextLine();
       while (reader.hasNextLine()) {
          String reserveId = reader.nextLine();
          String custId= reader.nextLine();
           
            String totalPassengers = reader.nextLine();
            String grandTotal = reader.nextLine();
            // Just read the ID and convert it to flightData
            String flightCode = reader.nextLine();
            reservation newData = new reservation(reserveId, custId, totalPassengers,grandTotal,flightCode);
            reservations.add(newData);
        }

        } catch (Exception e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        
        
        
    }
    // FLIGHT DATA OPERATIONS

    public class flightData{
         String flightCode;
         String flyFrom;
         String flyTo;
         String time;
         double price;


        //constructor
        public flightData(
            String flightCode,
            String flyFrom,
            String flyTo,
            String time,
            double price
        ){

            this.flightCode = flightCode;
            this.flyFrom = flyFrom;
            this.flyTo = flyTo;
            this.time = time;
            this.price = price;
        }

    }
    
    public void createFlight(String code, String from,String to, String time, String price){
        flightDatas.removeAll(flightDatas);
        reservations.removeAll(reservations);
        readFiles();
        
        double p = Double.parseDouble(price);
        flightData newFlightData = new flightData(
            code,from,to,time,p
        );
        
        flightDatas.add(newFlightData);
        
         
        try {
            FileWriter myWriter = new FileWriter("src\\main\\java\\flightData.txt",true);
            myWriter.write("\n" +code + "\n" + from + "\n" + to+ "\n" + time+ "\n" + price);

            myWriter.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
          System.out.println("An error occurred.");
          e.printStackTrace();
        }
        //add to txt file
    }
    

    
   
    
    
    
  
    public flightData getFlightData(String code){
        flightDatas.removeAll(flightDatas);
        reservations.removeAll(reservations);
        readFiles();
        Iterator<flightData> i = flightDatas.iterator();
        flightData a;
        while(i.hasNext()){
            a = i.next();
            if(a.flightCode.equals(code)){
                return a;
            }
        }
        
        return null;
    }
    
    public boolean flightDoesExist(String code){
        flightDatas.removeAll(flightDatas);
        reservations.removeAll(reservations);
        readFiles();
         Iterator<flightData> i = flightDatas.iterator();
        while(i.hasNext()){
            if(i.next().flightCode.equals(code)){
                return true;
            }
        }
        
        return false;
        
    }
    
    
    public void deleteFlight(String code){
        flightDatas.removeAll(flightDatas);
        reservations.removeAll(reservations);
        readFiles();
        
       
        Iterator<flightData> p = flightDatas.iterator();
        flightData o;
        int i = 0;
        while(flightDatas.size() > i){
            
            if(flightDatas.get(i).flightCode.equals(code)){
                
                flightDatas.remove(i);
            } 
            i++;
        }
        
        i = 0;
        
        
               
        try {
            FileWriter myWriter = new FileWriter("src\\main\\java\\flightData.txt");
            while(flightDatas.size() > i){
            if(i == 0){
                myWriter.write(flightDatas.get(i).flightCode + "\n" + 
                    flightDatas.get(i).flyFrom + "\n" + flightDatas.get
                    (i).flyTo + "\n" + flightDatas.get(i).time+ "\n" 
                    + flightDatas.get(i).price);
            } else{
                myWriter.write("\n" +flightDatas.get(i).flightCode + "\n" + 
                    flightDatas.get(i).flyFrom + "\n" + flightDatas.get
                    (i).flyTo + "\n" + flightDatas.get(i).time+ "\n" 
                    + flightDatas.get(i).price);
            }
                  i++;
            }
            myWriter.close();
            System.out.println("Successfully wrote to the file.");
            } catch (IOException e) {
              System.out.println("An error occurred.");
              e.printStackTrace();
                }
     
     
        
       
        
        
        
        
        
      
        
    }
    
    
    
  
    
    
    
    //////////////////////////////////////////////////////////
    

    
    //CUSTOMER FLIGHT RESERVATION OPERATIONS
    
    public class reservation{
        private String reservationCode;
        private String customerId;

        private String totalPassengers;
        private String grandTotal;
        private String flightCode;


        //constructor
        public reservation(
            String reservationCode,
            String customerId,
            String totalPassengers,
            String grandTotal,
            String flightCode
 
        ){
            this.reservationCode = reservationCode;
            this.customerId = customerId;
            this.totalPassengers = totalPassengers;
            this.grandTotal = grandTotal;
            this.flightCode = flightCode;
        }
    }
    
    
    public void makeReservation(String reserveCode,String userId,String totalPassenger,
        String grandTotal, String flightCode)
    {
//        reservation newReservation = new reservation(
//          reserveCode, id, infants,child,adult,
//          totalPassenger,grandTotal, flight
//        );
//        
//        reservations.add(newReservation);
        
        try {
        FileWriter myWriter = new FileWriter("src\\main\\java\\reservationData.txt",true);
        myWriter.write("\n" +reserveCode + "\n" + userId + "\n" + totalPassenger+ "\n" + grandTotal+ "\n" + flightCode);
 
        myWriter.close();
        System.out.println("Successfully wrote to the file.");
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
        
        
    }
    
    
    public boolean deleteReservation(String reserveCode, String custId){
        this.readFiles();
        
        Iterator<reservation> i = reservations.iterator();
        while(i.hasNext()){
            reservation str = i.next();
            if(str.reservationCode.equals(reserveCode) && str.customerId.equals(custId)){
                
                reservations.remove(i.next());
              
                return true;
            }
        }
        return false;
       
    }
    
    public void writeToReserveFile(String rCode, String cId){
        Iterator<reservation> z = reservations.iterator();

        
        try{
            FileWriter myWriter = new FileWriter("src\\main\\java\\reservationData.txt");
            while(z.hasNext()){
                reservation str = z.next();
                if(str.reservationCode.equals(rCode) && str.customerId.equals(cId)){
                    str = z.next();
                } else{
                    myWriter.write("\n" +str.reservationCode + "\n" + str.customerId+ "\n" + str.totalPassengers+ "\n" + str.grandTotal+ "\n" + str.flightCode);
                }
                
                System.out.println("\n" +str.reservationCode + "\n" + str.customerId+ "\n" + str.totalPassengers+ "\n" + str.grandTotal+ "\n" + str.flightCode);
            }
            System.out.println("Successfully wrote to the file.");
            myWriter.close();
        }catch(IOException e){
            System.out.println("An error occurred.");
            e.printStackTrace();
            
        }
    }
    
    
    public reservation getReservation(int code){
        Iterator<reservation> i = reservations.iterator();
        while(i.hasNext()){
            if(i.next().reservationCode.equals(code)){
                return i.next();
            }
        }
        
        return null;
    }
    
    
    
    //////////////////////////////////////////////////////////
    
    
    // LOGIN SYSTEM OPERATIONS
    // ADMIN Authentication
    // CUSTOMER Authentication
    
     class userSchema{
            private String id;
            private String fullName;
            private String password;

            
            
            //setter
            public userSchema(String id, String name,String pass){
                this.id = id;
                this.fullName = name;
                this.password = pass;
            }
   }
    
    public class authentication{
        public void constructUsers(){
            try {
                File fileReserve = new File("src\\main\\java\\account.txt");
                Scanner reader = new Scanner(fileReserve);
                reader.nextLine();
                while (reader.hasNextLine()) {
                    String id = reader.nextLine();
                    String user= reader.nextLine();

                    String pass = reader.nextLine();
                    userSchema newData = new userSchema(id,user,pass);
                    userSchemas.add(newData);
                 }

            } catch (Exception e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
        }
        
        
        public void register(String user, String pass){
            userSchemas.removeAll(userSchemas);
            constructUsers();
            int size = userSchemas.size()+1;
            String id = String.valueOf(size);
            
            try {
            FileWriter myWriter = new FileWriter("src\\main\\java\\account.txt",true);
            myWriter.write("\n" +id + "-" + user + "\n" + user + "\n" + pass);

            myWriter.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
          System.out.println("An error occurred.");
          e.printStackTrace();
    }
            
            
                
                
        }
        
        public boolean checkUserIfExist(String user){
            try {
                File fileFlight = new File("src\\main\\java\\account.txt");
                Scanner reader = new Scanner(fileFlight);
         
                while (reader.hasNextLine()) {
                    String id = reader.nextLine();
                    System.out.println(id);
                    String user1 = reader.nextLine();
                    System.out.println(user1);
                    String pass1 = reader.nextLine();
                    System.out.println(pass1);
                    if(user.equals(user1)){
                        return true;
                    }
                }

        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
            return false;
         
        }
        
        public boolean login (String user, String password){
            try {
                File fileFlight = new File("src\\main\\java\\account.txt");
                Scanner reader = new Scanner(fileFlight);
                System.out.println(user + password);
                while (reader.hasNextLine()) {
                    String id = reader.nextLine();
                    System.out.println(id);
                    String user1 = reader.nextLine();
                    System.out.println(user1);
                    String pass1 = reader.nextLine();
                    System.out.println(pass1);
                    if(user.equals(user1)  && password.equals(pass1)){
                        return true;
                    }
                }

        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
         
      	return false;
        
        
        
        //login
    }

    }
    
}
