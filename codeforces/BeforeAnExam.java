import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BeforeAnExam {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line1 = new StringTokenizer(input.readLine(), " ");
        int days = Integer.parseInt(line1.nextToken());
        int sumTime = Integer.parseInt(line1.nextToken());
        
        Day[] arrDays = new Day[days];
        int sumOfMin = 0;
        int sumOfMax = 0;
        for(int i = 0; i < days; i++){
            StringTokenizer line = new StringTokenizer(input.readLine(), " ");
            int min = Integer.parseInt(line.nextToken());
            int max = Integer.parseInt(line.nextToken());
            sumOfMin += min;
            sumOfMax += max;
            arrDays[i] = new Day(min, max - min);
        }
        if(sumOfMin <= sumTime && sumOfMax >= sumTime){
            System.out.println("YES");
            sumTime -= sumOfMin;
            int[] sol = new int[days];
            for(int i = 0; i < days; i++){
                sol[i] = arrDays[i].min;
                if(arrDays[i].allowance <= sumTime){
                    sol[i] += arrDays[i].allowance;
                    sumTime -= arrDays[i].allowance;
                } else {
                    sol[i] += sumTime;
                    sumTime = 0;
                }
            }
            for(int i = 0; i < sol.length - 1; i++){
                System.out.print(sol[i] + " ");
            }
            System.out.print(sol[sol.length - 1]);
        } else {
            System.out.println("NO");
        }

    }
}

class Day {

    public int min;
    public int allowance;

    public Day(int min, int allowance){
        this.min = min;
        this.allowance = allowance;
    }
}