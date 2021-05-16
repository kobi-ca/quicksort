//
// Created by kobi on 5/8/21.
//

/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

// Driver Code
int main()
{
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        {
            int arr[] = {2, 5, 9, 7, 4, 3, 6, 5, 1, 1, 10, 11};
            int n = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, n - 1);
            const auto s = std::is_sorted(std::begin(arr), std::end(arr));
            std::clog << std::boolalpha << s << '\n';
            if (!s) {
                printArray(arr, n);
            }
        }

        {
            int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
            int n = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, n - 1);
            const auto s = std::is_sorted(std::begin(arr), std::end(arr));
            std::clog << std::boolalpha << s << '\n';
            if (!s) {
                printArray(arr, n);
            }
        }

        {
            int arr[] = {10, 10, 10, 10, 10};
            int n = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, n - 1);
            const auto s = std::is_sorted(std::begin(arr), std::end(arr));
            std::clog << std::boolalpha << s << '\n';
            if (!s) {
                printArray(arr, n);
            }
        }

        {
            int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int n = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, n - 1);
            const auto s = std::is_sorted(std::begin(arr), std::end(arr));
            std::clog << std::boolalpha << s << '\n';
            if (!s) {
                printArray(arr, n);
            }
        }

        {
            int arr[] = {10, 10, 10, 9, 9, 9, 8, 8, 7, 6};
            int n = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, n - 1);
            const auto s = std::is_sorted(std::begin(arr), std::end(arr));
            std::clog << std::boolalpha << s << '\n';
            if (!s) {
                printArray(arr, n);
            }
        }

        {
            int arr[] = {10, 10, 10, 9, 9, 9, 8, 8, 7, 6, 7, 8, 9, 10, 11};
            int n = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, n - 1);
            const auto s = std::is_sorted(std::begin(arr), std::end(arr));
            std::clog << std::boolalpha << s << '\n';
            if (!s) {
                printArray(arr, n);
            }
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::clog << "diff " << (end - start).count() << '\n';
    return 0;
}

// This code is contributed by rathbhupendra
