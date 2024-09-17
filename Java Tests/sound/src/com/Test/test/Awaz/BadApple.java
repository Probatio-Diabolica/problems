package com.Test.test.Awaz;

import javax.sound.sampled.*;
import java.io.File;
import java.io.IOException;

public class BadApple {
    /*
    -> That's how we play audio in Java (wav,AU and AIF only)
    Java Sound supports a set of audio file formats, for example AU, AIF, and WAV1. M
    */ 
    public BadApple(String path){
        try{
            // Loading the audio file
            File audioFile = new File(path);
            //File audioFile = new File("resources/Title.wav");
            AudioInputStream audioStream = AudioSystem.getAudioInputStream(audioFile);

            // create a clip
            Clip clip = AudioSystem.getClip();

            clip.open(audioStream);

            // Audio starts
            clip.start();
            // Wait for the clip to finish playing            
            Thread.sleep(clip.getMicrosecondLength() / 1000);

            //close the audio
            clip.close();
            audioStream.close();

        }
        catch (UnsupportedAudioFileException | IOException | LineUnavailableException | InterruptedException e) {
            //->possible
            BadApple ba = new BadApple("resources/BA.wav");
        }
    }

    public static void main(String[] args) throws Exception {
        System.out.println("Bad Apple!");

        BadApple ba = new BadApple("resources/Spring.wav");
        ba = new BadApple("resources/Title.Wav");
        
        /* 
        try{
            // Loading the audio file
            File audioFile = new File("resources/BA.wav");
            //File audioFile = new File("resources/Title.wav");
            AudioInputStream audioStream = AudioSystem.getAudioInputStream(audioFile);

            // create a clip
            Clip clip = AudioSystem.getClip();

            clip.open(audioStream);

            // Audio starts
            clip.start();
            // Wait for the clip to finish playing            
            Thread.sleep(clip.getMicrosecondLength() / 1000);

            //close the audio
            clip.close();
            audioStream.close();

        }
        catch (UnsupportedAudioFileException | IOException | LineUnavailableException | InterruptedException e) {
            e.printStackTrace();
        }
        */


        
    }
}
