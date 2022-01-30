import java.util.*;

import javax.print.attribute.HashAttributeSet;

import java.io.*;
import java.text.CollationElementIterator;

public class closestcow {

    private static grass[] grasses;
    private static int grassynum;
    private static int M;
    private static int N;
    public static void main(String[] args)throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(in.readLine());

        grassynum = Integer.parseInt(tokenizer.nextToken());
        M = Integer.parseInt(tokenizer.nextToken());
        N = Integer.parseInt(tokenizer.nextToken());
        grasses = new grass[grassynum];

        for(int i = 0; i < grassynum; i++){
            tokenizer = new StringTokenizer(in.readLine());
            grasses[i] = new grass(Integer.parseInt(tokenizer.nextToken()), Long.parseLong(tokenizer.nextToken()));
        }
        Arrays.sort(grasses);

        Integer[] nhojCows = new Integer[M];
        for(int i = 0; i < M; i++){
            nhojCows[i] = Integer.parseInt(in.readLine());
        }
        Arrays.sort(nhojCows);
        
        TreeMap<Integer, Integer> nhojCowsMap = new TreeMap<Integer, Integer>();
        for(int i = 0; i < M; i++){
            nhojCowsMap.put(nhojCows[i], i);
        }  
        TreeMap<Integer, Integer> grassesMap = new TreeMap<Integer, Integer>();
        for(int i = 0; i < grassynum; i++){
            grassesMap.put(grasses[i].loc, i);
        }
        
        long[] prefixSum = new long[grassynum + 1];
        for(int i = 0; i < grassynum; i++){
            prefixSum[i + 1] = prefixSum[i] + grasses[i].value;
        }

        long[][] points = new long[2][M + 1];
        for(int i = 0; i < grassynum; i++){
            Map.Entry<Integer, Integer> nextDownLineCow = nhojCowsMap.ceilingEntry(grasses[i].loc);
            int NofDownLine;
            if(nextDownLineCow == null){
                NofDownLine = M;
            } else {
                NofDownLine = nextDownLineCow.getValue();
            }
            points[1][NofDownLine] += grasses[i].value;
            if(NofDownLine == 0 || NofDownLine == M){
                points[0][NofDownLine] += grasses[i].value;
            } else {
                int locOfAnchorCow = Math.min(nhojCows[NofDownLine], (2*grasses[i].loc) - nhojCows[NofDownLine - 1]);
                int fixedLength = (locOfAnchorCow + nhojCows[NofDownLine] + 1)/2;
                int NextGrass = grassesMap.lowerEntry(fixedLength).getValue();
                points[0][NofDownLine] = Math.max(points[0][NofDownLine], prefixSum[NextGrass + 1] - prefixSum[i]);
            }
        }
        Long[] OverallValues = new Long[2*(M+1)];
        for(int i = 0; i <= M; i++){
            OverallValues[2*i] = points[0][i];
            OverallValues[(2*i) + 1] = points[1][i] - points[0][i];
        }
        Arrays.sort(OverallValues);
        long answer = 0;
        for(int i = Math.max(0, OverallValues.length - N); i < OverallValues.length; i++){
            answer += OverallValues[i];
        }
        System.out.println(answer);
    }
}

class grass implements Comparable<grass>{
    public int loc;
    public Long value;

    public grass(int loc, Long value){
        this.loc = loc;
        this.value = value;
    }

    public int compareTo(grass a){
        return loc - a.loc;
    }

    public String toString(){
        return loc + " | " + value;
    }

}