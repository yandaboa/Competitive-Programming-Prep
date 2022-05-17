import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.function.IntUnaryOperator;

public class RockAndLever {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(input.readLine());
        StringBuilder sol = new StringBuilder();
        for(int i = 0; i < testCases; i++){
            HashMap<Integer, Long> numOfBinDigits = new HashMap<Integer, Long>();
            int arrSize = Integer.parseInt(input.readLine());
            StringTokenizer line = new StringTokenizer(input.readLine(), " ");
            long totalSum = 0;
            for(int j = 0; j < arrSize; j++){
                int numOfDigits = Integer.toBinaryString(Integer.parseInt(line.nextToken())).length();
                if(numOfBinDigits.keySet().contains(numOfDigits)){
                    totalSum += numOfBinDigits.get(numOfDigits);
                    numOfBinDigits.put(numOfDigits, numOfBinDigits.get(numOfDigits) + 1);
                } else {
                    numOfBinDigits.put(numOfDigits, (long) 1);
                }
            }
            sol.append(totalSum + "\n");
        }
        System.out.println(sol);
    }
}
