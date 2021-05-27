import java.util.*;
import java.io.*;

class cowntagion
{
    private static int V;   // No. of vertices
    private static HashMap<Integer, ArrayList<Integer>> adj;
    private static int days;
    private static int[] cows;
 
    private static int BFS(int s)
    {
        boolean visited[] = new boolean[V];
 
        // Create a queue for BFS
        LinkedList<Integer> queue = new LinkedList<Integer>();
 
        visited[s]=true;
        queue.add(s);
 
        while (queue.size() != 0)
        {
            // Dequeue a vertex from queue and print it
            s = queue.poll();
 
            int fbelow = 0;
            Iterator<Integer> i = adj.get(s).listIterator();
            while (i.hasNext())
            {
                int n = i.next();
                if (!visited[n])
                {
                    fbelow++;
                    visited[n] = true;
                    queue.add(n);
                }
            }
            System.out.println(fbelow);
            int result = (int)(Math.log(fbelow + 1)/Math.log(2));
            days += result;
        }
        return days;
    }

    public static void main(String[] args)
    {
        Scanner obj = new Scanner(System.in);
        
        int cows = Integer.parseInt(obj.nextLine());
        days = 0;
        V = cows;
        adj = new HashMap<Integer, ArrayList<Integer>>(V);
        for (int i=0; i < V; ++i)
            adj.put(i, new ArrayList<Integer>());
        
        for(int i = 0; i < cows - 1; i++){
            String road = obj.nextLine();
            int first = Integer.parseInt(road.split(" ")[0]);
            int second = Integer.parseInt(road.split(" ")[1]);
            adj.get(first).add(second);
            adj.get(second).add(first);
        }
        int sol = BFS(0) + V - 1;
        System.out.println(sol);
    }
}
