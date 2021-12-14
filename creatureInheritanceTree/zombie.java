package creatureInheritanceTree;

public class zombie extends creature implements revivable {

    public zombie(String name){
        super(name);
    }
    @Override
    public void revive() {
        System.out.println("Zombie(" + name + ") has come back to life, run for your life!");
    }
}
