public class Main {
    public static void main(String[] args) {
        ChainExercise<Integer> a = new ChainExercise<>();
        ChainExercise<Integer> b = new ChainExercise<>();
        ChainExercise<Integer> c = new ChainExercise<>();
        a.push_back(10);
        a.push_back(5);
        a.push_back(8);
        a.push_back(4);
        a.push_back(99);
        a.push_back(15);
        a.push_back(34);
        a.push_back(12);
        a.push_back(13);
        a.push_back(7);
        a.push_back(9);
        a.push_back(2);
        a.bubbleSort(true);
        a.output();
        System.out.println("hello world!");
    }
}
