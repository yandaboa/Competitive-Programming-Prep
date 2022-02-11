import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class sameDifferences {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int numOfTestCases = Integer.parseInt(input.readLine());
        long[] sols = new long[numOfTestCases];
        for(int i = 0; i < numOfTestCases; i++){
            int arrLength = Integer.parseInt(input.readLine());
            StringTokenizer line = new StringTokenizer(input.readLine(), " ");
            HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
            long ans = 0;
            for(int j = 0; j < arrLength; j++){
                int value = Integer.parseInt(line.nextToken());
                if(map.containsKey(value - j)){
                    ans += map.get(value - j);
                    map.put(value - j, map.get(value - j) + 1);
                } else {
                    map.put(value - j, 1);
                }
            }
            sols[i] = ans;
        }
        for(int i = 0; i < sols.length; i++){
            System.out.println(sols[i]);
        }
    }
}