#include <stdio.h>

int main() {
    int n = 5, m = 3;

    int allocation[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int available[3] = {3, 3, 2};

    int need[5][3];
    int finish[5] = {0};
    int safeSequence[5];
    int work[3];

    // Calculate Need Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize Work = Available
    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    int count = 0;

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {

            if (finish[i] == 0) {

                int j;

                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                // If all resources can be allocated
                if (j == m) {

                    for (int k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }

                    safeSequence[count] = i;
                    count++;

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process could be allocated
        if (found == 0) {
            printf("\nSystem is NOT in a safe state.\n");
            return 0;
        }
    }

    // Print Safe Sequence
    printf("\nSystem is in a SAFE state.\n");
    printf("Safe Sequence: ");

    for (int i = 0; i < n; i++) {
        printf("P%d", safeSequence[i]);

        if (i != n - 1) {
            printf(" -> ");
        }
    }

    printf("\n");

    return 0;
}