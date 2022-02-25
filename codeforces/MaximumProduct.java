import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class MaximumProduct {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int numOfCases = Integer.parseInt(input.readLine());
        String solution = "";
        for(int i = 0; i < numOfCases; i++){
            int size = Integer.parseInt(input.readLine());
            StringTokenizer line = new StringTokenizer(input.readLine());
            Integer[] arr = new Integer[size];
            boolean allNeg = true;
            for(int j = 0; j < size; j++){
                int a = Integer.parseInt(line.nextToken());
                arr[j] = a;
                if(a > 0){
                    allNeg = false;
                }
            }
            if(allNeg){
                long sol = 1;
                Arrays.sort(arr);
                for(int j = arr.length - 5; j < arr.length; j++){
                    sol *= arr[j];
                }
                solution += sol;
            } else {
                Arrays.sort(arr, new SortByAbs());
                long sol = arr[size-5]*arr[size-4]*arr[size-3]*arr[size -2]*arr[size - 1];
                for(int j = 5; j < arr.length; j++){
                    for(int a = 0; a < 5; a++){
                        long temp = arr[j];
                        for(int b = 0; b < 5; b++){
                            if(b != a){
                                temp *= arr[b];        
                            }

                        }
                        sol = Math.max(temp, sol);
                    }
                }
                solution += sol;
                
            }
            solution += "\n";
        }
        System.out.println(solution);
    }
}

class SortByAbs implements Comparator<Integer>{
    @Override
    public int compare(Integer a, Integer b){
        return Math.abs(a) - Math.abs(b);
    }
}