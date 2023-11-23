#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

void expand_array(int** array, int extra_num, int* array_size) {
    (*array_size)++;
    *array = (int*)realloc(*array, (*array_size) * sizeof(int));
    (*array)[(*array_size) - 1] = extra_num;  // Write at the correct index
}

void is_prime(int* array, int* num, int* array_size) {
    for (int i = 0; i < *array_size; i++) {
        if ((*num) % (array[i]) == 0) {
            (*num)++;
            return;
        }
    }
    expand_array(&array, *num, array_size);
    (*num)++;
}

int main() {
    int* array = (int*)malloc(3 * sizeof(int));
    int array_size = 3;
    array[0] = 2; array[1] = 3; array[2] = 5;
    int num = 6;

    while (num < MAXSIZE) {
        is_prime(array, &num, &array_size);
    }
    for (int i = 0; i < array_size; i++) printf("%d ", array[i]);

    free(array);

    system("pause");
    return 0;
}
