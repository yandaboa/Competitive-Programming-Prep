import java.util.*;
import java.io.*;

public class soulmates{
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int numOfPairs = Integer.parseInt(input.readLine());
        long slave = 0;
        long master = 0;
        long changes = 0;
        
        for(int i = 0; i < numOfPairs; i++){
            StringTokenizer currLine = new StringTokenizer(input.readLine(), " ");
            slave = Long.parseLong(currLine.nextToken());
            master = Long.parseLong(currLine.nextToken());

            if(slave == master){
                System.out.println(0);
                continue;
            }

            if(slave < master){
                while(slave <= master/2){
                    slave *= 2;
                    changes++;
                }
                changes += master - slave;

            } else {
                while(master < slave){
                    if(slave%2 == 1){
                        slave++;
                        slave /= 2;
                        changes += 2;
                    } else {
                        slave /= 2;
                        changes++;
                    }
                }

                changes += master - slave;
            }
            
            System.out.println(changes);

        }
    }
}