#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1E5

int comp_used_for_one_dimensional_arrays(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}
//const void*使得该函数能够接收所有类型的数据，之所以是指针是因为qsort要改变主参
//(int*)是因为a，b在定义时为void，必须强制给个类型，外面再来个*是为了去数值
//升序：前减后，降序：后减前

int comp_used_for_two_dimensional_arrays_comparing_columns(const void* a,const void*b){
    return (*(int**)a)[0] - (*(int**)b)[0];
}

//const void* 只需要一个*即可，具体是几维指针留待后面决定
//此函数的意义：要排列的是一个二维数组m*n的第一列(所以用[0])
//一整行跟着一起动，故给第一列排序时每一行也跟着一起被调换了

/*至于为什么是比较第一列而不是第一行：

当`b`是指向二维数组中的一行的指针，具体地说是指向整数数组（一行）的指针时：

1. `(int**)b` 将 `b` 强制类型转换为指向整数指针的指针，将 `b` 解释为指向整数数组的指针。
2. `(*(int**)b)` 对指向指针的指针进行解引用，得到整数数组（一行）。
3. `(*(int**)b)[0]` 然后访问这个数组的第一个元素，实际上是原始二维数组中第一列的值。

因此，`(*(int**)b)[0]` 允许你在 `b` 是指向一行的指针时访问二维数组的第一列。*/

int** qsort_examples(int* one_dimensional_array, int two_dimensional_array[3][2], 
                    int one_dimensional_array_size, int two_dimensional_array_column_size){

//qsort格式：要被排序的数列，该数列大小（相应行或列个数），
//sizeof(int or int*)（取决于一维还是二维)，比较函数
    int** temp_array_for_ordering = (int**)malloc(two_dimensional_array_column_size * sizeof(int*));
    int t = 0;
    for (int i = 0; i < two_dimensional_array_column_size; i++) {
            temp_array_for_ordering[i] = two_dimensional_array[i];
        }

    qsort(one_dimensional_array,one_dimensional_array_size,sizeof(int),comp_used_for_one_dimensional_arrays);
    qsort(temp_array_for_ordering,two_dimensional_array_column_size,sizeof(int*),comp_used_for_two_dimensional_arrays_comparing_columns);
    return temp_array_for_ordering;
}

int main() {
    int one_dimensional_array_eg[5] = {5, 2, 8, 1, 3};
    int two_dimensional_array_eg[3][2] = {
        {3, 2},
        {1, 5},
        {2, 3}
    };


    int one_dimensional_array_size = sizeof(one_dimensional_array_eg) / sizeof(int);
    int two_dimensional_array_column_size = sizeof(two_dimensional_array_eg) / sizeof(two_dimensional_array_eg[0]);
    int** ans_two_dimensional_array = (int**)malloc(two_dimensional_array_column_size * sizeof(int*));

    // Call the qsort_examples function
    ans_two_dimensional_array=qsort_examples(one_dimensional_array_eg, two_dimensional_array_eg,
                    one_dimensional_array_size, 
                    two_dimensional_array_column_size);

    // Print the sorted arrays
    printf("Sorted One-dimensional Array: ");
    for (int i = 0; i < one_dimensional_array_size; i++) {
        printf("%d ", one_dimensional_array_eg[i]);
    }
    printf("\n");

    printf("Sorted Two-dimensional Array: \n");
    for (int i = 0; i < two_dimensional_array_column_size; i++) {
        printf("%d %d\n", ans_two_dimensional_array[i][0], ans_two_dimensional_array[i][1]);
    }

    system("pause");
    return 0;
}
