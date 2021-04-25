// Program losuje liczbę 0≤X≤100. Napisz funkcję, która zgaduje wartość X.
// W pętli losujemy n∈[0,100]. Jeżeli X=n zgadliśmy X, jeżeli nie na podstawie wartości X i n ograniczamy przedział,
// z którego losujemy kolejne n.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int x,      // zmienna losowana X
    n = -1,     // liczba zgadywana n
    lb = 0,     // dolna granica losowania n
    ub = 100,   // górna granica losowania n
    tc = 0;     // ilość prób zgadnięcia przez program (tak żeby cokolwiek printować...)

    srand(time(0)); // podanie ziarna losowania (zależne od momentu wykonania programu)

    x = rand() % (ub + 1) + lb; // losowanie X

    printf("\nWartosc X: %d\n\n", x);

    while (n != x) {    // pętla działa aż n == X
        n = rand() % (ub - lb + 1) + lb;

        printf("Zgadnieto n = %d\n", n);

        if (n < x) {
            lb = n;
            printf("Nowy zasieg losowania [%d, %d]\n", lb, ub);
        } else if (n > x) {
            ub = n;
            printf("Nowy zasieg losowania [%d, %d]\n", lb, ub);
        } else {
            printf("X znaleziona!\n");
        }

        tc++;
    }

    printf("\nZgadniecie zajelo %d prob\n", tc);
    return 0;
}
