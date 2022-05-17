import java.util.Random;
import java.util.Scanner;

public class DiceGame {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Random rand = new Random();
        String guess;
        int guessAsNumber;
        int score = 0;
        do{
            guess = input.nextLine();
            guessAsNumber = Integer.parseInt(guess);
            score++;
        }while(guessAsNumber != rand.nextInt(6));
        System.out.println("You got it! It took you " + score + " guesses.");
    }
}
