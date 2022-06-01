import java.util.Iterator;
import java.util.LinkedList;

/*TAKEAWAY:
------------
The visited array makes it so that the DFS only finds one possible path to the target.
The DFS won't get to the target again beacuse it is marked as visited in the array.
Need to look at what DFS can be used for
SUCCESS in implementing a DFS.
*/
public class dfsShortestPath {
    public static void main(String[] args){
        Graph g = new Graph(5);
        g.addEdge(1, 2);
        g.addEdge(2, 1);
        g.addEdge(5, 2);
        g.addEdge(2, 5);
        g.addEdge(1, 3);
        g.addEdge(3, 4);
        g.addEdge(4, 5);
        g.addEdge(1, 5);
        System.out.println(g.DFS(1, 5));
    }
}

class Graph {
    public int V;
    private LinkedList<Integer> adj[];

    private String shortestPath = "";
    private int pathLength = Integer.MAX_VALUE;

    public Graph(int V){
        this.V = V + 1;
        adj = new LinkedList[this.V];
        for(int i = 0; i < adj.length; i++){
            adj[i] = new LinkedList<Integer>();
        }
    }

    public void addEdge(int a, int b){
        System.out.println("Edge from " + a + " to " + b + " was added.");
        adj[a].add(b);
    }

    public String DFS(int a, int target){
        pathLength = Integer.MAX_VALUE;
        shortestPath = "";
        DFSutil(a, new boolean[V], target, "");
        return shortestPath;
    }

    public void DFSutil(int a, boolean[] visited, int target, String path){
        System.out.println(a+ " | " + path);
        path += a;
        visited[a] = true;
        //this code is meant to help find the shortest possible path
        if(a == target){
            if(path.length() < pathLength){
                shortestPath = path;
                pathLength = path.length();
            }
            return;
        }
        Iterator<Integer> it = adj[a].iterator();
        while(it.hasNext()){
            int temp = it.next();
            if(!visited[temp]){
                DFSutil(temp, visited, target, path);
            }
        }
    }
}