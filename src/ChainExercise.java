import org.jetbrains.annotations.NotNull;

public class ChainExercise<T extends Comparable<T>> extends Chain<T>{
      public Chain<T> melt(@NotNull Chain<T> theChain) {
          Chain<T> meltChain = new Chain<>();
          ChainNode<T> meltPreNode = null;
          ChainNode<T> meltNxtNode = null;
          ChainNode<T> fCurNode = this.headerNode.next;
          ChainNode<T> sCurNode = theChain.headerNode.next;
          while (fCurNode != null && sCurNode != null) {
              if (fCurNode.element.compareTo(sCurNode.element) < 0) {
                  if (meltPreNode == null) {
                      meltPreNode = fCurNode;
                  }
                  meltNxtNode = fCurNode;
                  fCurNode = fCurNode.next;
              } else {
                  if (meltPreNode == null) {
                      meltPreNode = sCurNode;
                  }
                  meltNxtNode = sCurNode;
                  sCurNode = sCurNode.next;
              }
              meltPreNode.next = meltNxtNode;
              meltPreNode = meltPreNode.next;

          }
          if (fCurNode == null && sCurNode != null) {
              meltNxtNode.next = sCurNode;
              meltChain.lastNode = this.lastNode;
          } else if (fCurNode != null && sCurNode == null) {
              meltNxtNode.next = fCurNode;
              meltChain.lastNode = theChain.lastNode;
          } else {
              meltChain.lastNode = meltPreNode;
          }
          meltChain.headerNode.next = this.headerNode.next;
          meltChain.listSize = this.listSize + theChain.listSize;
          this.headerNode.next = null;
          theChain.headerNode.next = null;
          return meltChain;
      }
}
