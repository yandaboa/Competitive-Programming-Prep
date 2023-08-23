import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;



public class livestockLineup {

    private static ArrayList<Integer> inComp;
    private static boolean[] visited = new boolean[8];
    private static ArrayList<Integer>[] adjMatrix = new ArrayList[8];


    private static void DFS(int a){
        if(visited[a]){
            return;
        }
        System.out.println(a);
        visited[a] = true;
        inComp.add(a);
        for(int i = 0; i < adjMatrix[a].size(); i++){
            DFS(adjMatrix[a].get(i));
        }
        
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int constraints = Integer.parseInt(input.next());
        String[] cowNames = {"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};
        Arrays.sort(cowNames);
        Map<String, Integer> alphOrder = new HashMap<String, Integer>();
        for(int i = 0; i < cowNames.length; i++){
            alphOrder.put(cowNames[i], i);
        }

        for(int i = 0; i < adjMatrix.length; i++){
            adjMatrix[i] = new ArrayList<Integer>();
        }

        while(input.hasNextLine()){
            int cow1, cow2;
            cow1 = alphOrder.get(input.next()); input.next(); input.next(); input.next(); input.next(); cow2 = alphOrder.get(input.next());
            System.out.println(cow1 + " " + cow2);
            adjMatrix[cow1].add(cow2);
            adjMatrix[cow2].add(cow1);
        }

        List<ArrayList<Integer> > components = new ArrayList<ArrayList<Integer> >();
        for(int i = 0; i < visited.length; i++){
            if(!visited[i]){
                inComp = new ArrayList<Integer>();
                DFS(i);
                for(int j = 0; j < inComp.size(); i++){
                    System.out.print(inComp.get(j) + " ");
                }
                System.out.println();
                components.add(inComp);
            }
        }
        components.sort(new Comparator<ArrayList<Integer>>() {    
            @Override
            public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
                return o1.get(0).compareTo(o2.get(0));
            }               
        });
        for(int i = 0; i < components.size(); i++){
            for(int j = 0; j < components.get(i).size(); i++){
                System.out.println(components.get(i).get(j));
            }
        }
        
    }
}