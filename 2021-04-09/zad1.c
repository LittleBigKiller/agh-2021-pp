#include <stdio.h>

int multiply_numbers(int, int *, int);

void factorial(int);

#define RESSIZE 512

int main(void) {
    int n;

    printf("Podaj n:\n");
    scanf("%d", &n);

    factorial(n);

    return 0;
}

int multiply_numbers(int x, int *bn, int rs) {
    int carry = 0;  // zmienna przechowująca "nadwyżkę"

    // Mnożenie każdej kolejnej cyfry bn przez x
    for (int i = 0; i < rs; i++) {
        // mnożenie cyfry naszej dużej liczby (bn = big number) przez naszą mniejszą liczbę i dodawanie "nadwyżki"
        int dig = bn[i] * x + carry;

        // zapisanie ostatniej cyfry wyniku poprzedniej operacji w odpowiednim miejscu tablicy wynikowej
        bn[i] = dig % 10;

        // zapisanie "nadwyżki"
        carry = dig / 10;
    }

    // umieszczenie reszty "nadwyżki" w tablicy wynikowej i zmiana długości tablicy wynikowej
    while (carry) {
        bn[rs] = carry % 10;
        carry = carry / 10;
        rs++;
    }

    return rs;
}

void factorial(int n) {
    // deklaracja i inicjalizacja tablicy wynikowej (przechowującej silnie od tyłu)
    int res[RESSIZE];
    res[0] = 1;
    int res_size = 1;

    // użycie formuły na silnie czyli n! = 1 * 2 * ... * n
    for (int i = 2; i <= n; i++) {
        res_size = multiply_numbers(i, res, res_size);
    }

    // wypisanie od tyłu naszej tablicy wynikowej
    for (int i = res_size - 1; i >= 0; i--)
        printf("%d", res[i]);
}
