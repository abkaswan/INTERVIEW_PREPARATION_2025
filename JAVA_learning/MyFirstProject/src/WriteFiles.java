import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class WriteFiles {
    public void run(){
        // how to write a file using java (4 popular options)

        // FileWriter = Good for small or medium-sized text files.
        // BufferedWriter = Better performance for large amounts of text
        // PrintWriter = Best for structured data, like reports or logs
        // FileOutputStream = Best for binary files (e.g., images, audio files)
        String filePath = "test.txt";
        String textContent = "I like pizzaaaa!\n It is really good.\n Buy me pizza.";

        // or use below """ """ for multiline string if you have lots of text

        String textContent1 = """
                Roses are Red.
                Violets are blue
                Booty booty booty 
                ROCKIN' EVERYWhere
                """;
        // try and open up some resources -- try with resources
        // you can pick any location and put instead of test.txt
        try(FileWriter writer = new FileWriter(filePath);){
            writer.write(textContent1);
            System.out.println("File has been written.");
        }
        catch (FileNotFoundException e){
            System.out.println("Could not locate file location.");
        }
        catch(IOException e){
            System.out.println("Could not write file.");
        }

    }
}
