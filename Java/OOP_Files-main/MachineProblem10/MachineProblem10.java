
//IMPORTS:
import java.io.File;
import java.io.IOException;
import java.io.FileWriter;
import java.util.Scanner;

public class MachineProblem10 {

    static void fileShuffle(String source, String destination) {

        try {
            // create the source file
            File s = new File(source);
            if (s.createNewFile()) {
                System.out.println("File created: " + s.getName());

            } else {
                System.out.println("File already exists.");
            }

            // and then write on it
            System.out.println("Writing to the file...\n");
            FileWriter myWriter = new FileWriter(source);
            myWriter.write("Action is the foundational key to all success");
            myWriter.close();

            // Read the content of the source file
            // and put it in a variable data
            File readerObj = new File(source);
            Scanner myReader = new Scanner(readerObj);
            String data = null;
            while (myReader.hasNextLine()) {
                data = myReader.nextLine();
                System.out.println(data + '\n');
            }
            myReader.close();

            // create the destination file
            File d = new File(destination);
            if (d.createNewFile()) {
                System.out.println("File created: " + d.getName());
            } else {
                System.out.println("File already exists.");
            }

            // replacing all occurrences of spaces (' ') converted to underscores ('_').
            System.out.println("Replacing space with underscore...\n");
            String convertedText = "";
            for (int i = 0; i < data.length(); i++) {

                if (data.charAt(i) == ' ') {
                    convertedText += '_';
                } else {
                    convertedText += data.charAt(i);
                }
            }

            // and then write it on destination file
            FileWriter writer = new FileWriter(destination);
            writer.write(convertedText);
            writer.close();

            // Read the destination file
            System.out.println("The content of the destinaion file is: ");
            File destinationFile = new File(destination);
            Scanner destinationReader = new Scanner(destinationFile);
            while (destinationReader.hasNextLine()) {
                String destinationData = destinationReader.nextLine();
                System.out.println("\n" + destinationData);
            }
            destinationReader.close();

        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public static void main(String args[]) {
        fileShuffle("source.txt", "destination.txt");
    }
}