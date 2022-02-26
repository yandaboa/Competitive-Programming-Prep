import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class IncreasingArray {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(input.readLine());
        StringTokenizer line = new StringTokenizer(input.readLine(), " ");
        long previousElem = Integer.parseInt(line.nextToken());
        long operationsTotal = 0;
        while(line.hasMoreTokens()){
            long curr = Integer.parseInt(line.nextToken());
            if(curr < previousElem){
                operationsTotal = operationsTotal + previousElem - curr;
            } else {
                previousElem = curr;
            }
        }
        System.out.println(operationsTotal);
    }
}
