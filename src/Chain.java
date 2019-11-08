import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

public class Chain<T> extends ExtendLinearList<T> {

    protected int listSize = 0;
    protected ChainNode<T> headerNode;
    protected ChainNode<T> lastNode;
    protected void checkIndex(int theIndex) {
        if (this.listSize != 0) {
            if (theIndex < 0 || theIndex >= this.listSize) {
                throw new ArrayIndexOutOfBoundsException("out of border");
            }
        }
    }
    Chain() {
        this.headerNode = new ChainNode<>();
        this.lastNode = this.headerNode;
        this.headerNode.next = null;
    }

    @SuppressWarnings("unchecked")
    Chain(@NotNull final Chain theChain) {
        if (theChain.listSize != 0) {
            this.listSize = theChain.listSize;
            this.lastNode = theChain.lastNode;
            ChainNode<T> newNode = new ChainNode<>((T) theChain.headerNode.element, null);
            this.headerNode = newNode;

            ChainNode<T> sourceNode = theChain.headerNode.next;
            ChainNode<T> targetNode = this.headerNode;
            while (sourceNode != null) {
                newNode = new ChainNode<>(sourceNode.element, null);
                targetNode.next = newNode;
                targetNode = targetNode.next;
                sourceNode = sourceNode.next;
            }
        } else {
            this.headerNode = new ChainNode<>((T) theChain.headerNode.element, null);
            this.lastNode = this.headerNode;
        }
    }

    @Override
    public void clear() {
        // TODO I think this function is not mandatory
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
        return this.listSize == 0;
    }

    @Override
    public int size() {
        return this.listSize;
    }

    @Override
    public T get(int theIndex) {
        try {
            this.checkIndex(theIndex);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
            return null;
        }
        ChainNode<T> curNode = this.headerNode.next;
        byte index = 0;
        while (index != theIndex) {
            index++;
            curNode = curNode.next;
        }
        return curNode.element;
    }

    @Override
    public int indexOf(T theElement) {
        int index = 0;
        ChainNode<T> curNode = this.headerNode.next;
        while (curNode != null) {
            if (curNode.element == theElement) {
                return index;
            }
            index++;
            curNode = curNode.next;
        }
        return -1;
    }

    @Override
    public void erase(int theIndex) {
        try {
            this.checkIndex(theIndex);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
            return ;
        }
        int index = 0;
        ChainNode<T> curNode = this.headerNode;
        while (index != theIndex) {
            curNode = curNode.next;
            index++;
        }
        ChainNode<T> deleteNode = curNode.next;
        curNode.next = deleteNode.next;
        deleteNode.next = null;
        this.listSize--;
    }

    @Override
    public void insert(int theIndex, T theElement) {
        try {
            this.checkIndex(theIndex);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
            return ;
        }
        int index = 0;
        ChainNode<T> curNode = this.headerNode;
        while (index != theIndex) {
            curNode = curNode.next;
            index++;
        }
        curNode.next = new ChainNode<>(theElement, curNode.next);
        this.listSize++;
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
    ChainNode(T element, ChainNode<T> next) {
        this.element = element;
        this.next = next;
    }

    ChainNode() {

    }
}
