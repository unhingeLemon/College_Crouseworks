import java.io.*;
import java.util.Scanner;

public class S3_Technical_A {

    public static void main(String args[]) {
        try {

            File file = new File("file.txt");

            // create the file
            if (file.createNewFile()) {
                System.out.println("File created: " + file.getName() + "\ncontinuing...\n");

            } else {
                System.out.println("File already exists. continuing...\n");
            }

            FileOutputStream fos = new FileOutputStream(file);

            Integer c = 65;

            // make the integer to string
            // so that we can use the getByte method
            // if we did not do this
            // this will just output
            // the ASCII value of 65
            String converted = c.toString();

            // Since fos only accept bytes we
            // need to convert it

            byte b[] = converted.getBytes();

            fos.write(b);

            // scanner
            Scanner reader = new Scanner(file);

            // read the line from fos
            while (reader.hasNextLine()) {
                String data = reader.nextLine();
                System.out.println(data);
            }

            // remember to close it

            fos.close();
            reader.close();

            // if any error we catch it
        } catch (Exception e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

}
