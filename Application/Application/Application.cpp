#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
/////////////////////////////Алгоритмы поиска в неупорядоченных массивах
template <typename T>
unsigned linear_search(T* arr, const unsigned sz, T des)
{
    unsigned comp_num = 0;
    unsigned i;
    for (i = 0; i < sz; i++)
    {
		comp_num++;
        if(arr[i] == des) break;
    }
    return comp_num;
}

template <typename T>
unsigned fast_linear_search_for_disordered(T* arr, const unsigned sz, T des)
{
    unsigned comp_num = 0;
	int* new_array = new int[sz + 1];
	new_array[sz] = des;
	for (unsigned j = 0; j < sz; j++)
	{
		new_array[j] = arr[j];
	}
    unsigned i;
    for (i = 0; ; i++)
    {
        comp_num++;
		if (new_array[i] == des)
		{
			if (i == sz) break;     //Элемент не найден
			else break;             //Элемент найден
		}
    }
	delete[] new_array;
    return comp_num;
}

/////////////////////////////Алгоритмы поиска в упорядоченных массивах
template <typename T>
unsigned fast_linear_search_for_ordered(T* arr, const unsigned sz, T des)
{
	unsigned comp_num = 0;
	int* new_array = new int[sz + 1];
	new_array[sz] = des;
	for (unsigned j = 0; j < sz; j++)
	{
		new_array[j] = arr[j];
	}
	unsigned i;
	for (i = 0; ; i++)
	{
		if (new_array[i] > des) break;    //В массиве нет элемента
		comp_num++;
		if (new_array[i] == des)
		{
			if (i == sz) break;     //Элемент не найден
			else break;             //Элемент найден
		}
	}
	delete[] new_array;
	return comp_num;
}

unsigned binary_search(int* arr, const unsigned R, int des, const unsigned L = 1, unsigned comp_num = 1)
{
	unsigned l = L;
	unsigned r = R;
    unsigned middle = (l + r) / 2;
	unsigned count = comp_num;
	count++;
	if (arr[middle] > des)
	{
		count = binary_search(arr, r, des, middle, count);
	}
	else
	{
		count++;
		if (arr[middle] < des)
		{
			count = binary_search(arr, middle, des, l, count);
		}
	}
	return count;
}

int main()
{
	setlocale(0, "");
	const unsigned SIZE = 20;
    using namespace std;
    int disordered_array[SIZE];
    unsigned i;
    int j;
    srand(time(NULL));
    for (unsigned i = 0; i < SIZE; i++)
    {
        disordered_array[i] = rand();
        disordered_array[i] %= 500;     //генерация случайных чисел в диапазоне до 500
    }
	/////////////////////////////Создание упорядоченного массива
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
	/////////////////////////////Вывод массивов на экран
    for (i = 0; i < SIZE; i++)
        cout << "[" << i + 1 << "] = " << disordered_array[i] << " ";
    cout << endl << endl;
    for (i = 0; i < SIZE; i++)
        cout << "[" << i + 1 << "] = " << ordered_array[i] << " ";
    cout << endl;
	
	int desired_element;
	cout << "Введите элемент, который требуется найти --> ";
	cin >> desired_element;
	binary_search(ordered_array, SIZE, desired_element);
	cout << "Число сравнений --> " << endl;
    
    return 0;
}

