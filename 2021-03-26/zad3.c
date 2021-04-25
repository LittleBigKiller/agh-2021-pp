#include <stdio.h>

#define ARRSIZE 10

void print_nums(int[], int, int, unsigned short);

int main(void) {
    int arr[ARRSIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, n = ARRSIZE, k;
    unsigned short wybor;

    printf("Podaj k:");
    scanf("%d", &k);

    printf("Czy w przod (false=0 / true=1):");
    scanf(" %hu", &wybor);

    print_nums(arr, n, k, wybor);

    return 0;
}

void print_nums(int arr[], int n, int k, unsigned short wprzod) {
    printf("%u\n", wprzod);
    if (wprzod) {
        for (int i = k; i < n; i++) {
            printf("%d ", arr[i]);
        }
        for (int i = 0; i < k; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        for (int i = k; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
        for (int i = n - 1; i > k; i--) {
            printf("%d ", arr[i]);
        }
    }
}
