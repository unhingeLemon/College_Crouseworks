//input -> number of elements, values to be search
//output -> position of the input number
import java.util.Scanner;



class LinearSearch
    {
    public static void main(String args[])
    {
        //variables
        int num, item, counter, array[];
        //input
        Scanner input = new Scanner(System.in);
        System.out.println("Enter number of elements ");
        num = input.nextInt();
        //create the array
        array= new int[num];
        System.out.println("Enter "+ num +"integers:");
        //input
        for (counter = 0; counter <num; counter++)
            array[counter]=input.nextInt();
        //Enter the search values
        System.out.println("Enter the number to search: ");
        item = input.nextInt();
        for (counter = 0; counter < num; counter ++){
            if(array[counter]==item)
            {
                System.out.println(item + "is present at position "+(counter+1));
                break;
            }
        }
        if (counter == num)
         System.out.println(item +"does not exist in the array");
        }
}