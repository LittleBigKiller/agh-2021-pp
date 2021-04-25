#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRMAX 128

// Deklaracje tablic o odpowiednich maksymalnych długościach i inicjowanie ich na wartość 0
int t1[ARRMAX] = {0};
int t2[ARRMAX] = {0};
int t3[ARRMAX * 2] = {0};

void reverse(int[], int);

int one_two(int[], int, int[], int, int[]);

// Deklaracje funkcji pomocniczych
void merge(int[], int, int, int);

void mergeSort(int[], int, int);

void printArray(int[], int);

// Początek programu
int main(void) {
    // inicjowanie pseudolosowości
    time_t tt;
    int seed = time(&tt);
    srand(seed);

    int N1, N2; // deklaracja zmiennych przechowujących faktyczne długości tablic

    // pobieranie długości tablic
    printf("Podaj rozmiar pierwszej tablicy N1: ");
    scanf("%d", &N1);

    printf("Podaj rozmiar drugiej tablicy N2: ");
    scanf("%d", &N2);

    // wypełnianie tablicy 1 na wybraną długość losowymi liczbami
    int i = 0;
    while (i < N1) {
        t1[i] = rand() % 10;
        i++;
    }

    // wypełnianie tablicy 2 na wybraną długość losowymi liczbami
    i = 0;
    while (i < N2) {
        t2[i] = rand() % 10;
        i++;
    }

    printf("Initial state of arrays:\n");
    printArray(t1, N1);
    printArray(t2, N2);

    mergeSort(t1, 0, N1 - 1);
    mergeSort(t2, 0, N2 - 1);

    printf("Arrays after sorting:\n");
    printArray(t1, N1);
    printArray(t2, N2);

    reverse(t1, N1);
    reverse(t2, N2);

    printf("Reversed arrays:\n");
    printArray(t1, N1);
    printArray(t2, N2);

    reverse(t1, N1);
    reverse(t2, N2);

    printf("Arrays returned to normal for one_two():\n");
    printArray(t1, N1);
    printArray(t2, N2);

    int N3 = one_two(t1, N1, t2, N2, t3);
    printf("Final array, result of one_two:\n");
    printArray(t3, N3);

    return 0;
}

void reverse(int arr[], int l) {
    int i = 0;
    while (i < l / 2) { // przejście przez wartości od 0 do połowy tablicy i zamiana elementów o 'i' od krawędzi
        // Zamiana w miejscu bez zmiennej pomocniczej przez dodawanie i odejmowanie wartości
        arr[i] += arr[l - 1 - i];
        arr[l - 1 - i] = arr[i] - arr[l - 1 - i];
        arr[i] -= arr[l - 1 - i];
        i++;
    }
}

int one_two(int arr1[], int l1, int arr2[], int l2, int arr3[]) {
    int i = 0;  // counter pierwszej tablicy
    int j = 0;  // counter drugiej tablicy
    int k = 0;  // counter trzeciej tablicy
    while (i < l1 && j < l2) {
        if (i == 0 && j == 0) { // hack na wpisanie pierwszego elementu, bo dalsze sprawdzenia nie działają jeśli
            if (arr1[i] < arr2[j]) {    // żadna tablica nie zaczyna się od 0
                arr3[k] = arr1[i];  // dopisanie do arr3
                i++;
            } else {
                arr3[k] = arr2[j];  // dopisanie do arr3
                j++;
            }
        }
        if (arr1[i] < arr2[j]) {    // sprawdzanie czy aktualna z arr1 jest mniejsza od aktualnej z arr2
            if (arr1[i] > arr3[k]) {    // sprawdzanie czy aktualna z arr1 jest większa od poprzedniej z arr3
                k++;
                arr3[k] = arr1[i];  // dopisanie do arr3
            }
            i++;
        } else if (arr2[j] < arr1[i]) { // sprawdzanie czy aktualna z arr2 jest mniejsza od aktualnej z arr1
            if (arr2[j] > arr3[k]) {    // sprawdzanie czy aktualna z arr2 jest większa od poprzedniej z arr3
                k++;
                arr3[k] = arr2[j];  // dopisanie do arr3
            }
            j++;
        } else { // w przypadku kiedy są równe
            if (arr1[i] > arr3[k]) {    // sprawdzanie czy aktualna z arr2 jest większa od poprzedniej z arr3
                k++;
                arr3[k] = arr1[i];  // dopisanie do arr3
            }
            i++;
            j++;
        }
    }

    // dopisywanie pozostałych z arr1
    while (i < l1) {
        if (arr1[i] > arr3[k]) {
            k++;
            arr3[k] = arr1[i];
        }
        i++;
    }

    // dopisywanie pozostałych z arr2
    while (j < l2) {
        if (arr2[j] > arr3[k]) {
            k++;
            arr3[k] = arr2[j];
        }
        j++;
    }
    k++;    // zwiększenie countera o jeden, bo wskazywał ostatni element, nie długość tablicy

    return k;
}

// Funkcje pomocnicze
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
