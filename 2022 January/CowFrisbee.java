import java.util.*;
import java.io.*;

public class CowFrisbee {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int numOfCows = Integer.parseInt(input.readLine());
        int[] cows = new int[numOfCows];
        long totalDistance = 0;
        int min = 0;
        StringTokenizer cowString = new StringTokenizer(input.readLine(), " ");

        for(int i  = 0; i < numOfCows; i++){
            cows[i] = Integer.parseInt(cowString.nextToken());
        }
        for(int i = 0; i < numOfCows - 1; i++){
            int j = i + 1;
            while(cows[i] > cows[j]){
                if(!(min > cows[j])){
                    min = cows[j];
                    totalDistance += j - i + 1;
                }
                j++;
            }
            totalDistance += j - i + 1;
            min = 0;
        }
        System.out.println(totalDistance);
    }
}
