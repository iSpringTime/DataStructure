#include "queue.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "malloc.h"
#include "math.h"

#define ARRY_SIZE 100
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

int delSameElem(int arr[], int num, int new_arr[]) 
{
    int i;
    int newArryLen = 0;

    bool flag[ARRY_SIZE] = {0};
    for (i = 0;i < num;i++) {
        if(flag[arr[i]] == false) {
            new_arr[newArryLen++] = arr[i];
            flag[arr[i]] = true;
        }
    }
    return newArryLen;
}

bool delSameElemInsort(int arr[], int length, int *newLength)
{
    if(arr == NULL || length == 0) {
        return false;
    }

    int count = 1;
    for (int i = 1;i < length;i++) {
        if (arr[i] == arr[i - 1]) {
            continue;
        } else {
             arr[count++] = arr[i];
        }
    }
    *newLength = count;
    return true;
}
