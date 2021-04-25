#include <stdio.h>

int main(void) {
    int n;
    int fts = 64;
    int fibtable[fts];

    fibtable[0] = 0;
    fibtable[1] = 1;

    for (int i = 2; i < fts; i++) {
        fibtable[i] = fibtable[i - 1] + fibtable[i - 2];
    }

    // Pobieranie danych od użytkownika
    printf("Podaj n: ");
    scanf("%d", &n);

    int i = 1;
    char loop = 1, isFibMulti = 1;
    while (loop) {
        if (fibtable[i] > n)
            loop = 0;

        if (n == fibtable[i] * fibtable[i - 1]) {
            printf("%d jest iloczynem %d i %d wyrazu ciagu fibonacciego.\n", n, i - 1, i);
            isFibMulti = 0;
        }

        i++;
    }

    if (isFibMulti)
        printf("%d nie jest iloczynem wyrazow ciagu fibonacciego.\n", n);

    return 0;
}