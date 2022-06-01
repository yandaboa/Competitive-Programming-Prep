import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Animal{
    String species = "";
    private static String region = "Africa";

    public Animal(String species){
        this.species = species;
    }

    public static String getRegion(){
        return region;
    }

}

public class Test {
    public static void main(String[] args){
        System.out.println(Animal.getRegion());
    }
}

/*
class Result {
    Cube red;
    Cube blue;
    Cube orange;
    Cube green;
    Cube purple;
    Cube yellow;

    /*
     * Complete the 'rotateCube' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING start
     *  2. STRING moves
     

    public static String rotateCube(String start, String moves) {
        doCubes();
    }

    private static void doCubes(){
        Cube red = new Cube();
        String[][] tempGrid = {{"R0", "R1", "R2"}, {"R3", "R4", "R5"}, {"R5", "R7", "R8"}};
        red.cubeGrid = tempGrid;
        Cube blue = new Cube();
        String[][] tempGridd = {{"B0", "B1", "B2"}, {"B3", "B4", "B5"}, {"B5", "B7", "B8"}};
        blue.cubeGrid = tempGridd;
        Cube orange = new Cube();
        String[][] tempGrid1 = {{"O0", "O1", "O2"}, {"O3", "O4", "O5"}, {"O5", "O7", "O8"}};
        orange.cubeGrid = tempGrid1;
        Cube green = new Cube();
        String[][] tempGrid2 = {{"G0", "G1", "G2"}, {"G3", "G4", "G5"}, {"G5", "G7", "G8"}};
        green.cubeGrid = tempGrid2;
        Cube purple = new Cube();
        String[][] tempGrid3 = {{"P0", "P1", "P2"}, {"P3", "P4", "P5"}, {"P5", "P7", "P8"}};
        purple.cubeGrid = tempGrid3;
        Cube yellow = new Cube();
        String[][] tempGrid4 = {{"Y0", "Y1", "Y2"}, {"Y3", "Y4", "Y5"}, {"Y5", "Y7", "Y8"}};
        yellow.cubeGrid = tempGrid4;
    }

}

class Cube{
    public String[][] cubeGrid;
    public Cube left;
    public Cube right;
    public Cube up;
    public Cube down;

    public Cube(String color){
        String[][] cubeGrid = {{"R0", "R1", "R2"}, {"R3", "R4", "R5"}, {"R5", "R7", "R8"}};
        this.cubeGrid = cubeGrid;
    }

    public Cube(){

    }
}
*/