
#include <stdio.h>

int main() {
    int n, b[20], r[20], w[20], t[20];
    int q, time = 0, done, i;
    float aw = 0, at = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Burst time P%d: ", i + 1);
        scanf("%d", &b[i]);
        r[i] = b[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &q);

    if (n < 1 || n > 20 || q <= 0) {
        printf("Invalid input\n");
        return 1;
    }

    do {
        done = 1;
        for (i = 0; i < n; i++) {
            if (r[i] > 0) {
                done = 0;
                if (r[i] > q) {
                    time += q;
                    r[i] -= q;
                } else {
                    time += r[i];
                    w[i] = time - b[i];
                    r[i] = 0;
                }
            }
        }
    } while (!done);

    printf("\nProcess\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        t[i] = b[i] + w[i];
        aw += w[i];
        at += t[i];
        printf("P%d\t%d\t%d\t%d\n",
               i + 1, b[i], w[i], t[i]);
    }

    printf("Average WT = %.2f\n", aw / n);
    printf("Average TAT = %.2f\n", at / n);

    return 0;
}
