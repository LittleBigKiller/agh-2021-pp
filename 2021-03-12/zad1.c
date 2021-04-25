#include <stdio.h>

char isPerfect(int a);  // deklaracja funkcji pomocniczej

int main(void) {
    int lb, ub;      // podana przez granice przedzialu

    // Pobieranie danych od użytkownika
    printf("Podaj dolna granice przedzialu do sprawdzenia lb: ");
    scanf("%d", &lb);

    printf("Podaj gorna granice przedzialu do sprawdzenia ub: ");
    scanf("%d", &ub);

    int pc = 0, i = lb;
    while (i <= ub) {  // pętla wywołująca funkcje pomocniczą na każdej liczbie z przedziału i zliczająca ilość liczb doskonałych
        if (isPerfect(i)) { //
            printf("%d jest doskonala.\n", i);
            pc += 1;
        }
        i++;
    }

    printf("\nW przedziale [%d, %d] znajduja sie %d liczby doskonale.\n", lb, ub, pc);

    return 0;
}

char isPerfect(int a) { // pomocnicza funkcja sprawdzająca czy liczba jest doskonała
    if (a == 1)
        return 0;

    int divsum = 1;

    int i = 2;
    while (i * i <= a) {    // sprawdzamy każdą liczbę mniejszą lub równą pierwiastkowi z a, czy nie jest dzielnikiem
        if (a % i == 0) {
            if (i != a / i) {
                divsum += i + a / i;    // jeżeli jest dzielnikiem a nie jest pierwiastkiem to dopisujemy do sumy ją i wynik z dzielenia przez nią
            } else {
                divsum += i;    // jeżeli jest dzielnikiem i pierwiastkiem z liczby to dodajemy ją do sumy tylko raz
            }
        }
        i++;
    }

    return (char) (a == divsum);    // sprawdzamy czy suma równa się pierwotnej liczbie
}