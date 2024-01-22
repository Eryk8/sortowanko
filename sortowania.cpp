#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// sortowanie babelkowe funkcjaa
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // przesuwanie liczb 
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// sortowanie przez scalanie to jest funkcja
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // tymczasowe tablice
    int L[n1], R[n2];

    // Kopiowanie danych do tymczasowych tablic L[] i R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // Scalanie tymczasowych tablic z powrotem do arr[l..r]
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // kopoiwanie pozostalych elemntow L
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // kopiowanie pozostalych elementow R 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // srodek
        int m = l+(r-l)/2;

        // sortowanie jednej i drugiej polowy 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        // scalanie polowek
        merge(arr, l, m, r);
    }
}