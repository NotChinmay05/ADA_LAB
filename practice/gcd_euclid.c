#include<stdio.h>
#include<time.h>

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b % a, a);
}

void main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    clock_t begin = clock();
    int result = gcd(a, b);
    printf("GCD of %d and %d = %d", a, b, result);

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime Taken: %f seconds\n", time_spent);
}
