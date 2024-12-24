#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;       // largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

// Heap-Sort algorithm
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        // Call heapify
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {33, 1, 125, 18, 79, 10};

    cout << "Unsortd array --> ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted array --> ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
