import java.util.Scanner;
import java.math.RoundingMode;
import java.text.DecimalFormat;

public class S1_Technical_A {

    // This is the code for calculating the interest
    // Basically in the loop this happens:
    // If the account balance is 500 then in the loop the interest is adding for 10
    // years:
    // 500,551,578,607 so on.
    // The compoundIn variable is the yearly,monthly, or daily
    static double calculate(double principal, double interest, int compoundIn) {
        double result = 0;
        // This for loop is for annual
        if (compoundIn == 0) {
            for (int i = 0; i < 10; i++) {
                result = principal;
                principal = result * (1 + (interest / 100));

            }
        } else {
            // This for loop is for daily and monthly
            for (int j = 0; j < 10 * compoundIn; j++) {
                result = principal;
                principal = result * (1 + (((interest / 100) / compoundIn)));

            }
        }

        return principal;
    }

    public static void main(String[] args) {

        // Initializing variables
        double interestRate = 0;
        double accntBalance = 0;
        Scanner sc = new Scanner(System.in);

        // To format the decimal places
        // The "#.##" means 2 decimal places
        DecimalFormat df = new DecimalFormat("#.##");
        // Ceiling - this causes the last given place to be rounded to its next number.
        df.setRoundingMode(RoundingMode.CEILING);

        // Loop to ask the user to use the program once more
        while (true) {

            // Getting the inputs from the user
            // The if else is used to validate the user's inputs
            System.out.print("Enter you Bank Account Balance: ");
            if (sc.hasNextDouble()) {
                accntBalance = sc.nextDouble();
            } else {
                System.out.println("Invalid input will now terminate.");
                break;
            }
            System.out.print("Enter the interest rate: ");
            if (sc.hasNextDouble()) {
                interestRate = sc.nextDouble();

            } else {
                System.out.println("Invalid input will now terminate.");
                break;
            }

            // Solving and printing the results
            // The df.format will format the numbers into 2 decimal places
            System.out.println("The value of the account in 10 years: ");
            System.out.println("Annual:  " + df.format(calculate(accntBalance, interestRate, 0)));
            System.out.println("Monthly: " + df.format(calculate(accntBalance, interestRate, 12)));
            System.out.println("Daily:   " + df.format(calculate(accntBalance, interestRate, 365)));

            // Asking the user to use to program again
            System.out.print("Do you want to try again? [y/n]: ");
            char askAgain = sc.next().charAt(0);

            if (askAgain == 'n' || askAgain == 'n') {
                System.out.println("Thank you for using this program!");
                break;
            }

        }

    }
}
