import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.StringTokenizer;
import java.util.function.IntUnaryOperator;

import javax.swing.plaf.ColorUIResource;

public class SleepingInClass {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int testCaseNumber = Integer.parseInt(input.readLine());
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < testCaseNumber; i++){
            int arrSize = Integer.parseInt(input.readLine());
            int[] arr = new int[arrSize];
            StringTokenizer line = new StringTokenizer(input.readLine(), " ");
            int sum = 0;
            int max = Integer.MIN_VALUE;
            int b = 0;
            while(line.hasMoreTokens()){
                int curr = Integer.parseInt(line.nextToken());
                arr[b] = curr;
                sum += curr;
                max = Math.max(curr, max);
                b++;
            }
            if(max == 0){
                sb.append(0 + "\n");
            } else {
                for(int j = max; j <= sum; j++){
                    if(sum%j == 0){
                        boolean ifTrue = true;
                        int currSum = 0;
                        for(int x = 0; x < arr.length; x++){
                            currSum += arr[x];
                            if(currSum > j){
                                ifTrue = false;
                            }
                            if(currSum == j){
                                currSum = 0;
                            }
                        }
                        if(ifTrue){
                            sb.append(arrSize - (sum/j) + "\n");
                            break;
                        }
                    }
                } 
            }
        }
        sb.delete(sb.length() - 1, sb.length());
        System.out.println(sb);
    }
}
