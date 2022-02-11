import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class oddSelection {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(input.readLine());
        for(int i = 0; i < testCases; i++){
            StringTokenizer line1 = new StringTokenizer(input.readLine(), " ");
            StringTokenizer line2 = new StringTokenizer(input.readLine(), " ");
            line1.nextToken();
            int chooseThisNum = Integer.parseInt(line1.nextToken());
            int oddCount = 0;
            int evenCount = 0;
            while(line2.hasMoreTokens()){
                if(Integer.parseInt(line2.nextToken())%2 == 0){
                    evenCount++;
                } else {
                    oddCount++;
                }
            }

            if(oddCount == 0){
                System.out.println("No");
            } else {
                int lesserOfTwo = Math.min(oddCount, chooseThisNum);
                if(lesserOfTwo%2 == 0){
                    lesserOfTwo--;
                }
                if(evenCount >= chooseThisNum - lesserOfTwo){
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            }  
        }
    }
}
// count the number of even and odd numbers in the array, make sure there are enough even + (double odd pairs) + 1 odd to make it an odd sequence
// even and an odd pair keep the parity the same throughout.