#include <stdio.h>

int main() {
    int N;
    
    // Input the number of rows N
    printf("Enter the number of rows N: ");
    scanf("%d", &N);

    // Loop through rows
    for (int i = 0; i < N; i++) {
        // Loop through columns
        for (int j = 0; j < N; j++) {
            printf("* ");
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}
