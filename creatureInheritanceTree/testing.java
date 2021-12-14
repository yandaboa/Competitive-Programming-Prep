package creatureInheritanceTree;

public class testing {
    public static void main(String[] args){
        update(new zombie("Frank"));
        update(new creeper("Sam"));
        System.out.println(new zombie("Freddie"));
        zombie Ted = new zombie("Ted");
        Ted.revive();
    }

    public static void update(creature c){
        if(c instanceof revivable){
            zombie temp = (zombie) c;
            temp.revive();
        } if (c instanceof explodable){
            creeper temp = (creeper) c;
            temp.explode();
        }
    }
}
