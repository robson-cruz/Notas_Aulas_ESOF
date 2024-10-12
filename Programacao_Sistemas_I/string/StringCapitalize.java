public class StringCapitalize {
    /**
     * @param args
     */
    public static void main(String[] args) {
        String myStr = "hello";

        // Convert the first caracter to uppercase
        String firstLetter = String.valueOf(myStr.charAt(0)).toUpperCase();
        // Get the rest of the string
        String subString = myStr.subSequence(1, myStr.length()).toString();

        // Print the string capitalized
        System.out.println(firstLetter + subString);
    }
}
