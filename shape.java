import java.util.*;
import java.io.*;

public class shape implements Comparable<shape>{
    
    public int z;
    public String name;

    public shape(int z, String a){
        this.z = z;
        name = a;
    }

    @Override
    public int compareTo(shape o) {
        return this.z - o.z;
    }

    public String toString(){
        return "Layer " + z + ", shape: " + name;
    }
}

class testing{
    public static void main(String[] args){
        ArrayList<shape> shapes = new ArrayList<shape>();
        shapes.add(new shape(1, "triangle"));
        shapes.add(new shape(5, "circle"));
        shapes.add(new shape(4, "red circle"));
        shapes.add(new shape(3, "rectangle"));
        shapes.add(new shape(7, "orange triangle"));
        shapes.add(new shape(6, "orange circle"));
        System.out.println(shapes);
        Collections.sort(shapes);
        System.out.println(shapes);
    }
}