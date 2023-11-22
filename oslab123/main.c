#include <stdio.h>

struct block {
    int id;
    int size;
    int alloc;
} b[10];

struct process {
    int id;
    int size;
    int bno;
} p[10];

int main() {
    int m, n, i, j, temp;

    printf("Enter the number of blocks: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter the block id and size %d: ", i + 1);
        scanf("%d %d", &b[i].id, &b[i].size);
        b[i].alloc = -1;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter process id and size: ");
        scanf("%d %d", &p[i].id, &p[i].size);
        p[i].bno=-1;
    }

    int choice;
    printf("Choose allocation strategy:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // First Fit
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    if (b[j].alloc == -1 && b[j].size >= p[i].size) {
                        p[i].bno = b[j].id;
                        b[j].alloc = 1;
                        break;
                    }
                }
            }
            break;

        case 2: // Best Fit
            for (i = 0; i < m; i++) {
                for (j = 0; j < m - 1 - i; j++) {
                    if (b[j].size > b[j + 1].size) {
                        temp = b[j + 1].size;
                        b[j + 1].size = b[j].size;
                        b[j].size = temp;
                    }
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    if (b[j].alloc == -1 && b[j].size >= p[i].size) {
                        p[i].bno = b[j].id;
                        b[j].alloc = 1;
                        break;
                    }
                }
            }
            break;

        case 3: // Worst Fit
            for (i = 0; i < m; i++) {
                for (j = 0; j < m - 1 - i; j++) {
                    if (b[j].size < b[j + 1].size) {
                        temp = b[j + 1].size;
                        b[j + 1].size = b[j].size;
                        b[j].size = temp;
                    }
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    if (b[j].alloc == -1 && b[j].size >= p[i].size) {
                        p[i].bno = b[j].id;
                        b[j].alloc = 1;
                        break;
                    }
                }
            }
            break;

        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("Process No\tBlock No\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", p[i].id, p[i].bno);
    }

    return 0;
}

