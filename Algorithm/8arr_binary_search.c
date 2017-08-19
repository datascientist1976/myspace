#include <stdio.h>
#include <stdlib.h>

void print(int a[], int left, int right)
{
    for(int idx = left; idx <= right; idx++)
    {
        printf("%5d ", a[idx]);
    }
    printf("\n");
}

int upper_bound(int a[], int left, int right, int key)
{
    while(left < right)
    {
        int m = (left + right) >> 1;
        if(a[m] <= key)
            left = m + 1;
        else
            right = m;
    }

    if(a[left] > key)
        return left;
    
    return -1;
}

int lower_bound(int a[], int left, int right, int key)
{
    while(left < right)
    {
        int m = (left + right) >> 1;
        if(a[m] >= key)
            right = m;
        else
            left = m + 1;
    }

    if(a[left] >= key)
        return left;

    return -1;
}

int binary_search_nodup(int a[], int left, int right, int key)
{
    while(left <= right)
    {
        int m = (left + right) >> 1;
        if(a[m] == key) return m;
        else if(a[left] <= a[m]) //when m=left, a[l] == a[m]
        {
            if(a[left] <= key && key < a[m])
                right = m - 1;
            else
                left = m + 1;
        }
        else //right part is sorted
        {
            if(a[m] < key && key <= a[right])
                left = m + 1;
            else
                right = m - 1;
        }
    }
    return -1;
}

int binary_search_withdup(int a[], int left, int right, int key)
{
    while(left <= right)
    {
        int m = (left + right) >> 1;
        if(a[m] == key) return m;
        else if(a[left] < a[m])
        {
            if(a[left] <= key && key < a[m])
                right = m - 1;
            else
                left = m + 1;
        }
        else if(a[left] > a[m])//right part is sorted
        {
            if(a[m] < key && key <= a[right])
                left = m + 1;
            else
                right = m - 1;
        }
        else
        {
            if(a[m] != a[right])
            {
                left = m + 1;
            }
            else
            {
                left++;
            }
        }
    }
    return -1;
}

int findMin(int a[], int left, int right)
{
    while(left < right)
    {
        int m = (left + right) >> 1;
        if(a[m] > a[right])
            left = m + 1;
        else if(a[m] < a[right])
            right = m;
        else
            right--;
    }
    return left;
}

int main(int argc, char* argv[])
{
    //int arr[] = {1,2,3,4,5,65,67,89,100,102,999};
    //int arr[] = {1024,2453,9872,1,2,3,4,5,65,67,89,100,102,999};
    int arr[] = {1024,1024,1024,2453,9872,1,2,3,4,5,65,67,67,89,100,102,999,1024};
    const int sz = sizeof arr / sizeof *arr;
    print(arr, 0, sz - 1);
    printf("nodup find:%d\n", binary_search_withdup(arr, 0, sz-1, 77));
    return 0;
}