import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

import javax.swing.text.AsyncBoxView;

public class ClosingTheFarm {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new FileReader("closing.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("closing.out"));
        StringBuilder sb = new StringBuilder();

        String[] temp = input.readLine().split(" ");
        Graph gp = new Graph(Integer.parseInt(temp[0]));

        for(int i = 0; i < Integer.parseInt(temp[1]); i++){
            StringTokenizer st = new StringTokenizer(input.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            gp.addEdge(a, b);
            gp.addEdge(b, a);
        }
        if(gp.DFS()){
            sb.append("YES\n");
        }else {
            sb.append("NO\n");
        }
        for(int i = 0; i < Integer.parseInt(temp[0]) - 1; i++){
            gp.closeCity(Integer.parseInt(input.readLine()));
            if(gp.DFS()){
                sb.append("YES\n");
            }else {
                sb.append("NO\n");
            }
        }
        out.write(sb.toString());
        out.close();
    }
}


class Graph {
    public int V;
    private LinkedList<Integer> adj[];

    private boolean[] canbeReached;
    private HashSet<Integer> exempt;

    public Graph(int V){
        this.V = V + 1;
        adj = new LinkedList[this.V];
        for(int i = 1; i < adj.length; i++){
            adj[i] = new LinkedList<Integer>();
        }
        canbeReached = new boolean[this.V];
        exempt = new HashSet<Integer>();
    }

    public void addEdge(int a, int b){
        System.out.println("Edge from " + a + " to " + b + " was added.");
        adj[a].add(b);
    }

    public void closeCity(int a){
        System.out.println(a + " was closed");
        exempt.add(a);
        for(int i = 1; i < adj.length; i++){
            removeEdge(a, i);
            removeEdge(i, a);
        }
    }

    private void removeEdge(int a, int b){
        if(adj[a].indexOf(b) > -1){
            adj[a].remove(adj[a].indexOf(b));
            System.out.println("Edge " + a + " to " + b + " was removed.");
        }
    }

    public boolean DFS(){
        canbeReached = new boolean[this.V];
        for(int i = 1; i < this.V; i++){
            if(!exempt.contains(i)){
                DFSutil(i, new boolean[this.V]);
                break;
            }
        }
        for(int i = 1; i < canbeReached.length; i++){
            if(!canbeReached[i] && !exempt.contains(i)){
                System.out.println(i);
                return false;
            }
        }
        return true;
    }

    public void DFSutil(int a, boolean[] visited){
        
        visited[a] = true;
        canbeReached[a] = true;
        //this code is meant to help find the shortest possible path

        Iterator<Integer> it = adj[a].iterator();
        while(it.hasNext()){
            int temp = it.next();
            if(!visited[temp]){
                DFSutil(temp, visited);
            }
        }
    }
}