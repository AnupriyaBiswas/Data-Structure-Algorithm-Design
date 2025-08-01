//Write a Java program to create a method that takes a string as input and throws an exception is the string does not contain vowels.

import java.io.*;
public class Prog9003
{
       static class NoVowelException extends Exception {
        public NoVowelException(String message) {
            super(message);
        }
    }

    // Method to check for vowels
    public static void checkVowels(String str) throws NoVowelException 
    {
        str = str.toLowerCase();
    
        if (!(str.contains("a") || str.contains("e") || str.contains("i") || str.contains("o") || str.contains("u"))) {
            throw new NoVowelException("The string does not contain any vowels.");
        } else {
            System.out.println("The string contains vowels.");
        }
    }

    // Main method to test the checkVowels method
    public static void main(String[] args)throws IOException
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        String input;
        System.out.print("Enter String : ");
        input = br.readLine();
        
        try {
            checkVowels(input);
        } catch (NoVowelException e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}
