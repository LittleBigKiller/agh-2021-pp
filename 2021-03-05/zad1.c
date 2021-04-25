// Paragon fiskalny zawiera następujące informacje: cenę jednostkową netto a, liczbę zakupionych sztuk towaru x
// oraz wysokość podatku VAT podaną w procentach p. Napisz program, który wczytuje powyższe dane z klawiatury,
// a następnie oblicza wartość netto zakupionego towaru, wartość podatku VAT oraz wartość towaru brutto.
// Wyniki obliczeń należy wypisać na ekranie w formie uproszczonego "paragonu fiskalnego".

#include <stdio.h>

int main(void) {
    float a,    // cena towaru i zmienna używana przy obliczeniach
    p,  // procent podatku VAT
    x,  // liczba zakupionych sztuk
    net = 0,    // wartość netto
    vat = 0,    // wartość podatku VAT
    brut = 0;   // wartość brutto

    // Pobieranie danych od użytkownika
    printf("Podaj cene netto jednej sztuki a: ");
    scanf("%f", &a);

    printf("Podaj ilosc produktow x: ");
    scanf("%f", &x);

    printf("Podaj wysokosc VAT w procentach p: ");
    scanf("%f", &p);


    // obliczenia konkretnych wartosci
    net = a * x;
    vat = net * (p / 100); // podzielenie na 100, żeby uzyskać wartość liczbową procentów
    brut = net + vat;

    // wypis paragonu
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\tPARAGON:\n");
    printf("\n");
    printf("Cena jednostkowa:\t%.2f\tPLN\n", a);
    printf("Ilosc:\t\t\t%.0f\tszt.\n", x);
    printf("VAT:\t\t\t%.0f  \t%%\n", p);
    printf("Wartosc Netto:\t\t%.2f\tPLN\n", net);
    printf("Wartosc podatku VAT:\t%.2f\tPLN\n", vat);
    printf("Wartosc Brutto:\t\t%.2f\tPLN\n", brut);
    return 0;
}