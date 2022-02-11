import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class oddSelection2 {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int testCaseN = Integer.parseInt(input.readLine());
        for(int i = 0; i < testCaseN; i++){
            StringTokenizer line1 = new StringTokenizer(input.readLine());
            StringTokenizer line2 = new StringTokenizer(input.readLine());
            line1.nextToken();
            while(line2.hasMoreTokens()){
                
            }
        }   
    }
}