public class Main {
    public static void main(String[] args) {
        ChainExercise<Integer> a = new ChainExercise<>();
        ChainExercise<Integer> b = new ChainExercise<>();
        ChainExercise<Integer> c = new ChainExercise<>();
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        a.push_back(4);
        a.push_back(5);
        a.push_back(6);
        a.push_back(7);
        a.push_back(8);
        a.push_back(9);
        a.push_back(10);
        a.push_back(11);
        a.push_back(12);
        a.output();
        MoveLeftAndRightOnChain<Integer> move = new MoveLeftAndRightOnChain<>(a);
        move.moveRight();
        move.moveRight();
        move.moveRight();
        move.output();
        move.moveLeft();
        move.output();
        System.out.println("hello world!");
    }
}
