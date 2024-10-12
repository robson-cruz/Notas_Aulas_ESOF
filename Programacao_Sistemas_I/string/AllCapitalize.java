public class AllCapitalize {
    /**
     * Capitalize all words into a given string
     * @param args
     */
    public static void main(String[] args) {
        final String myStr = "hello java language";
        
        // split the string into words
        final String[] strArray = myStr.split("\\s+");
        final var capStr = new StringBuilder();

        // Iterate over ech word
        for (String word : strArray) {
            // Capitalize the first character and append to the rest of the word
            String capitalizedWord = word.substring(0, 1).toUpperCase() + word.substring(1, word.length());
            capStr.append(capitalizedWord).append(" ");
        }

        // Print the string capitalized
        System.out.println(capStr.toString().trim());
    }
}
