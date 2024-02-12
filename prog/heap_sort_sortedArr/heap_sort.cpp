#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    for (int size = 1000; size <= 50000; size += 1000) {
        int* arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }

        auto start = high_resolution_clock::now();

        heapSort(arr, size);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << size << " " << duration.count() << endl;

        delete[] arr;
    }

    return 0;
}