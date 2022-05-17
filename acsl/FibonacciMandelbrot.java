import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;



class Result {

    private static int escapeValue = 4;
    private static final DecimalFormat df = new DecimalFormat("0.000");


    /*
     * Complete the 'numFibonacciCycles' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. FLOAT realPartLL
     *  2. FLOAT imagPartLL
     *  3. FLOAT realPartUR
     *  4. FLOAT imagPartUR
     *  5. FLOAT incr
     */

    public static int numFibonacciCycles(float realPartLL, float imagPartLL, float realPartUR, float imagPartUR, float incr) {
        Integer[] arr = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
        List<Integer> fibonaccis = Arrays.asList(arr);
        int counter = 0;
        float i = imagPartLL;
        while(i <= imagPartUR){
            
            
            for(float j = realPartLL; j <= realPartUR; j+=incr){

                j = Float.parseFloat(df.format(j));
                int temp = calculateCycle(j, i);
                if(fibonaccis.contains(temp)){
                    counter++;
                }
                System.out.println(temp + " | " + j + " " + i);
            }
            i += incr;
            i = Float.parseFloat(df.format(i));
        }

        return counter;
    }

    private static int calculateCycle(double realPart, double imagPart){
        ArrayList<Double> soFarReal = new ArrayList<Double>();
        ArrayList<Double> soFarImag = new ArrayList<Double>();
        realPart = Double.parseDouble(df.format(realPart));
        imagPart = Double.parseDouble(df.format(imagPart));
        double changingReal = Double.parseDouble(df.format(realPart));
        double changingImag = Double.parseDouble(df.format(imagPart));
        System.out.print(changingReal + " " + changingImag + "i\n");

        soFarReal.add(changingReal);
        soFarImag.add(changingImag);
        for(int i = 2; i < 501; i++){
            double tempReal = changingReal;
            changingReal = Math.pow(changingReal, 2) + -1*(Math.pow(changingImag, 2)) + realPart;
            changingImag = 2*tempReal*changingImag + imagPart;
            changingReal = Double.parseDouble(df.format(changingReal));
            changingImag = Double.parseDouble(df.format(changingImag));
            for(int j = 0; j < soFarReal.size(); j++){
                if(soFarReal.get(j) == changingReal && soFarImag.get(j) == changingImag){
                    return i - j - 1;
                }
            }
            double temp = Math.sqrt(Math.pow(changingReal, 2) + Math.pow(changingImag, 2));
            if(temp > 4){
                return 0;
            }
            soFarReal.add(changingReal);
            soFarImag.add(changingImag);
        }
        return -1;
    }
    
}