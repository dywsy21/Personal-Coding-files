#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n], corre[8 * n];
    char str[n][8], catted_str[8 * n + 10], res_str[2 * n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Initialize str[n][8] to '0'
    for (int i = 0; i < n; i++)
        memset(str[i], '0', 8);

    // a[i] -> str[i][8]
    for (int i = 0; i < n; i++) {
        int p = 7, index = 0;
        while (a[i] >= (int)pow(2, p) && p >= 0) {
            str[i][index] = '0' + (a[i] >> p & 1);  // Corrected this line
            a[i] -= (int)pow(2, p);
            index++;
            p--;
        }
    }

    // str[n][8] -> catted_str
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < 8; q++)
            catted_str[8 * p + q] = str[p][q];
    }

    // Pad catted_str to be a multiple of 6
    int index = 0;
    while (strlen(catted_str) % 6 != 0) {
        catted_str[8 * n + index] = '0';
        index++;
    }

    // Calculate d
    int d = 0;
    while ((n + d) % 3 != 0)
        d++;

    // catted_str -> res_str
    for (int index_6 = 0; index_6 < strlen(catted_str) / 6; index_6++) {
        for (index = 0; index < 6; index++)
            corre[index_6] += (int)pow(2, catted_str[6 * index_6 + index] - '0');
    }

    // Update res_str length based on corre array
    for (int i = 0; i < strlen(catted_str) / 6; i++) {
        res_str[i] = (char)corre[i];  // Convert ASCII code to character
    }

    for (int i = strlen(catted_str) / 6; i <= strlen(catted_str) / 6 + d - 1; i++) {
        res_str[i] = '=';
    }

    // Print result
    puts(res_str);

    system("pause");
    return 0;
}
