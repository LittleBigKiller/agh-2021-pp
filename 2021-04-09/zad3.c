#include <stdio.h>

void print_spiral(int *, int);

int main(void) {
    int n, ctr = 1;

    // pobieranie rozmiaru spirali
    printf("Podaj rozmiar spirali n: ");
    scanf("%d", &n);

    int spiral[n][n];

    int rc = 0, cc = 0; // Licznik aktualnego wiersza i kolumny
    int rl = 1, ru = n - 1, cl = 0, cu = n - 1; // Granice wiersza i kolumny (dolna i górna)

    while (1) { // pętla główna, przerywana przez wewnętrzny warunek
        while (cc < cu) {   // kroki "dodatnio" po kolumnach i wpisywanie wartości ctr
            spiral[rc][cc] = ctr;
            ctr++;
            cc++;
        }
        cu--;   // zmniejszenie górnego limitu kolumn

        if (ru < rl && cu < cl) break;  // sprawdzenie czy limity zostały zmniejszone w niemożliwy sposób i koniec pętli

        while (rc < ru) {    // kroki "dodatnio" po wierszach i wpisywanie wartości ctr
            spiral[rc][cc] = ctr;
            ctr++;
            rc++;
        }
        ru--;   // zmniejszenie górnego limitu wierszy

        if (ru < rl && cu < cl) break;  // sprawdzenie czy limity zostały zmniejszone w niemożliwy sposób i koniec pętli

        while (cc > cl) {   // kroki "ujemnie" po kolumnach i wpisywanie wartości ctr
            spiral[rc][cc] = ctr;
            ctr++;
            cc--;
        }
        cl++;   // zwiększenie dolnego limitu kolumn

        if (ru < rl && cu < cl) break;  // sprawdzenie czy limity zostały zmniejszone w niemożliwy sposób i koniec pętli

        while (rc > rl) {   // kroki "ujemnie" po wierszach i wpisywanie wartości ctr
            spiral[rc][cc] = ctr;
            ctr++;
            rc--;
        }
        rl++;   // zwiększenie dolnego limitu wierszy

        if (ru < rl && cu < cl) break;  // sprawdzenie czy limity zostały zmniejszone w niemożliwy sposób i koniec pętli
    }
    spiral[rc][cc] = ctr;

    print_spiral((int *) spiral, n);

    return 0;
}

void print_spiral(int *arr, int size) { // prosta funkcja pomocnicza wypisująca całą spiralę
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *((arr + i * size) + j));
        }
        printf("\n");
    }
}
