#include <stdio.h>
#include <time.h>                                                                                                                                                                    #include <stdio.h>

int main() {
    int n, i, j, min, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    // Selection Sort
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        // Swap
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    clock_t end = clock();

    double time_taken = ((end - start) / CLOCKS_PER_SEC);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime Taken: %f ms", time_taken);

    return 0;
}
