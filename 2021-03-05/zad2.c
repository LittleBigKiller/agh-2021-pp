// Napisz program, który wczytuje liczbę całkowitą N a następnie oblicza i drukuje na ekran wartość N!.
// Uwaga: silnia bardzo szybko powoduje przepełnienie całkowitoliczbowe.
// Sprawdź dla jakich wartości N program wyprowadza prawidłowy wynik.
// Przetestuj działanie programu dla różnych typów danych (dla ułatwienia można zastosować definicję typedef).

#include <stdio.h>

int main(void) {
    typedef unsigned long long ullong;  // Definiowanie skrótowej nazwy typu

    int n;  // zmienna wejściowa N
    ullong fact = 1;    // zmienna przechowująca obliczenia N!

    // Pobieranie danych od użytkownika
    printf("\nPodaj N: ");
    scanf("%d", &n);

    printf("%d! wynosi: ", n);

    while (n > 0) {
        fact *= n;
        n--;
    }

    // wyznaczona metodą prób i błędów maksymalna liczba N dla której program działa:   N = 65

    printf("%llu\n", fact);
    return 0;
}