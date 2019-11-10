import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

public class Chain<T extends Comparable<T>> extends ExtendLinearList<T> {

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

    public ChainNode<T> getNodeOfIndex(int theIndex) {
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
        return curNode;
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

    ChainNode<T> eraseNode(int theIndex) {
        try {
            this.checkIndex(theIndex);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
            return null;
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
        return deleteNode;
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

    void insert(int theIndex, ChainNode<T> oneNode) {
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
        oneNode.next = curNode.next;
        curNode.next = oneNode;
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

    // P126 26
    public void insert(int theIndex, ChainNode<T> insertNode, boolean decrease) {
        ChainNode<T> curNode = this.headerNode.next;
        ChainNode<T> preNode = this.headerNode;
        int index;
        for (index = theIndex; index > 0 && decrease ? insertNode.element.compareTo(curNode.element) < 0 :insertNode.element.compareTo(curNode.element) > 0; index--) {
            curNode = curNode.next;
            preNode = preNode.next;
        }
        if (theIndex != 0 && index != 0) {
            if (index == theIndex) {
                while (curNode.next != insertNode) {
                    curNode = curNode.next;
                }
                curNode.next = insertNode.next;
                insertNode.next = this.headerNode.next;
                this.headerNode.next = insertNode;
            } else {
                while (curNode.next != insertNode) {
                    curNode = curNode.next;
                }
                curNode.next = insertNode.next;
                insertNode.next = preNode.next;
                preNode.next = insertNode;
            }
        }
    }

    public void insertSort(boolean decrease) {
        ChainNode<T> curNode;
        for (int sortCount = 0; sortCount < this.listSize; sortCount++) {
            curNode = this.getNodeOfIndex(sortCount);
            this.insert(sortCount, curNode, decrease);
        }
    }

    // P126 27 (1)
    void bubbleSort(boolean decrease) {
        ChainNode<T> curNode;
        ChainNode<T> tmpNode;
        for (int times = this.listSize-1; times > 0; times--) {
            ChainNode<T> maxNode = this.headerNode.next;
            curNode = maxNode.next;
            tmpNode = maxNode;
            for (int theIndex = 1; theIndex <= times; theIndex++) {
                if (decrease ? maxNode.element.compareTo(curNode.element) > 0 : maxNode.element.compareTo(curNode.element) < 0) {
                    maxNode = curNode;
                }
                curNode = curNode.next;
                tmpNode = tmpNode.next;
            }
            curNode = tmpNode;
            if (maxNode == this.headerNode.next) {
                this.headerNode.next = maxNode.next;
                maxNode.next = curNode.next;
                curNode.next = maxNode;
            } else if (maxNode == curNode) {
                continue;
            } else {
                ChainNode<T> preNode = this.headerNode;
                while (preNode.next != maxNode) {
                    preNode = preNode.next;
                }
                preNode.next = maxNode.next;
                if (curNode == this.lastNode) {
                    maxNode.next = null;
                    curNode.next = maxNode;
                    this.lastNode = maxNode;
                } else {
                    maxNode.next = curNode.next;
                    curNode.next = maxNode;
                }
            }
        }
    }

    // P126 27 (2)
    /*
    Needn't move ChainNode like bubbleSort, we could only move element to rearrange the element.
     */
    void selectionSort(boolean decrease) {
        ChainNode<T> curNode;
        ChainNode<T> tmpNode;
        for (int times = this.listSize-1; times > 0; times--) {
            ChainNode<T> maxNode = this.headerNode.next;
            curNode = maxNode.next;
            tmpNode = maxNode;
            for (int theIndex = 1; theIndex <= times; theIndex++) {
                if (decrease ? maxNode.element.compareTo(curNode.element) > 0 : maxNode.element.compareTo(curNode.element) < 0) {
                    maxNode = curNode;
                }
                curNode = curNode.next;
                tmpNode = tmpNode.next;
            }
            curNode = tmpNode;
            T tmp;
            tmp = curNode.element;
            curNode.element = maxNode.element;
            maxNode.element = tmp;
        }
    }

    // P126 27 (3)
    /*
    ranking the
     */
    void rankSort(boolean decrease) {
        int[] index = new int[this.listSize];
        ChainNode<T> curNode = this.headerNode.next;
        for (int times = 0; times < this.listSize; times++) {
            ChainNode<T> tmpNode = this.headerNode.next;
            for (int theIndex = 0; theIndex < this.listSize; theIndex++) {
                if (decrease ? curNode.element.compareTo(tmpNode.element) < 0 : curNode.element.compareTo(tmpNode.element) > 0) {
                    index[times]++;
                } else if (curNode.element.compareTo(tmpNode.element) == 0 && theIndex < times) {
                    index[times]++;
                }
                tmpNode = tmpNode.next;
            }
            curNode = curNode.next;
        }
        curNode = this.headerNode.next;
        Chain<T> newChain = new Chain<>();
        for (int theIndex = 0; theIndex < this.listSize; theIndex++) {
            ChainNode<T> tmpNode = curNode;
            for (int i = 0; i < this.listSize; i++) {
                if (index[i] == theIndex) {
                    newChain.push_back(tmpNode.element);
                    continue;
                }
                tmpNode = tmpNode.next;
            }
        }
        this.headerNode.next = newChain.headerNode.next;
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
