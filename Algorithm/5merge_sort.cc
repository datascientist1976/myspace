#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
void print(T a[], int left, int right)
{
    for(int idx = left; idx <= right; idx++)
    {
        cout << " " << setw(5) << a[idx];
    }
    cout << endl;
}

int merge(int a[], int t[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int result = 0;
    for(; i <= mid && j <= right;)
    {
        if(a[i] <= a[j])
        {
            t[k++] = a[i++];
        }
        else
        {
            t[k++] = a[j++];
            result += mid - i + 1;
        }
    }

    while(i <= mid) t[k++] = a[i++];
    while(j <= right) t[k++] = a[j++];

    for(int i = left; i <= right; i++)
    {
        a[i] = t[i];
    }

    return result;
}

int merge_sort(int a[], int t[], int left, int right)
{
    if(left >= right)
	    return 0;
    
    int m = (left + right) / 2;
    return  merge_sort(a, t, left, m) + merge_sort(a, t, m + 1, right) + merge(a, t, left, m, right);
}

int main(int argc,char* argv[])
{
    int a[10] = {9,12,2343,1,41,43,345,145,654,9713};
    int t[10];
    print(a, 0, 9);
    int reverse_order_num = merge_sort(a, t, 0, 9);
    print(a, 0, 9);
    cout << "reverse_order_num:" << reverse_order_num << endl;
    return 0;
}
