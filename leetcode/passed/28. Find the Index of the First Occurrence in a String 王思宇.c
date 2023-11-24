int strStr(char* haystack, char* needle) {
    int hay_index = 0, needle_index = 0, ret = -1;

    while(haystack[hay_index]){
        if(haystack[hay_index] == needle[0]){
            int temp = hay_index;
            while(haystack[hay_index] && needle[needle_index]){
                if(haystack[hay_index] == needle[needle_index]){
                    hay_index++; needle_index++;
                }
                else break;
            }
            if(!needle[needle_index]){
                ret = temp;
                break;
            }
            else{
                needle_index = 0;
                hay_index = temp;
            }
        }
        hay_index++;
    }
    return ret;
}