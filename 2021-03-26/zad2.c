#include <stdio.h>
#define ARRSIZE 10

int main(void) {
    int ti[ARRSIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, *pi;
    double td[ARRSIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0}, *pd;

    pi = &ti[0];
    pd = &td[0];

    printf("%p\n", (void *) pi);
    printf("%p\n", (void *) pd);

    printf("Tablica intow:\n");
    for (int i = 0; i < ARRSIZE; i++) {
        printf("pointer = %p, value = %d\n", (void *) (pi + i), *(pi + i));
    }

    printf("Tablica doubli:\n");
    for (int i = 0; i < ARRSIZE; i++) {
        printf("pointer = %p, value = %.1lf\n", (void *) (pd + i), *(pd + i));
    }

    return 0;
}
