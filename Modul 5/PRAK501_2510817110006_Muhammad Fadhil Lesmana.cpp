#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void insertionSort(string &arr) {
    int n = arr.length();
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "\nHasil Insertion Sort (Nama) : " << arr << endl;
}

void merge(string &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    string L = "", R = "";
    for (int i = 0; i < n1; i++) L += arr[l + i];
    for (int j = 0; j < n2; j++) R += arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSortRec(string &arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortRec(arr, l, m);
    mergeSortRec(arr, m + 1, r);
    merge(arr, l, m, r);
}

void mergeSort(string arr) {
    mergeSortRec(arr, 0, arr.length() - 1);
    cout << "\nHasil Merge Sort (Nama)   : " << arr << endl;
}

void shellSort(string &arr) {
    int n = arr.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            char temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    cout << "\nHasil Shell Sort (Nama)   : " << arr << endl;
}

int partition(string &arr, int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortRec(string &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortRec(arr, low, pi - 1);
        quickSortRec(arr, pi + 1, high);
    }
}

void quickSort(string arr) {
    quickSortRec(arr, 0, arr.length() - 1);
    cout << "\nHasil Quick Sort (NIM)    : " << arr << endl;
}

void bubbleSort(string &arr) {
    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "\nHasil Bubble Sort (NIM)   : " << arr << endl;
}

void selectionSort(string &arr) {
    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
    cout << "\nHasil Selection Sort (NIM): " << arr << endl;
}

int main() {
    string nama, nim;
    int pilihan;

    cout << "Masukkan Nama Anda : ";
    getline(cin, nama);
    cout << "Masukkan NIM Anda  : ";
    cin >> nim;

    do {
        cout << "\n----------------------------\n";
        cout << ":         SORTING          :\n";
        cout << "----------------------------\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Shell Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Bubble Sort\n";
        cout << "6. Selection Sort\n";
        cout << "7. Exit\n";
        cout << "----------------------------\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: insertionSort(nama); break;
            case 2: mergeSort(nama); break;
            case 3: shellSort(nama); break;
            case 4: quickSort(nim); break;
            case 5: bubbleSort(nim); break;
            case 6: selectionSort(nim); break;
            case 7: 
                cout << "\nKeluar dari program...\n"; 
                break;
            default: 
                cout << "\nPilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilihan != 7);
    return 0;
}