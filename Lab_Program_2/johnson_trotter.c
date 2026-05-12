#include <stdio.h>

#define LEFT -1
#define RIGHT 1

struct node {
    int value;
    int dir;
};

int getMobile(struct node a[], int n) {
    int mobile = -1;
    int mobile_index = -1;

    for (int i = 0; i < n; i++) {
        if (a[i].dir == LEFT && i != 0 && a[i].value > a[i-1].value && a[i].value > mobile) {
            mobile = a[i].value;
            mobile_index = i;
        }

        if (a[i].dir == RIGHT && i != n-1 && a[i].value > a[i+1].value && a[i].value > mobile) {
            mobile = a[i].value;
            mobile_index = i;
        }
    }
    return mobile_index;
}

void printPermutation(struct node a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i].value);
    }
    printf("\n");
}

void johnsonTrotter(int n) {
    struct node a[n];
    for (int i = 0; i < n; i++) {
        a[i].value = i + 1;
        a[i].dir = LEFT;
    }

    printPermutation(a, n);

    while (1) {
        int mobile_index = getMobile(a, n);

        if (mobile_index == -1)
            break;

        int swap_index = mobile_index + a[mobile_index].dir;

        struct node temp = a[mobile_index];
        a[mobile_index] = a[swap_index];
        a[swap_index] = temp;

        mobile_index = swap_index;

        for (int i = 0; i < n; i++) {
            if (a[i].value > a[mobile_index].value) {
                a[i].dir = -a[i].dir;
            }
        }

        printPermutation(a, n);
    }
}

void main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);
    printf("\n");
}
