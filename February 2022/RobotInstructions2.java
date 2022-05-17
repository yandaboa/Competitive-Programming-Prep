import java.io.BufferedReader;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.StringTokenizer;

import javax.naming.InsufficientResourcesException;

public class RobotInstructions2 {

    private static Long[] xArr;
    private static Long[] yArr;

    private static int[] solution;
    private static Long xTarget;
    private static Long yTarget;
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int instructions = Integer.parseInt(input.readLine());
        xArr = new Long[instructions];
        yArr = new Long[instructions];
        solution = new int[instructions];
        StringTokenizer target = new StringTokenizer(input.readLine());
        xTarget = Long.parseLong(target.nextToken());
        yTarget = Long.parseLong(target.nextToken());
        long remXNeg = 0;
        long remYNeg = 0;

        for(int i = 0; i < instructions; i++){
            solution[i] = 0; 
            StringTokenizer line = new StringTokenizer(input.readLine());
            xArr[i] = Long.parseLong(line.nextToken());
            yArr[i] = Long.parseLong(line.nextToken());
            if(xArr[i] < 0){
                remXNeg += xArr[i];
            }
            if(yArr[i] < 0){
                remYNeg += yArr[i];
            }
        }
        for(int i = 0; i < instructions; i++){
            if(xArr[i] < 0){
                remXNeg -= xArr[i];
            }
            if(yArr[i] < 0){
                remYNeg -= yArr[i];
            }
            recursived(1, xArr[i], yArr[i], i, remXNeg, remYNeg);
        }
        for(int i = 0; i < solution.length; i++){
            System.out.println(solution[i]);
        }
    }

    private static void recursived(int pickedNum, Long currSum, Long currYSum, int index, Long remXNeg, Long remYNeg){
        if(currSum == xTarget && currYSum == yTarget){
            solution[pickedNum - 1]++;
        }
        if(currSum + remXNeg <= xTarget && currYSum + remYNeg <= yTarget){
            for(int i = index + 1; i < xArr.length; i++){
                if(xArr[i] < 0){
                    remXNeg -= xArr[i];
                }
                if(yArr[i] < 0){
                    remYNeg -= yArr[i];
                }
                recursived(pickedNum + 1, currSum + xArr[i], currYSum + yArr[i], i, remXNeg, remYNeg);
            }
        }
        
    }
}