public class Main {
    public static void main(String[] args) {
        ChainExercise<Integer> a = new ChainExercise<>();
        ChainExercise<Integer> b = new ChainExercise<>();
        ChainExercise<Integer> c = new ChainExercise<>();
        a.push_back(4);
        a.push_back(3);
        a.push_back(9);
        a.push_back(3);
        a.push_back(7);
        a.push_back(1);
        a.rankSort(false);
        a.output();
        System.out.println("hello world!");
    }
}
