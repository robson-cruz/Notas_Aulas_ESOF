public class Temperature {
    /**
     * Celsius to Fahrenheit
     * 
     * @param celsius
     */
    public static void celsiusToFahrenheit(double celsius) {
        
        double fahrenheit = celsius * 1.8 + 32;
            
        System.out.print("Fahrenheit: " + fahrenheit);
    }
    
    /**
     * Fahrenheit to Celsius
     * 
     * @param fahrenheit
     */
    public static void fahrenheitToCelsius(double fahrenheit) {
        
        double celsius = (fahrenheit - 32) * 5 / 9;
            
        System.out.printf("Celsius: %.1f", celsius);
    }
    
    /**
     * Kelvin to Celsius
     * 
     * @param kelvin
     */
    public static void kelvinToCelsius(double kelvin) {
        
        double celsius = - kelvin - 273.15;
        
        System.out.printf("Celsius: %.1f", celsius);
    }

    /**
     * Celsius to Kelvin
     * 
     * @param celsius
     */
    public static void celsiusToKelvin(double celsius) {
        
        double kelvin = celsius + 273.15;
        
        System.out.printf("Kelvin: %.1f", kelvin);
    }
}