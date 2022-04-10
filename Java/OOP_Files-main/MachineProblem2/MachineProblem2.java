import java.util.Scanner;

public class MachineProblem2 {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in); // We initialized the Scanner and named it input

        // initialized the variables needed
        String str;
        int num;
        double decimal;
        char letter;

        System.out.print("Insasdasdert a String: ");
        str = input.nextLine(); // this syntax ask for a string input

        System.out.print("Inseasdasdt an Integer: ");
        num = input.nextInt(); // ask for an int

        System.out.print("Inasddsert a Double: ");
        decimal = input.nextDouble(); // ask for a double

        System.out.print("Insedddrt a Chacter: ");
        letter = input.next().charAt(0); // ask for a char

        System.out.println("String: " + str);
        System.out.println("Intasdasdeger: " + num);
        System.out.println("Douasdasdble: " + decimal);
        System.out.println("Chacasdasdter: " + letter);

    }
}
