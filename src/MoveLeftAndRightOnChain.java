// P126 24
public class MoveLeftAndRightOnChain<T extends Comparable<T>> extends Chain<T> {
    private ChainNode<T> p;
    private ChainNode<T> l;
    MoveLeftAndRightOnChain(Chain<T> theChain) {
        p = theChain.headerNode.next;
        l = null;
        this.headerNode.next = theChain.headerNode.next;
    }
    void moveRight() {
        ChainNode<T> nxtNode = p.next;
        if (p != null) {
            p.next = l;
            l = p;
            p = nxtNode;
            if (nxtNode != null) {
                nxtNode = nxtNode.next;
            }
        }
    }
    void moveLeft() {
        ChainNode<T> nxtNode = l.next;
        if (l != null) {
            l.next = p;
            p = l;
            l = nxtNode;
            if (nxtNode != null) {
                nxtNode = nxtNode.next;
            }
        }
    }
    T currentElement() {
        return p.element;
    }

    T previousElement() {
        return l.element;
    }
    public void output() {
        ChainNode<T> curNode = p;
        System.out.print("p: ");
        while (curNode != null) {
            System.out.print(curNode.element + " ");
            curNode = curNode.next;
        }
        System.out.println();
        curNode = l;
        System.out.print("l: ");
        while (curNode != null) {
            System.out.print(curNode.element + " ");
            curNode = curNode.next;
        }
        System.out.println();
    }
}
