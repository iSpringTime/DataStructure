import jdk.jshell.Snippet;
import org.jetbrains.annotations.NotNull;

public class ChainExercise<T extends Comparable<T>> extends Chain<T>{

    // P124 15
    void reverse()
    {
          ChainNode<T> preNode = null;
          ChainNode<T> curNode = this.headerNode.next;
          ChainNode<T> nxtNode = curNode.next;
          while (curNode != null) {
              curNode.next = preNode;
              preNode = curNode;
              curNode = nxtNode;
              if (nxtNode != null) {
                  nxtNode = nxtNode.next;
              }
          }
          this.headerNode.next = preNode;
      }
      // P125 20
      Chain<T> merge(@NotNull Chain<T> theChain) {
          Chain<T> meltChain = new Chain<>();
          ChainNode<T> mergePreNode = null;
          ChainNode<T> mergeNxtNode = null;
          ChainNode<T> fCurNode = this.headerNode.next;
          ChainNode<T> sCurNode = theChain.headerNode.next;
          while (fCurNode != null && sCurNode != null) {
              if (fCurNode.element.compareTo(sCurNode.element) < 0) {
                  if (mergePreNode == null) {
                      mergePreNode = fCurNode;
                  }
                  mergeNxtNode = fCurNode;
                  fCurNode = fCurNode.next;
              } else {
                  if (mergePreNode == null) {
                      mergePreNode = sCurNode;
                  }
                  mergeNxtNode = sCurNode;
                  sCurNode = sCurNode.next;
              }
              mergePreNode.next = mergeNxtNode;
              mergePreNode = mergePreNode.next;

          }
          if (fCurNode == null && sCurNode != null) {
              assert mergeNxtNode != null;
              mergeNxtNode.next = sCurNode;
              meltChain.lastNode = this.lastNode;
          } else if (fCurNode != null && sCurNode == null) {
              assert mergeNxtNode != null;
              mergeNxtNode.next = fCurNode;
              meltChain.lastNode = theChain.lastNode;
          } else {
              meltChain.lastNode = mergePreNode;
          }
          meltChain.headerNode.next = this.headerNode.next;
          meltChain.listSize = this.listSize + theChain.listSize;
          this.headerNode.next = null;
          theChain.headerNode.next = null;
          return meltChain;
      }

      // P125 22
      void split(@NotNull Chain<T> a, @NotNull Chain<T> b) {
          ChainNode<T> sNode = this.headerNode.next;
          ChainNode<T> fNode = sNode.next;
          a.headerNode.next = fNode;
          b.headerNode.next = sNode;
          while (sNode.next.next != null && fNode.next.next != null) {
              sNode.next = sNode.next.next;
              fNode.next = fNode.next.next;
              fNode = fNode.next;
              sNode = sNode.next;
          }
          if (fNode.next == null) {
              sNode.next = null;
          } else {
              sNode.next = fNode.next;
              fNode.next = null;
          }
      }

      // P125 23
      void circularShift(int leftShift) {
          try {
              if (leftShift < 0 || leftShift > this.listSize) {
                  throw new ArrayIndexOutOfBoundsException("out of border");
              } else if (leftShift == 0) {
                  return ;
              }
          } catch (Exception e) {
              System.out.println(e.getMessage());
              return ;
          }
          ChainNode<T> curNode = this.headerNode;
          int theIndex = 0;
          while (theIndex < leftShift) {
              curNode = curNode.next;
              theIndex++;
          }
          this.lastNode.next = this.headerNode.next;
          this.headerNode.next = curNode.next;
          curNode.next = null;
      }
}
