import java.util.*;

public class SortClass {
    public static void sort(int a[], int low, int hight) {
        int i, j, index;
        if (low > hight) {
            return;
        }
        i = low;
        j = hight;
        index = a[i]; // 用子表的第一个记录做基准
        while (i < j) { // 从表的两端交替向中间扫描
            while (i < j && a[j] >= index)
                j--;
            if (i < j)
                a[i++] = a[j];// 用比基准小的记录替换低位记录
            while (i < j && a[i] < index)
                i++;
            if (i < j) // 用比基准大的记录替换高位记录
                a[j--] = a[i];
        }
        a[i] = index;// 将基准数值替换回 a[i]
        sort(a, low, i - 1); // 对低子表进行递归排序
        sort(a, i + 1, hight); // 对高子表进行递归排序

    }

    public static void quickSort(int a[]) {

        qSort(a, 0, a.length - 1);
    }

    public static void swap(int[] array, int a, int b) {
        int tmp;

        tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
    }

    public static void qSort(int[] array, int top, int tail) {
        int posi;
        if (top < tail) {
            posi = partition(array,top,tail);
            qSort(array, top, posi - 1);
            qSort(array, posi + 1, tail);
        }
    }

    public static int partition(int[] array, int top, int tail) {
        int tmp = array[top];
        while (top < tail) {
            while ((top < tail)&&(array[tail] >= tmp)) {
                tail--;
            }
            swap(array,top,tail);
            while ((top < tail)&&(array[top] <= tmp)) {
                top++;
            }
            swap(array,top,tail);
        }
        return top;
    }

    public static void main(String[] args) {

        int[] a = { 49, 38, 65, 97, 76, 13, 27, 59 };
        quickSort(a);
        System.out.println(Arrays.toString(a));
    }
}