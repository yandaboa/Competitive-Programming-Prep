import java.util.*;
import java.io.*;

public class shell {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader(new File("shell.in")));
        BufferedWriter out = new BufferedWriter(new FileWriter(new File("shell.out")));

        int switches = Integer.parseInt(in.readLine());

        ArrayList<cup> table = new ArrayList<cup>();
        for(int i = 0; i < 3; i++){
            table.add(new cup());
        }

        for(int i = 0; i < switches; i++){
            String[] temp = in.readLine().split(" ");
            cup temp2 = table.get(Integer.parseInt(temp[0]) - 1);
            table.set(Integer.parseInt(temp[0]) - 1, table.get(Integer.parseInt(temp[1]) - 1));
            table.set(Integer.parseInt(temp[1]) - 1, temp2);
            
            table.get(Integer.parseInt(temp[2]) - 1).count += 1;
        }
        int max = 0;
        for(cup a : table){
            max = Math.max(a.count, max);
        }

        out.write("" + max);
        out.close();
    }
}

class cup {
    public int count;

    public cup(){
        count = 0;
    }

    public cup(int a){
        count = a;
    }

    public String toString(){
        return "" + count;
    }
}
