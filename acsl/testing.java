import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class testing {
    public static void main(String[] args)throws IOException{

      /*
        Random rand = new Random();
        Double[] rangeOf10 = new Double[10];
        Double numberOfTrials = 100.0;
        //sets entire array to 0
        for(int i = 0 ; i < 10; i++){
            rangeOf10[i] = 0.0;
        }

        for(int i = 0; i < numberOfTrials; i++){

        }
        int min = 5;
        int max = 15;
        int number = rand.nextInt(max - min - 1) + min;
        

        for(int i = 0; i < 10; i++){
            System.out.println(rangeOf10[i]/numberOfTrials);
        }
        

        int tries = 1;
        Random rand = new Random();
        int randomNumber;
        do {
          randomNumber = rand.nextInt(6);
          System.out.println(randomNumber);
        }
        while (randomNumber != 5);

        

        File myObj = new File("filename.txt");
        if (myObj.createNewFile()) {
          System.out.println("File created: " + myObj.getName());
        } else {
          System.out.println("File already exists.");
        }
        

        FileWriter writer = new FileWriter("filename.txt");
        writer.write("Hello World");
        writer.close();
        

        File my2ndObj = new File("filename.txt");
        Scanner myReader = new Scanner(my2ndObj);
        while (myReader.hasNextLine()) {
          String data = myReader.nextLine();
          System.out.println(data);
        }
        */
        Scanner input = new Scanner(System.in);
        String[] arr = input.nextLine().split(" ");
        Random rand = new Random();
        int previous = 0;
        for(int i = 0; i < 20; i++){
          int randomed = rand.nextInt(arr.length);
          while(previous == randomed){
            randomed = rand.nextInt(arr.length);
          }
          System.out.println(arr[randomed]);
          previous = randomed;
          input.nextLine();
        }

    }
}
