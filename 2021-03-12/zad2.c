#include <stdio.h>

char isPrime(int a);  // deklaracja funkcji pomocniczej
char isPrimest(int a);  // deklaracja funkcji pomocniczej

int main(void) {
    int n;      // podana przez granice przedzialu

    // Pobieranie danych od użytkownika
    printf("Podaj n: ");
    scanf("%d", &n);

    int pc = 0, i = 2;
    while (i <= n) {  // pętla wywołująca funkcje pomocniczą na każdej liczbie z przedziału i zliczająca ilość liczb doskonałych
        if (isPrimest(i)) { //
            printf("%d jest najpierwsza.\n", i);
            pc += 1;
        }
        i++;
    }

    return 0;
}

char isPrime(int a) { // pomocnicza funkcja sprawdzająca czy liczba jest pierwsza
    if (a == 1)
        return 0;

    int i = 2;
    while (i * i <= a) {    // sprawdzamy każdą liczbę mniejszą lub równą pierwiastkowi z a, czy nie jest dzielnikiem
        if (a % i == 0) {
            return 0;
        }
        i++;
    }

    return 1;
}

char isPrimest(int a) {
    if (!isPrime(a))
        return 0;

    int i = a, prev = 99;   // liczba najmniejsza ustawiona na
    while (i != 0) {
        if (i % 10 < prev) {
            prev = i % 10;
        } else {
            return 0;
        }
        i /= 10;
    }

    return 1;
}