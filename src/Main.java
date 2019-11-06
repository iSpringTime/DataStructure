public class Main {
    public static void main(String[] args) {
        Chain<Integer> chain = new Chain<>(0);
        chain.push_back(1);
        chain.push_back(2);
        chain.push_back(3);
        chain.push_back(4);
        chain.push_back(5);
        chain.output();
        Chain<Integer> b = new Chain<>(chain);
        chain.output();
        System.out.println(b.get(6));
        System.out.println(b.indexOf(6));
        b.insert(4, 9);
        b.output();
        System.out.println("hello world!");
    }
}
