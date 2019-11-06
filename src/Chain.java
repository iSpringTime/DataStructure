import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

public class Chain<T> extends ExtendLinearList<T> {

    private int listSize = 0;
    private ChainNode<T> headerNode;
    private ChainNode<T> lastNode;
    private void checkIndex(int theIndex) {
        if (this.listSize != 0) {
            if (theIndex < 0 || theIndex >= this.listSize) {
                throw new ArrayIndexOutOfBoundsException("out of border");
            }
        }
    }

    Chain(T theHeaderValue) {
        this.headerNode = new ChainNode<>(theHeaderValue, null);
        this.lastNode = this.headerNode;
    }

    @SuppressWarnings("unchecked")
    public Chain(@NotNull final Chain theChain) {
        if (theChain.listSize != 0) {
            this.listSize = theChain.listSize;
            ChainNode<T> newNode = new ChainNode<>((T) theChain.headerNode.element, null);
            this.headerNode = newNode;

            ChainNode<T> sourceNode = theChain.headerNode.next;
            ChainNode<T> targetNode = this.headerNode;
            while (sourceNode != null) {
                newNode = new ChainNode<>(sourceNode.element, null);
                targetNode.next = newNode;
                targetNode = targetNode.next;
                sourceNode = sourceNode.next;
                this.listSize++;
            }
        } else {
            this.headerNode = new ChainNode<>((T) theChain.headerNode.element, null);
        }
    }

    @Override
    public void clear() {

    }

    @Override
    public void push_back(T theElement) {
        ChainNode<T> newNode = new ChainNode<>(theElement, null);
        this.lastNode.next = newNode;
        this.lastNode = newNode;
        this.listSize++;
    }

    @Override
    public boolean empty() {
        return false;
    }

    @Override
    public int size() {
        return 0;
    }

    @Override
    public T get(int theIndex) {
        return null;
    }

    @Override
    public int indexOf(T theElement) {
        return 0;
    }

    @Override
    public void erase(int theIndex) {

    }

    @Override
    public void insert(int theIndex, T theElement) {

    }

    @Override
    public void output() {
        ChainNode<T> curNode = this.headerNode.next;
        while (curNode != null) {
            System.out.print(curNode.element + " ");
            curNode = curNode.next;
        }
        System.out.println();
    }
}

class ChainNode<T> {
    T element;
    ChainNode<T> next;

    @Contract(pure = true)
    public ChainNode(T element) {
        this.element = element;
    }

    @Contract(pure = true)
    ChainNode(T element, ChainNode<T> next) {
        this.element = element;
        this.next = next;
    }
}
