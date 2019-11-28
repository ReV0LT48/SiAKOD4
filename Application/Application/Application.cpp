#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
/////////////////////////////Алгоритмы поиска в неупорядоченных массивах
template <typename T>
unsigned linear_search(T* arr, const unsigned sz, T des)
{
    unsigned comp_num = 1;
    unsigned i;
    for (i = 0; i < sz; i++, comp_num++)
    {
        if(arr[i] == des) break;
    }
    return comp_num;
}

template <typename T>
unsigned fast_linear_search_for_disorederd(T* arr, const unsigned sz, T des)
{
    unsigned comp_num = 0;
    unsigned fsz = sz;
    fsz += 1;
    arr[fsz] = des;
    unsigned i;
    for (i = 0; ; i++)
    {
        comp_num++;
        if(arr[i] == des && i != fsz) break;
        comp_num++;
        if(i == fsz) break;
    }
    return comp_num;
}

/////////////////////////////Алгоритмы поиска в упорядоченных массивах
template <typename T>
unsigned fast_linear_search_for_ordered(T* arr, const unsigned sz, T des)
{
    
}

int main()
{
    using namespace std;
    const unsigned SIZE = 20;
    int disordered_array[SIZE];
    unsigned i;
    int j;
    srand(time(NULL));
    for (unsigned i = 0; i < SIZE; i++)
    {
        disordered_array[i] = rand();
        disordered_array[i] %= 500;     //генерация случайных чисел в диапазоне до 500
    }
    int ordered_array[SIZE];
    for (i = 0; i < SIZE; i++) ordered_array[i] = disordered_array[i];
    for (i = 1; i < SIZE; i++)
    {
        for (j = i; j > 0 && ordered_array[j - 1] > ordered_array[j]; j--)
        {
            int temp = ordered_array[j];
            ordered_array[j] = ordered_array[j - 1];
            ordered_array[j - 1] = temp;
        }
    }
    for (i = 0; i < SIZE; i++)
        cout << "[" << i + 1 << "] = " << disordered_array[i] << " ";
    cout << endl;
    for (i = 0; i < SIZE; i++)
        cout << "[" << i + 1 << "] = " << ordered_array[i] << " ";
    cout << endl;
    
    return 0;
}
