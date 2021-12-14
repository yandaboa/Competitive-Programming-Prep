package creatureInheritanceTree;

public class creeper extends creature implements explodable {

    public creeper(String name){
        super(name);
    }

    @Override
    public void explode() {
        System.out.println("Creeper(" + name + ") has died, exploding everything around it to bits and peices.");
    }
}
