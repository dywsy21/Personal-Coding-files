#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX_LENGTH 1000000

void StringStatistics(char* str, int* numChars, int* numLines, int* numWords) {
    *numChars=strlen(str)-1;
    (*numLines) = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n')
            (*numLines)++;
        i++;
    }

    int j = 0;
    while (str[j] != '\0') {
        if (str[j] == ' ')
            (*numWords)++;
        if (str[i] == '\n')
            (*numWords)++;
        j++;
    }

    printf("The characters, lines and words of this string are %d, %d and %d\n", *numChars, *numLines, *numWords);
}

int main() {
    char* str;
    char temp[MAX_LENGTH];
    int numChars=0, numLines, numWords=1;

    str = (char*)malloc((MAX_LENGTH + 1) * sizeof(char));
    printf("Enter a string:\n");

    fgets(str, MAX_LENGTH, stdin);

    StringStatistics(str, &numChars, &numLines, &numWords);

    system("pause");
    return 0;
}
