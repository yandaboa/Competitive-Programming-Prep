import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.HashSet;

// this works but tbh i still have no clue how to apply to a real usaco problem :D

public class dfs {
    public static void main(String[] args){
        Graph test = new Graph(6);
        test.addEdge(1, 2);
        test.addEdge(2, 3);
        test.addEdge(4, 5);
        System.out.println(test.hasPathDFS(1, 5));
    }
}

class Graph {
    private HashMap<Integer, Node> nodeLookUp = new HashMap<Integer, Node>();
    
    public Graph(int size){
        for(int i = 0; i < size; i++){
            nodeLookUp.put(i, new Node(i));
        }
    }

    private class Node {
        private int id;
        LinkedList<Node> adjacent = new LinkedList<Node>();
        private Node(int id) {
            this.id = id;
        }
        
    }
    private Node getNode(int id){
        return nodeLookUp.get(id);
    }

    public void addEdge(int start, int end){
        nodeLookUp.get(start).adjacent.add(nodeLookUp.get(end));
    }

    public boolean hasPathDFS(int source, int destination){
        Node s = nodeLookUp.get(source);
        Node e = nodeLookUp.get(destination);
        HashSet<Integer> alreadyVisited = new HashSet<Integer>();
        return hasPathDFS(s, e, alreadyVisited);
    }

    private boolean hasPathDFS(Node s, Node e, HashSet<Integer> alreadyVisited){
        if(alreadyVisited.contains(s.id)){
            return false;
        }
        alreadyVisited.add(s.id);
        if (s == e){
            return true;
        }
        for(Node child : s.adjacent){
            if(hasPathDFS(child, e, alreadyVisited)){
                return true;
            }
        }
        return false;
    }
}
