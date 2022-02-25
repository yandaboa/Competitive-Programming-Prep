import java.io.BufferedReader;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class MissingNumber {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        boolean[] nums = new boolean[Integer.parseInt(input.readLine()) + 1];
        StringTokenizer line = new StringTokenizer(input.readLine(), " ");
        while(line.hasMoreTokens()){
            nums[Integer.parseInt(line.nextToken())] = true;
        }
        for(int i = 1; i < nums.length; i++){
            if(!nums[i]){
                System.out.println(i);
            }
        }
    }
}
