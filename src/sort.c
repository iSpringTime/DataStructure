#include "queue.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "malloc.h"
#include "math.h"

//初始化
//开始必然是空队列，队尾指针和队头指针都指向头结点
void swap(int *left, int *right)
{
    int tmp;

    tmp = *right;
    *right = *left;
    *left = tmp;
}

void BubbleSort2(int arr[], int num)
{
    int k = num;
    int j;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (j = 1; j < k; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j - 1], &arr[j]);
                flag = true;
            }
        }
        k--;
    }
}

void qsort(int a[], int left, int right)
{
    int i, j, pivot;
    pivot = a[right];   //the last item as pivot
    i = left;
    j = right - 1;
    if (left < right)
    {
    for (; ;)
    {
        for (; a[i] < pivot; i++);
        for (; a[j] > pivot; j--);
        if (i < j)
        swap(&a[i], &a[j]);
        else
        break;
        }
        swap(&a[i], &a[right]); //now i is the pivot index in the array
        qsort(a, left, i - 1);
        qsort(a, i + 1, right);
    }
}

