package creatureInheritanceTree;

public class creature {
    public String name;

    public creature(String a){
        name = a;
    }

    public String toString(){
        return "Creature is a " + name;
    }
}
