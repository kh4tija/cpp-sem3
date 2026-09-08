#include "array.h"
#include <iostream>
using namespace std;

template <class T>
array<T>::array()
{
    lb = 1;
    ub = 0;
}

template <class T>
void array<T>::setLB(int x)
{
    lb = x;
}

template <class T>
void array<T>::setUB(int x)
{
    ub = x;
}

template <class T>
void array<T>::create()
{
    cout << "Enter " << (ub - lb + 1) << " elements: ";

    for (int i = lb; i <= ub; i++)
    {
        cin >> a[i];
    }
}

template <class T>
void array<T>::display()
{
    for (int i = lb; i <= ub; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

// Bubble Sort
template <class T>
void array<T>::bubbleSort()
{
    for (int i = lb; i < ub; i++)
    {
        for (int j = lb; j < ub - (i - lb); j++)
        {
            if (a[j] > a[j + 1])
            {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
template <class T>
void array<T>::insertionSort()
{
    for (int i = lb + 1; i <= ub; i++)
    {
        T key = a[i];
        int j = i - 1;

        while (j >= lb && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Selection Sort
template <class T>
void array<T>::selectionSort()
{
    for (int i = lb; i < ub; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j <= ub; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        T temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

// Merge
template <class T>
void array<T>::merge(int low, int mid, int high)
{
    T temp[100];

    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}

// Merge Sort Helper
template <class T>
void array<T>::mergeSortHelper(int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        mergeSortHelper(low, mid);
        mergeSortHelper(mid + 1, high);

        merge(low, mid, high);
    }
}

// Merge Sort
template <class T>
void array<T>::mergeSort()
{
    mergeSortHelper(lb, ub);
}

// Partition for Quick Sort
template <class T>
int array<T>::partition(int low, int high)
{
    T pivot = a[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;

            T temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    T temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

// Quick Sort Helper
template <class T>
void array<T>::quickSortHelper(int low, int high)
{
    if (low < high)
    {
        int p = partition(low, high);

        quickSortHelper(low, p - 1);
        quickSortHelper(p + 1, high);
    }
}

// Quick Sort
template <class T>
void array<T>::quickSort()
{
    quickSortHelper(lb, ub);
}