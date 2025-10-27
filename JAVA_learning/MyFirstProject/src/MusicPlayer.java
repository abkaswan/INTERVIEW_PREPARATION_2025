import javax.sound.sampled.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class MusicPlayer {
    public void play(){
        String filePath = "SampleYoutube.wav";
        File file = new File(filePath);

        // you can use try with resources if an object implements the auto closable interface , scanner and audioStream both do so we put it in try with resources as they will close by itself
        try(Scanner scanner = new Scanner(System.in);AudioInputStream audioStream = AudioSystem.getAudioInputStream(file);){

            // clip is like a music/sound player , allows you to load an audio file and then play,pause or reset the audio
            Clip clip = AudioSystem.getClip();
            clip.open(audioStream);

            String response = "";
            while(!response.equals("Q")){
                System.out.println("P = PLAY");
                System.out.println("S = STOP");
                System.out.println("R = RESET");
                System.out.println("Q = QUIT");
                System.out.print("Enter your choice : ");

                response = scanner.next().toUpperCase();

                switch (response){
                    case "P" -> clip.start();
                    case "S" -> clip.stop();
                    case "R" -> clip.setMicrosecondPosition(0);
                    case "Q" -> clip.close();
                    default -> System.out.println("Invalid choice!");
                }

            }
        }
        catch (FileNotFoundException e){
            System.out.println("Could not locate file.");
        }
        catch (UnsupportedAudioFileException e){
            System.out.println("Audio file is not supported.");
        }
        catch (LineUnavailableException e){
            System.out.println("Unable to access audio resource.");
        }
        catch (IOException e){
            System.out.println("Something went wrong!");
        }
        finally {
            System.out.println("Bye.");
        }

    }
}
