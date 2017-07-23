#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<typename T>
    string _itoa(T t)
{
    stringstream ss;
    ss << t;
    return ss.str();
}

template<typename T>
void print(T a[], size_t n)
{
    for(size_t idx = 0; idx < n; idx++)
        cout << " " << a[idx];

    cout << endl;
}

template<typename T>
void _swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

template<typename T>
bool _less(T a, T b)
{
    string a_str = _itoa(a);
    string b_str = _itoa(b);
    return (a_str + b_str) < (b_str + a_str);
}

template<typename T>
bool _greater(T a, T b)
{
    string a_str = _itoa(a);
    string b_str = _itoa(b);

    return (a_str + b_str) > (b_str + a_str);
}

//////////////////////////////////////////////////
int partition_first(int a[], int left, int right)
{
    int i = left;
    int j = right + 1;
    int key = a[left];
    while(1)
    {
        while(i < right && _less(a[++i], key));
        while(_greater(a[--j], key));
        if(i >= j)
        {
            break;
        }
        _swap(a[i], a[j]);
    }

    _swap(a[left], a[j]);
    
    return j;
}

int partition_last(int a[], int left, int right)
{
    int i = left - 1;
    int j = right;
    int key = a[right];

    while(1)
    {
        while(_less(a[++i], key));
        while(j > left && _greater(a[--j], key));
        if(i >= j)
        {
            break;
        }

        _swap(a[i], a[j]);
    }
    
    _swap(a[i], a[right]);
    return i;
}

int partition_three(int a[], int left, int right)
{
    int i = left - 1;
    int j = left;
    int key = a[right];

    while(j < right)
    {
        if(_less(a[j], key))
        {
            i++;
            _swap(a[i], a[j]);
        }
        j++;
    }
    
    i++;
    _swap(a[i], a[right]);
    return i;
}

////////////////////////////////////////////////

typedef int (*pf_partition_t)(int [], int, int);
pf_partition_t fun_partition = NULL;

///////////////////////////////////////////////

void qsort(int a[], int left, int right)
{
    if(left >= right)
        return;
    
    int pivot = fun_partition(a, left, right);
    qsort(a, left, pivot - 1);
    qsort(a, pivot + 1, right);
}

int main(int argc, char* argv[])
{
    fun_partition = partition_first;

    int a[] = {9, 99, 98, 321, 32, 899};
    int n = sizeof(a) / sizeof(*a);
    print(a, n);

    qsort(a, 0, n - 1);

    print(a, n);
    return 0;
}