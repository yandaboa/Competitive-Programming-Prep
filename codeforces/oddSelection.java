import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class oddSelection {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(input.readLine());
        for(int i = 0; i < testCases; i++){
            
        }
    }
}
// count the number of even and odd numbers in the array, make sure there are enough even + (double odd pairs) + 1 odd to make it an odd sequence
// even and an odd pair keep the parity the same throughout.