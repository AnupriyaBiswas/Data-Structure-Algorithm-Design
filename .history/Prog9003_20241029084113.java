public class Prog9003
{
       static class NoVowelException extends Exception {
        public NoVowelException(String message) {
            super(message);
        }
    }

    // Method to check for vowels
    public static void checkVowels(String str) throws NoVowelException {
        // Convert the string to lowercase for easier comparison
        str = str.toLowerCase();
        
        // Check if the string contains any vowels
        if (!(str.contains("a") || str.contains("e") || str.contains("i") || str.contains("o") || str.contains("u"))) {
            throw new NoVowelException("The string does not contain any vowels.");
        } else {
            System.out.println("The string contains vowels.");
        }
    }

    // Main method to test the checkVowels method
    public static void main(String[] args) {
        String input = "sky";
        
        try {
            checkVowels(input);
        } catch (NoVowelException e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}
