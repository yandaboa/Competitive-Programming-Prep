import java.util.*;
import java.io.*;
import java.math.*;

public class AlternatingSubsequence {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(input.readLine());
        for(int i = 0; i < testCases; i++){
            input.readLine();
            StringTokenizer currLine = new StringTokenizer(input.readLine(), " ");
            int positiveMax = 0;
            int negativeMax = Integer.MIN_VALUE;
            boolean positiveInterval = false;
            String indexZero = currLine.nextToken();
            long workingSum = 0;
            if(Integer.parseInt(indexZero) > 0){
                positiveInterval = true;
                positiveMax = Integer.parseInt(indexZero);
            } else {
                negativeMax = Integer.parseInt(indexZero);
            }
            while (currLine.hasMoreTokens()){
                int next = Integer.parseInt(currLine.nextToken());
                if(positiveInterval && next < 0){
                    positiveInterval = false;
                    workingSum += positiveMax;
                    positiveMax = 0;
                    negativeMax = next;
                } else if (!positiveInterval && next > 0){
                    positiveInterval = true;
                    workingSum += negativeMax;
                    negativeMax = Integer.MIN_VALUE;
                    positiveMax = next;
                } else if (positiveInterval){
                    positiveMax = Math.max(positiveMax, next);
                } else {
                    negativeMax = Math.max(negativeMax, next);
                }
            }
            if(positiveInterval){
                workingSum += positiveMax;
            } else {
                workingSum += negativeMax;
            }
            System.out.println(workingSum);
        }
    }
}