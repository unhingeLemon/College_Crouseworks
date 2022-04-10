public class S1_Technical_B {

    public static void main(String[] args) {
        // Since the experiment provided us the data
        // We will not ask the user for inputs
        // We will initialize the provided data in 2D array
        String student[][] = { { "Peter", "75", "77" }, { "Clark", "78", "80" }, { "Logan", "82", "84" } };

        // This for loop will just output the data above
        // the 'i' will iterate through the rows of the rows
        // I provided the columns position because
        // we need to specifically output the grades and averages
        for (int i = 0; i < 3; i++) {
            System.out.println("Student Name: " + student[i][0]);
            System.out.println("Grade: " + student[i][1]);
            System.out.println("Average: " + student[i][2] + "\n");
        }
    }
}
