char* reverseWords(char* s) {
    int size = 0;
    while (s[size++]);

    char* ret = (char*)malloc((size + 1) * sizeof(char));
    int ret_index = 0, i = size - 2;

    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i--;
        int temp = i;
        while (i >= 0 && s[i] != ' ') i--;

        for (int j = i + 1; j <= temp; j++) ret[ret_index++] = s[j];

        bool flag = false;
        for(temp = i; temp >= 0; temp--) if(s[temp] != ' ') flag = true;
        if(flag) ret[ret_index++] = ' ';
    }

    ret[ret_index] = '\0';
    return ret;
}
