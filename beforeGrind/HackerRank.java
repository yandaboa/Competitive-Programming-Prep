import java.io.*;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.StringTokenizer;

public class HackerRank {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer s1 = new StringTokenizer(input.readLine(), " ");
        int lamps = Integer.parseInt(s1.nextToken());
        int streetLength = Integer.parseInt(s1.nextToken());
        BigDecimal[] intervalsArr = new BigDecimal[lamps];
        StringTokenizer s2 = new StringTokenizer(input.readLine(), " ");
        for(int i = 0; i < intervalsArr.length; i++){
            intervalsArr[i] = BigDecimal.valueOf(Long.parseLong(s2.nextToken()));
        }
        Arrays.sort(intervalsArr);
        float maxDistanceBetweenLamps = 0;
        maxDistanceBetweenLamps = Math.max(maxDistanceBetweenLamps, intervalsArr[0].longValue());
        maxDistanceBetweenLamps = Math.max(maxDistanceBetweenLamps, streetLength - intervalsArr[intervalsArr.length - 1].longValue());
        for(int i = 1; i < intervalsArr.length; i++){
            float halvedDistance = (float)((intervalsArr[i].longValue() - intervalsArr[i-1].longValue())/2.0);
            maxDistanceBetweenLamps = Math.max(maxDistanceBetweenLamps, halvedDistance);
        }
        System.out.print(new BigDecimal(maxDistanceBetweenLamps).toPlainString());
    }
}