/*给你一个餐馆信息数组 restaurants，
其中restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]。
你必须使用以下三个过滤器来过滤这些餐馆信息。

其中素食者友好过滤器 veganFriendly 的值可以为 true 或者 false，
如果为 true 就意味着你应该只包括 veganFriendlyi 为 true 的餐馆，
为 false 则意味着可以包括任何餐馆。
此外，我们还有最大价格 maxPrice 和最大距离 maxDistance 两个过滤器，它们分别考虑餐厅的价格因素和距离因素的最大值。

过滤后返回餐馆的 id，按照 rating 从高到低排序。
如果 rating 相同，那么按 id 从高到低排序。
简单起见， veganFriendlyi 和 veganFriendly 为 true 时取值为 1，为 false 时，取值为 0 。*/

//Note: The returned array must be malloced, assume caller calls free().
 

#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
    return (*(int**)b)[1] - (*(int**)a)[1];   //升序：前减后，降序：后减前
}//(*(int**)b)[1] 这种写法保证了rating和相应的id捆绑在一起被sort

int* filterRestaurants(int** restaurants, int restaurantsSize, int* restaurantsColSize, int veganFriendly, int maxPrice, int maxDistance, int* returnSize) {
    int* available_or_not = (int*)malloc(restaurantsSize * sizeof(int));
    int ans_size = 0;

    for (int i = 0; i < restaurantsSize; i++) {
        if ((veganFriendly == 1 && restaurants[i][2] == 1) || veganFriendly == 0) {
            if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
                available_or_not[i] = 1;
                ans_size++;
            } else {
                available_or_not[i] = 0;
            }
        } else {
            available_or_not[i] = 0;
        }
    }

    int** temp_array_for_ordering = (int**)malloc(ans_size * sizeof(int*));
    int t = 0;
    for (int i = 0; i < restaurantsSize; i++) {
        if (available_or_not[i] == 1) {
            temp_array_for_ordering[t] = restaurants[i];
            t++;
        }
    }
//[i][0]存储id,[i][1]存储rating
    qsort(temp_array_for_ordering, ans_size, sizeof(int*), comp);

    int* ans_array = (int*)malloc(ans_size * sizeof(int));
    for (int i = 0; i < ans_size; i++) {
        if (i < ans_size - 1 && temp_array_for_ordering[i][1] == temp_array_for_ordering[i + 1][1]
        && temp_array_for_ordering[i][0] < temp_array_for_ordering[i + 1][0]) {
//i< ans_size - 1必须写在最前面，否则会报错！！！！
        int temp = temp_array_for_ordering[i][0];
        temp_array_for_ordering[i][0] = temp_array_for_ordering[i + 1][0];
        temp_array_for_ordering[i + 1][0] = temp;
        }   

        ans_array[i] = temp_array_for_ordering[i][0];
    }

    // Free allocated memory
    free(temp_array_for_ordering);
    free(available_or_not);

    *returnSize = ans_size;
    return ans_array;
}

int main() {
    int restaurantsData[5][5] = {{1, 4, 1, 40, 10}, {2, 8, 0, 50, 5}, {3, 8, 1, 30, 4}, {4, 10, 0, 10, 3}, {5, 1, 1, 15, 1}};
    int* restaurants[5];
    for (int i = 0; i < 5; i++) {
        restaurants[i] = restaurantsData[i];
    }

    int veganFriendly = 1;
    int maxPrice = 50;
    int maxDistance = 10;

    int returnSize = 0;
    int* result = filterRestaurants(restaurants, 5, NULL, veganFriendly, maxPrice, maxDistance, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(",");
        }
    }
    printf("]\n");

    // Free allocated memory
    free(result);
    system("pause");
    return 0;
}

