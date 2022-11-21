import java.util.*;
import java.io.*;

public class CountingRooms {

    private static boolean[][] visited;
    private static int rows;
    private static int cols;
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer dimensions = new StringTokenizer(input.readLine(), " ");
        rows = Integer.parseInt(dimensions.nextToken());
        cols = Integer.parseInt(dimensions.nextToken());
        int[][] grid = new int[rows][cols];
        visited = new boolean[rows][cols];
        for(int i = 0; i < rows; i++){
            String line = input.readLine();
            for(int j = 0; j < cols; j++){
                if(line.charAt(j) == '#'){
                    grid[i][j] = 0;
                    visited[i][j] = true;
                } else {
                    grid[i][j] = 1;
                }
            }
        }
        
        int numOfRooms = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    numOfRooms++;
                    dfs(i, j, grid);
                }
            }
        }
        System.out.println(numOfRooms);
        
    }

    private static void dfs(int x, int y, int[][] grid){
        if(x > rows - 1 || x < 0 || y > cols - 1 || y < 0 || grid[x][y] != 1 || visited[x][y]){
            return;
        }
        visited[x][y] = true;
        dfs(x + 1, y, grid);
        dfs(x, y + 1, grid);
        dfs(x - 1, y, grid);
        dfs(x, y - 1, grid);
    }
}
