// Szyfr Cezara polega na szyfrowaniu kolejnych liter (pozostałe znaki pozostawiamy bez zmian).
// Każda litera zostaje zamieniona w k-tą następną w alfabecie (k jest stałą szyfru),
// przy czym jeżeli taka nie istnieje (wychodzimy za 'z'), to odliczanie jest kontynuowane z powrotem od 'a'.
// Szyfrowanie zachowuje wielkość liter. Napisz funkcję, która szyfruje ciąg znaków podany jako argument.

#include <stdio.h>

int main(void) {
    int k;
    char string[256];

    printf("Podaj k: ");
    scanf("%d", &k);

    printf("Podaj słowo do zmiany: ");
    scanf("%s");

    return 0;
}