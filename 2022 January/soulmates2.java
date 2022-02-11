import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;
import java.util.StringTokenizer;
import java.io.*;
 
class nodes {
    long slave;
    long changes;
 
    public nodes(long slave, long changes){
        this.slave = slave;
        this.changes = changes;
    }
}
 
public class soulmates2 {

    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int numOfPairs = Integer.parseInt(input.readLine());
        long slave = 0;
        long master = 0;
        
        for(int i = 0; i < numOfPairs; i++){
            StringTokenizer currLine = new StringTokenizer(input.readLine(), " ");
            slave = Long.parseLong(currLine.nextToken());
            master = Long.parseLong(currLine.nextToken());
            System.out.println(minOperations(slave, master));
        }
    }

    private static long minOperations(long src, long target)
    {
 
        Set<nodes> visited = new HashSet<>();
        LinkedList<nodes> queue = new LinkedList<nodes>();
 
        nodes node = new nodes(src, 0);
 
        queue.offer(node);
        visited.add(node);
 
        while (!queue.isEmpty()) {
            nodes temp = queue.poll();
            visited.add(temp);
 
            if (temp.slave == target) {
                return temp.changes;
            }
 
            long mul = temp.slave * 2;
            long add = temp.slave + 1;
            long div = temp.slave / 2;

            // given constraints
            if (mul > 0 && mul < Long.MAX_VALUE/4) {
                nodes nodeMul = new nodes(mul, temp.changes + 1);
                queue.offer(nodeMul);
            }
            if (add > 0 && add < Long.MAX_VALUE/4) {
                nodes nodeSub = new nodes(add, temp.changes + 1);
                queue.offer(nodeSub);
            }
            if (div > 0 && div < Long.MAX_VALUE/4 && temp.slave%2 == 0) {
                nodes nodeDiv = new nodes(div, temp.changes + 1);
                queue.offer(nodeDiv);
            }
        }
        return -1;
    }
 
}