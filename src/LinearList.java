public abstract class LinearList<T> {
    public abstract boolean empty();
    public abstract int size();
    public abstract T get(int theIndex);
    public abstract int indexOf(final T theElement);
    public abstract void erase(int theIndex);
    public abstract void insert(int theIndex, final T theElement);
    public abstract void output();
}
