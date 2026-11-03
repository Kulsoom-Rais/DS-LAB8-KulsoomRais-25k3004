#include <iostream>
using namespace std;

int swaps = 0;

void swapElements(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

    swaps++;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swapElements(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);

    cout << "\nMax Heap: ";
    display(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swapElements(arr[0], arr[i]);

        cout << "\nAfter extraction: ";
        display(arr, n);

        heapify(arr, i, 0);

        cout << "After heapify: ";
        display(arr, n);
    }
}

int main()
{
    int arr[] = {42, 17, 63, 28, 51, 9, 36, 74, 23};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    display(arr, n);

    heapSort(arr, n);

    cout << "\nFinal Sorted Array: ";
    display(arr, n);

    cout << "\nTotal Swaps: " << swaps << endl;

    return 0;
}
