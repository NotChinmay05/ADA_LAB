#include <stdio.h>
#include <time.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n-1, source, destination, auxiliary);

    printf("Move disk %d from %c to %c\n", n, source, destination);

    towerOfHanoi(n-1, auxiliary, source, destination);
}

void main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    clock_t begin = clock();
    towerOfHanoi(n, 'A', 'B', 'C');
    clock_t end = clock();

    double time_spent = (end - begin) / CLOCKS_PER_SEC;
    printf("Time Taken: %f seconds", time_spent);
}
