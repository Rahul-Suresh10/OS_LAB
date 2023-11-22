#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, nb, np;

    int bs[25], ps[25], alloc[25];

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of processes: ");
    scanf("%d", &np);

    // Input block sizes
    for (i = 0; i < nb; i++) {
        printf("Enter the size of block %d: ", i + 1);
        scanf("%d", &bs[i]);
    }

    // Input process sizes
    for (i = 0; i < np; i++) {
        printf("Enter the size of process %d: ", i + 1);
        scanf("%d", &ps[i]);
    }

    // Initialize allocation array with -1 (not allocated)
    for (i = 0; i < np; i++) {
        alloc[i] = -1;
    }

    // Allocate processes to blocks using Best Fit
    for (i = 0; i < np; i++) {
        int bestFitBlock = -1;
        for (j = 0; j < nb; j++) {
            if (ps[i] <= bs[j]) {
                if (bestFitBlock == -1 || bs[j] < bs[bestFitBlock]) {
                    bestFitBlock = j;
                }
            }
        }

        if (bestFitBlock != -1) {
            alloc[i] = bestFitBlock;
            bs[bestFitBlock] -= ps[i];
        }
    }

    // Print allocation details
    printf("PROCESS NO\tPROCESS SIZE\tBLOCK NO\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, ps[i]);
        if (alloc[i] != -1) {
            printf("%d\n", alloc[i] + 1);
        } else {
            printf("Not allocated\n");
        }
    }

    return 0;
}

