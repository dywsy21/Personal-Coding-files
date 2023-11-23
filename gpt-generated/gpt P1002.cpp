#include <stdio.h>

long long int countPaths(int bx, int by, int hx, int hy) {
    long long int dp[21][21] = {0}; // Initialize a 2D array for dynamic programming

    // Set the starting point
    dp[0][0] = 1;

    // Mark the horse's position as unreachable
    dp[hx][hy] = 0;

    // Calculate paths using dynamic programming
    for (int i = 0; i <= bx; i++) {
        for (int j = 0; j <= by; j++) {
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }

    return dp[bx][by];
}

int main() {
    int bx, by, hx, hy;
    printf("Please input the coordinates (Bx By Hx Hy):\n");
    scanf("%d%d%d%d", &bx, &by, &hx, &hy);

    long long int result = countPaths(bx, by, hx, hy);

    printf("%lld\n", result);

    return 0;
}

