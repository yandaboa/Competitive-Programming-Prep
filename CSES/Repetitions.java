import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Repetitions {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String str = input.readLine();
        char curr = '/';
        int currLength = 0;
        int runningMax = Integer.MIN_VALUE;
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) != curr){
                curr = str.charAt(i);
                currLength = 1;
                runningMax = Math.max(runningMax, currLength);
            } else {
                currLength++;
                runningMax = Math.max(runningMax, currLength);
            }
        }
        System.out.println(runningMax);
    }
}
