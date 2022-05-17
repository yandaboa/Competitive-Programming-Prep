import java.util.Random;

public class program {
    public static void main(String[] args){
        Random rand = new Random(); //new random object

        int randomNumber = rand.nextInt(3);
        if(randomNumber == 0){
            System.out.println("ROCK");
        } else if (randomNumber == 1){
            System.out.println("SCISSORS");
        } else {
            System.out.println("PAPER");
        }        
    }
}
