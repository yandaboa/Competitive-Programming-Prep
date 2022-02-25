import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LovesChessboard {

    private static Boolean[][] visited;
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer limits = new StringTokenizer(input.readLine(), " ");
        int rows = Integer.parseInt(limits.nextToken());
        int cols = Integer.parseInt(limits.nextToken());
        char[][] board = new char[rows][cols];
        visited = new Boolean[rows][cols];
        for(int i = 0 ; i < rows; i++){
            String line = input.readLine();
            for(int j = 0; j < cols; j++){
                board[i][j] = line.charAt(j);
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] != '-'){
                    if((i + j)%2 == 0){
                        board[i][j] = 'W';
                    } else {
                        board[i][j] = 'B';
                    } 
                }
                
                /*
                if(!visited[i][j]){
                    dfs(i, j, board);
                }
                */
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
    }

    private static void dfs(int x, int y, char[][] board){
        
    }
}

//https://codeforces.com/problemset/problem/445/A