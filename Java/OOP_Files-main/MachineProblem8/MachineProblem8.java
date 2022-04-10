
import java.io.*;

class FindArray {
    int[] arr = { 1, 2, 3, 4, 5 };

    void displayArray() {

        System.out.println("The exceptions are: ");
        try {
            System.out.println(arr[5]); // accesing unknown index
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e);
        }

        try {
            String arr2 = null; // to invoke NullPointer Error
            int length = arr2.length();
        } catch (NullPointerException e) {
            System.out.println(e);
        }

        try {
            float invalidDivision = 5 / 0;
            // arithmetic exception
            // Since arithemetic exception
            // is under the RuntimeException
            // it will arithmetic exception
        } catch (RuntimeException e) {
            System.out.println(e);
        }

        System.out.println("\nThe content of the array are: ");
        for (int i : arr) {
            System.out.println(i);
        }

        System.out.println("\nSample use of assertion: \n");
        int age = 17;
        assert age >= 18 : "Not in legal age";
        System.out.println("The age is: " + age);

    }
}

public class MachineProblem8 {

    public static void main(String args[]) {

        FindArray findArray = new FindArray();
        findArray.displayArray();

    }
}