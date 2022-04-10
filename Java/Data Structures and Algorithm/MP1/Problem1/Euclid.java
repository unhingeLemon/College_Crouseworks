//OUR IMPORTS
import java.util.Scanner;

class Euclid {

    

    //Main program
    public static void main(String[] args){
   

        System.out.println("::::Greatest Common Denominator::::");
        System.out.println("    Using Euclidian Algorithm");

        //initialize the vars
        int a = 0;
        int b = 0;
        int rem = 0;
        int mult = 0;
        Boolean loop;

        // user inputs with validation
        do{
            try {
                //initialize and reinitialize the
                //scanner inside so that we will not be trapped
                //in the infinite loop
                Scanner in = new Scanner(System.in);

                System.out.print("\n\nEnter 1st number:");
                a = in.nextInt();
                if(a < 0) throw new Exception("Error!");
                System.out.print("Enter 2nd number:");
                b = in.nextInt();
                if(b < 0) throw new Exception("Error!");
               
                
                loop = false;
            } catch (Exception e) {
                System.out.print("Invalid Input!");
                loop = true;
                a = 0;
                b = 0;
            }
            

   

        }while(loop);
 

        // make sure that 2nd number is the biggest
        // else just swap
        if(a>b){
            int t = b;
            b = a;
            a = t;
        }
        System.out.print("\n\n");


        //constructing the logic
        while(true){
            //mult will be the q in the formula
            mult = b / a;
            // rem is for remainder
            rem = b % a;
            System.out.println(b + " = " + a + " * " + mult + " + " + rem);
            //swap values
            b = a;
            a = rem;
            if(a == 0){
                // Output the result
                // b will become the remainder after the swap
                System.out.println("\nThe GCD is: " + b);
                break;
            }

        }
       





    }
}