import java.io.BufferedReader;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.StringTokenizer;

import javax.naming.InsufficientResourcesException;

public class RobotInstructions {

    private static long[] xArr;
    private static long[] yArr;

    private static long[] solution;
    private static int xTarget;
    private static int yTarget;
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int instructions = Integer.parseInt(input.readLine());
        xArr = new long[instructions];
        yArr = new long[instructions];
        solution = new long[instructions];
        StringTokenizer target = new StringTokenizer(input.readLine());
        xTarget = Integer.parseInt(target.nextToken());
        yTarget = Integer.parseInt(target.nextToken());

        for(int i = 0; i < instructions; i++){
            solution[i] = 0; 
            StringTokenizer line = new StringTokenizer(input.readLine());
            xArr[i] = Long.parseLong(line.nextToken());
            yArr[i] = Long.parseLong(line.nextToken());
        }
        for(int i = 0; i < instructions; i++){
            recursived(1, xArr[i], yArr[i], i);
        }
        for(int i = 0; i < solution.length; i++){
            System.out.println(solution[i]);
        }
    }

    private static void recursived(int pickedNum, long currSum, long currYSum, int index){
        if(currSum == xTarget && currYSum == yTarget){
            solution[pickedNum - 1]++;
        }
        for(int i = index + 1; i < xArr.length; i++){
            recursived(pickedNum + 1, currSum + xArr[i], currYSum + yArr[i], i);
        }
    }
}