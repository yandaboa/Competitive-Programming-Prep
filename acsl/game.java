import java.util.Random;
import java.util.Scanner;

public class game {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Random rand = new Random();
        String guess;
        int guessAsInteger;
        int guessNumbers = 1;
        do{
            guess = input.nextLine();
            guessAsInteger = Integer.parseInt(guess);
            System.out.println(guessNumbers);
            guessNumbers++;
        } while(guessAsInteger != rand.nextInt(6) + 1);
    }
}
