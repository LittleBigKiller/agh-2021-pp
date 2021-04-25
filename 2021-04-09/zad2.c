#include <stdio.h>

void print_2d(int *, int);

int count_neighbors(int *, int, int, int, int);

int main(void) {
    int n, r;

    // pobieranie pierwszej linijki danych
    scanf("%d %d", &n, &r);
    int inarr[n][n], outarr[n][n];

    // pobieranie zawartości tablicy NxN
    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            inarr[i][j] = x;
        }
    }

    // wywołanie funkcji liczącej sąsiadów dla każdej komórki
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outarr[i][j] = count_neighbors((int *) inarr, n, r, i, j);  // zapisanie danych o sąsiadach w tablicy
        }
    }

    // wypisanie tablicy sąsiadów
    print_2d((int *) outarr, n);

    return 0;
}

void print_2d(int *arr, int size) { // prosta funkcja pomocnicza wypisująca całą tablicę
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *((arr + i * size) + j));
        }
        printf("\n");
    }
}

int count_neighbors(int *arr, int size, int range, int arri, int arrj) {    // funkcja pomocnicza licząca sąsiadów
    int ctr = 0;    // licznik
    for (int i = arri - range; i <= arri + range; i++) {    // wybieramy sprawdzany wiersz w zakresie
        for (int j = arrj - range; j <= arrj + range; j++) {    // wybieramy sprawdzaną kolumne w zakresie
            if (i >= 0 && j >= 0 && i < size && j < size)   // sprawdzenie czy nie pobieramy danych z poza tablicy
                ctr += *((arr + i * size) + j); // dodajemy wartość komórki do licznika (skuteczne dla 0 i 1)
        }
    }

    return ctr;
}
