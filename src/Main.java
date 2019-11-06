public class Main {
    public static void main(String[] args) {
        Chain<Integer> chain = new Chain<Integer>(0);
        chain.push_back(1);
        chain.push_back(2);
        chain.push_back(3);
        chain.push_back(4);
        chain.push_back(5);
        chain.output();
        System.out.println("hello world!");
    }
}
