#include <stdio.h>
#include <time.h>

int fib(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;

    return fib(n-1) + fib(n-2);
}

void main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    clock_t begin = clock();
    int result = fib(n);
    clock_t end = clock();
    double time_spent = (end - begin) / CLOCKS_PER_SEC;

    printf("Fib(%d) = %d", n, result);
    printf("\nTime Taken: %f seconds", time_spent);
}
