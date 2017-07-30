#include <stdlib.h>
#include <stdio.h>

void swap(int * a, int * b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void percolate_down(int a[], int n, int i)
{
    int val = a[i];
    for(int j = 2 * i + 1; j < n; i = j, j = 2 * i + 1)
    {
        if(j + 1 < n && a[j + 1] > a[j])
            j++;

        if(val >= a[j])
            break;

        a[i] = a[j];
    }
    a[i] = val;
}

void percolate_up(int a[], int i)
{
    int val = a[i];
    for(int j = (i - 1) / 2; i > 0; i = j, j = (i - 1) / 2)
    {
        if(val <= a[j])
            break;
        a[i] = a[j];
    }
    a[i] = val;
}

void print(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%5d ", a[i]);
    }
    printf("\n");
}

void makeheap(int a[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        percolate_down(a, n, i);
    }
}

void heapsort(int a[], int n)
{
    makeheap(a, n);
    for(int i = 1; i < n; i++)
    {
        swap(a, a + n - i);
        percolate_down(a, n - i, 0);
    }
}

int main(int argc, char* argv[])
{
    int a[10] = {543,6,45,7,6538,65,31,4257,1,5};
    print(a, 10);
    heapsort(a, 10);
    print(a, 10);
    return 0;
}