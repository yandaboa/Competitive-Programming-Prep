import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

import javax.crypto.ShortBufferException;
import javax.naming.ConfigurationException;

public class ternaryString {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int numOfTestCases = Integer.parseInt(input.readLine());
        String sol = "";

        for(int i = 0; i < numOfTestCases; i++){
            ArrayList<contigInterval> shortened = new ArrayList<contigInterval>();
            String line = input.readLine();
            String curr = line.charAt(0) + "";
            shortened.add(new contigInterval(Integer.parseInt((curr.charAt(curr.length() - 1)) + ""), 1));
            for(int j = 1; j < line.length(); j++){
                if(curr.charAt(curr.length() - 1) != line.charAt(j)){
                    shortened.add(new contigInterval(Integer.parseInt(line.charAt(j) + ""), 1));
                    curr += line.charAt(j);
                } else {
                    curr += line.charAt(j);
                    shortened.get(shortened.size() - 1).add();
                }
            }
            Stack<Integer> stack1 = new Stack<Integer>();
            Stack<Integer> stack2 = new Stack<Integer>();
            Stack<Integer> stack3 = new Stack<Integer>();

            for(int j = 0; j < shortened.size(); j++){
                if(shortened.get(j).value == 3){
                    stack3.add(j);
                } else if (shortened.get(j).value == 2){
                    stack2.add(j);
                } else {
                    stack1.add(j);
                }
            }
            int low = 0;
            int high = shortened.size() - 1;
            Stack[] three = new Stack[3];
            three[0] = stack1;
            three[1] = stack2;
            three[2] = stack3;
            while(low < high && !stack1.isEmpty() && !stack2.isEmpty() && !stack3.isEmpty()){
                if(shortened.get(low).occ > shortened.get(high).occ){
                    three[shortened.get(low).value - 1].pop();
                    low++;
                } else {
                    three[shortened.get(high).value - 1].pop();
                    high--;
                }
            }
            int sum = 0;
            for(int j = low; j <= high; j++){
                sum += shortened.get(j).occ;
            }
            sol += sum + "\n";
        }
        System.out.println(sol);
    }
}

class contigInterval{
    int value;
    int occ;
    public contigInterval(int value, int occ){
        this.value = value;
        this.occ = occ;
    }
    public void add(){
        occ += 1;
    }
    public String toString(){
        return value + " occurs " + occ + " times.";
    }
}