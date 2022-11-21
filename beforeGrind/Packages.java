import java.util.Scanner;
public class Packages {
   public static void main (String [] args) {
       Scanner numbers = new Scanner (System.in);
       System.out.print("Enter your number: ");
       int userInput = numbers.nextInt();
       System.out.println("You entered: " + userInput);

   }
}