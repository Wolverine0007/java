#include<iostream>
using namespace std;

class Heap {
public:
    int arr[700];
    void getArray(int n);
    void printArray(int n);
    void maxHeapify(int arr[], int n, int i);
    void maxHeapSort(int arr[], int n);
    void minHeapify(int arr[], int n, int i);
    void minHeapSort(int arr[], int n);
};

void Heap::maxHeapify(int arr[], int n, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[max]) {
        max = left;
    }
    if (right < n && arr[right] > arr[max]) {
        max = right;
    }
    if (max != i) {
        swap(arr[i], arr[max]);
        maxHeapify(arr, n, max);
    }
}

void Heap::maxHeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void Heap::minHeapify(int arr[], int n, int i) {
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[min]) {
        min = left;
    }
    if (right < n && arr[right] < arr[min]) {
        min = right;
    }
    if (min != i) {
        swap(arr[i], arr[min]);
        minHeapify(arr, n, min);
    }
}

void Heap::minHeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

void Heap::getArray(int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void Heap::printArray(int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Heap h1;
    int n, a = 1;
    cout << "\n Heap Sort Program";
    while (a == 1) {
        cout << "\n -----------------------------------" << endl;
        cout << "\n Enter The Number of Elements: ";
        cin >> n;

        cout << "\n Enter The Array Elements: " << endl;
        h1.getArray(n);

        cout << "\n -----------------------------------" << endl;
        cout << "\n Array Before Sorting: " << endl;
        h1.printArray(n);

        cout << "\n Array After Sorting (Max Heapify): " << endl;
        h1.maxHeapSort(h1.arr, n);
        h1.printArray(n);

        cout << "\n Array After Sorting (Min Heapify): " << endl;
        h1.minHeapSort(h1.arr, n);
        h1.printArray(n);

        cout << "\n Do you want to continue? (1/0): ";
        cin >> a;
    }
    return 0;
}

//Output -
// Enter The Number of Elements: 10    

//  Enter The Array Elements:
// 12
// 54
// 68
// 21
// 36
// 52
// 72 
// 65
// 23
// 51

//  -----------------------------------

//  Array Before Sorting:
// 12 54 68 21 36 52 72 65 23 51

//  Array After Sorting (Max Heapify):
// 12 21 23 36 51 52 54 65 68 72

//  Array After Sorting (Min Heapify):
// 72 68 65 54 52 51 36 23 21 12

//  Do you want to continue? (1/0): 0