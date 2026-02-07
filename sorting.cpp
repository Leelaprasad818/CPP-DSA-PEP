#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr, int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(vector<int> &arr, int n){
    for(int i = 0; i < n - 1; i++){
        cout << "Pass " << i + 1 << endl;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                cout << "Swapped index " << j << " and " << j + 1 << ": ";
                printArray(arr, n);
            }
        }
    }
}

void selectionSort(vector<int> &arr, int n){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        cout << "Selecting position " << i << endl;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(arr[i], arr[minIndex]);
            cout << "Swapped index " << i << " and " << minIndex << ": ";
            printArray(arr, n);
        }
    }
}

void insertionSort(vector<int> &arr, int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        cout << "Inserting element at index " << i << endl;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
            printArray(arr, n);
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
}

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    cout << "Pivot: " << pivot << endl;
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
            cout << "Swapped index " << i << " and " << j << ": ";
            printArray(arr, arr.size());
        }
    }
    swap(arr[i + 1], arr[high]);
    cout << "Swapped pivot to correct position: ";
    printArray(arr, arr.size());
    return i + 1;
}

void quickSortHelper(vector<int> &arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int> &arr, int n){
    quickSortHelper(arr, 0, n - 1);
}

void merge(vector<int> &arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        cout << "Merging: ";
        printArray(arr, arr.size());
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
        cout << "Left remain: ";
        printArray(arr, arr.size());
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
        cout << "Right remain: ";
        printArray(arr, arr.size());
    }
}

void mergeSortHelper(vector<int> &arr, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(vector<int> &arr, int n){
    mergeSortHelper(arr, 0, n - 1);
}

bool isSorted(vector<int> arr, int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]) return false;
    }
    return true;
}

int main(){
    int n;
    cout << "Enter len of arr : ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(isSorted(arr, n)){
        cout << "Array is Sorted ASC";
    } else {
        bool sort;
        cout << "Do sort (1/0): ";
        cin >> sort;
        if(sort){
            int option;
            cout << "SELECT OPTION : 1:bubble 2:selection 3:insertion 4:quick 5:merge sorting method : ";
            cin >> option;
            if(option == 1) bubbleSort(arr, n);
            else if(option == 2) selectionSort(arr, n);
            else if(option == 3) insertionSort(arr, n);
            else if(option == 4) quickSort(arr, n);
            else if(option == 5) mergeSort(arr, n);
            cout << "Final Sorted Array: ";
            printArray(arr, n);
        }
    }
    return 0;
}
