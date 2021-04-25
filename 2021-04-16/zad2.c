#include <stdio.h>
#include <malloc.h>

void print_2d(int **, int);

int count_perimeter_sum(int **, int, int, int, int);

int main(void) {
    int n, k;   // rozmiar tablicy, poszukiwana suma

    // pobieranie pierwszej linijki danych
    scanf("%d %d", &n, &k);

    // alokowanie tablicy nxn
    int **arr = (int **) malloc((unsigned) n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *) malloc((unsigned) n * sizeof(int));

    // alokowanie tablicy na koordynaty
    int **coarr = malloc(sizeof(int *)); // deklarowanie jako nullptr powodowało crash, ten hack to naprawia

    // pobieranie zawartości tablicy NxN
    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            arr[i][j] = x;
        }
    }

    int square_ctr = 0; // licznik pasujących kwadratów
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int rng = 1;    // zasięg poszukiwania (ile od środka jest krawędź)
            int perimeter_sum = count_perimeter_sum(arr, n, rng, i, j);
            while (perimeter_sum != -1) {   // pętla powiększająca zasięg szukania, aż przestanie się mieścić
                if (perimeter_sum == k) {
                    square_ctr++;

                    // tablica coarr trzyma koordynaty środków, powiększamy ją o 1, dopisujemy 'i' i 'j'
                    coarr = (int **) realloc(coarr, (unsigned) square_ctr * sizeof(int *));
                    coarr[square_ctr - 1] = (int *) malloc((unsigned) 2 * sizeof(int));

                    coarr[square_ctr - 1][0] = i;
                    coarr[square_ctr - 1][1] = j;
                }
                rng++;
                perimeter_sum = count_perimeter_sum(arr, n, rng, i, j);
            }
        }
    }

    printf("%d\n", square_ctr);
    for (int i = 0; i < square_ctr; i++)
        printf("%d %d\n", coarr[i][0], coarr[i][1]);

    // zwalnianie tablicy nxn
    for (int i = 0; i < n; i++)
        if (arr[i])
            free(arr[i]);
    if (arr)
        free(arr);

    // zwalnianie tablicy koordynatów
    for (int i = 0; i < square_ctr; i++)
        if (coarr[i])
            free(coarr[i]);
    if (coarr)
        free(coarr);

    return 0;
}

// prosta funkcja pomocnicza wypisująca całą tablicę
void print_2d(int **arr, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// funkcja pomocnicza licząca sumę na obwodzie
int count_perimeter_sum(int **arr, int size, int range, int arri, int arrj) {
    if (arri - range < 0 || arri + range >= size || arrj - range < 0 || arrj + range >= size)
        return -1;  // jeśli sprawdzany się nie mieści, zwróć informację, że się nie zmieścił (ujemną sumę)

    int ctr = 0;    // licznik sumy
    // liczenie pionowych sum
    for (int i = arri - range; i <= arri + range; i++) {
        ctr += arr[i][arrj - range];
        ctr += arr[i][arrj + range];
    }
    // liczenie poziomych sum
    for (int j = arrj - range; j <= arrj + range; j++) {
        ctr += arr[arri - range][j];
        ctr += arr[arri + range][j];
    }
    // odejmowanie narożników, bo policzone były dwa razy...
    ctr -= arr[arri - range][arrj - range];
    ctr -= arr[arri - range][arrj + range];
    ctr -= arr[arri + range][arrj - range];
    ctr -= arr[arri + range][arrj + range];

    return ctr;
}
