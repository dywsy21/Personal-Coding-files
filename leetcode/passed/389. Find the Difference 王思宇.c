char findTheDifference(char * s, char * t){
    int hashtable1[26] = {0}; 
    int hashtable2[26] = {0};
    
    int s_index = 0, t_index = 0;
    
    while(s[s_index]) {
        hashtable1[s[s_index] - 'a']++;
        s_index++;
    }

    while(t[t_index]) {
        hashtable2[t[t_index] - 'a']++;
        t_index++;
    }

    int index = 0;
    while (index < 26) {
        if (hashtable1[index] != hashtable2[index]) return 'a' + index;
        index++;
    }
    return 'a';
}
