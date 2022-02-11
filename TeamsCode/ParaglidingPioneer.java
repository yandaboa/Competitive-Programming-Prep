import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeMap;

import javax.management.openmbean.InvalidOpenTypeException;


public class ParaglidingPioneer{
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int numOfIntervals = Integer.parseInt(input.readLine());
        TreeMap<Integer, Integer> numberline = new TreeMap<Integer, Integer>();

        for(int i = 0; i < numOfIntervals; i++){
            StringTokenizer intervalString = new StringTokenizer(input.readLine(), " ");
            int begin = Integer.parseInt(intervalString.nextToken());
            int end = Integer.parseInt(intervalString.nextToken());
            if(numberline.keySet().contains(begin)){
                numberline.put(begin, numberline.get(begin) + 1);
            } else {
                numberline.put(begin, 1);
            }
            if(numberline.keySet().contains(end)){
                numberline.put(end + 1, numberline.get(end) - 1);
            } else {
                numberline.put(end + 1, -1);
            }
        }

        int max = Integer.MIN_VALUE;
        int indexOfMax = -1;
        int currSum = 0;
        for(Map.Entry<Integer, Integer> entry : numberline.entrySet()){
            currSum += entry.getValue();
            if(currSum > max){
                indexOfMax = entry.getKey();
                max = currSum;
            }
        }
        System.out.println(indexOfMax);
    }
}