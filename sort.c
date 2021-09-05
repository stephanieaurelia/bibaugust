#include "main.h"

void merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    for(int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[i + left];
    }
    for(int i = 0; i < rightSize; i++)
    {
        rightArr[i] = arr[i + mid + 1];
    }

    int idx = left;
    int idxL = 0;
    int idxR = 0;

    while(idxL < leftSize && idxR < rightSize)
    {
        if(leftArr[idxL] < rightArr[idxR])
        {
            arr[idx] = leftArr[idxL];
            idx++;
            idxL++;
        }
        else
        {
            arr[idx] = rightArr[idxR];
            idx++;
            idxR++;
        }
    }

    while(idxL < leftSize)
    {
        arr[idx] = leftArr[idxL];
        idx++;
        idxL++;
    }

    while(idxR < rightSize)
    {
        arr[idx] = rightArr[idxR];
        idx++;
        idxR++;
    }

}

void split(int arr[], int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    split(arr, left, mid);
    split(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void sort(int arr[], int n)
{
    split(arr, 0, n - 1);
}
