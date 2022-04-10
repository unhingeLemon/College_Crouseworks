import java.util.Scanner;
import java.io.*;

public class S3_Technical_B {

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int shiftSize;
        System.out.print("Shift Size: ");
        shiftSize = input.nextInt();

        try {
            File file = new File("file.txt");
            if (file.createNewFile()) {
                System.out.println("File created: " + file.getName());
            } else {
                System.out.println("File already exists.");
            }

            FileWriter writer = new FileWriter("file.txt");
            writer.write("Hello");
            writer.close();

            // read from a file
            Scanner reader = new Scanner(file);
            String data = "";
            // store it in a data var
            while (reader.hasNextLine()) {
                data = reader.nextLine();
            }
            System.out.println("Message read from the file: " + data);

            // convert the data into bytes
            byte b[] = data.getBytes();
            String convertedString = "";

            // add the shift size to the bytes
            for (int i = 0; i < b.length; i++) {
                b[i] = (byte) (b[i] + shiftSize);
            }
            // convert the bytes to char and then
            // append it to string
            for (int i = 0; i < b.length; i++) {
                convertedString += (char) b[i];
            }

            System.out.println("Encrypted message: " + convertedString);

            reader.close();

        } catch (Exception e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

}
