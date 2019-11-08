public class Main {
    public static void main(String[] args) {
        ChainExercise<Integer> a = new ChainExercise<>();
        a.push_back(1);
        a.push_back(2);
        a.push_back(6);
        a.push_back(9);
        a.output();
        ChainExercise<Integer> b = new ChainExercise<>();
        b.push_back(3);
        b.push_back(4);
        b.push_back(7);
        b.push_back(8);
        b.output();
        a.melt(b).output();
        a.output();
        System.out.println("hello world!");
    }
}
