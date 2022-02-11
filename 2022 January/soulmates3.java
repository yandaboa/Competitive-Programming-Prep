import java.io.*;
import java.util.StringTokenizer;
 
class GFG
{
    static long minOperations(long x, long y)
    {
       
        // If both are equal then return 0
        if (x == y)
            return 0;
 
        // Check if conversion is possible or not
        if (x <= 0 && y > 0)
            return -1;
 
        // If x > y then we can just increase y by 1
        // Therefore return the number of increments
        // required
        if (x/2 > y){
            return 1 + minOperations(x, y * 2);
        } else if (x > y){
            return 1 + minOperations(x, y + 1);
        }
            
 
        // If last bit is odd
        // then increment y so that we can make it even
        if (y % 2 != 0)
            return 1 + minOperations(x, y + 1);
 
        // If y is even then divide it by 2 to make it
        // closer to x
        else
            return 1 + minOperations(x, y / 2);
    }
 
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int numOfPairs = Integer.parseInt(input.readLine());
        long slave = 0;
        long master = 0;
        
        for(int i = 0; i < numOfPairs; i++){
            StringTokenizer currLine = new StringTokenizer(input.readLine(), " ");
            slave = Long.parseLong(currLine.nextToken());
            master = Long.parseLong(currLine.nextToken());
            System.out.println(minOperations(master, slave));
        }
    }
}