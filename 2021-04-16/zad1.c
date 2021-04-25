#include <stdio.h>
#include <malloc.h>

int count_sum(int **, int, int, int, int, int);

int main(void) {
    int n;   // rozmiar tablicy, poszukiwana suma

    // pobieranie pierwszej linijki danych
    scanf("%d", &n);

    // alokowanie tablicy nxn
    int **arr = (int **) malloc((unsigned) n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *) malloc((unsigned) n * sizeof(int));

    // pobieranie zawartości tablicy NxN
    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            arr[i][j] = x;
        }
    }

    int max_size = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            int rngi = 0;    // zasięg poszukiwania (ile od i jest krawędź i)
            int rngj = 0;    // zasięg poszukiwania (ile od j jest krawędź j)
            int cur_size = 0;   // zmienna przechowująca rozmiar aktualnie sprawdzanego pola

            int field_sum = count_sum(arr, n, rngi, rngj, i, j);
            while (field_sum == 0) {    // pętla działająca do czasu, aż pole będzie nieprawidłowe
                cur_size = (rngi + 1) * (rngj + 1); // przypisanie rozmiaru aktualnie sprawdzanego pola
                if (cur_size > max_size)    // sprawdzenie czy aktualne jest większe od maksymalnego
                    max_size = (rngi + 1) * (rngj + 1); // przypisanie nowego maksymalnego
                rngi++; // zwiększenie zasięgu poszukiwań
                field_sum = count_sum(arr, n, rngi, rngj, i, j);    // policzenie sumy nowego pola
            }
            if (rngi > 0) rngi--;   // jeśli pole w i można zmniejszyć, zmniejsz i kontynuuj
            else continue;  // jeśli pole 1x1 ma sumę 1, rozpocznij szukanie na nowo

            field_sum = 0;    // poprzednia suma musiała być poprawna

            // poniższa pętla działa analogicznie to poprzedniej, tylko na miejscu w rzędzie zamiast w kolumnie
            while (field_sum == 0) {
                cur_size = (rngi + 1) * (rngj + 1);
                if (cur_size > max_size)
                    max_size = (rngi + 1) * (rngj + 1);
                rngj++;
                field_sum = count_sum(arr, n, rngi, rngj, i, j);
            }
        }
    }

    // zwracanie wyniku w konsoli
    printf("%d\n", max_size);

    // zwalnianie tablicy nxn
    for (int i = 0; i < n; i++)
        if (arr[i])
            free(arr[i]);
    if (arr)
        free(arr);

    return 0;
}

int count_sum(int **arr, int size, int rngi, int rngj, int arri, int arrj) {    // funkcja pomocnicza licząca sumę
    if (arri + rngi >= size || arrj + rngj >= size)
        return -1;  // jeśli się nie mieści w nxn, zwróć informację, że się nie zmieścił (ujemną sumę)

    int ctr = 0;    // licznik sumy
    for (int i = arri; i <= arri + rngi; i++) {    // wybieramy sprawdzany wiersz w zakresie
        for (int j = arrj; j <= arrj + rngj; j++) {    // wybieramy sprawdzaną kolumne w zakresie
            ctr += arr[i][j]; // dodajemy wartość komórki do licznika (skuteczne dla 0 i 1)
        }
    }

    return ctr;
}
