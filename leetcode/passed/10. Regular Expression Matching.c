#include <bits/stdc++.h>
#define DEBUG printf("%d %d\n",sindex, pindex);

void reduceConsecutiveStars(char* str) {
    if (str == NULL)
        return;
    int len = strlen(str);
    if (len <= 1)
        return;

    int j = 0;  // Index to store the modified string
    int i = 0;  // Index to traverse the original string

    // Copy the first character
    str[j++] = str[i++];

    // Traverse the string
    while (i < len) {
        // If the current character is not a star or the previous character is not a star,
        // copy the current character to the modified string
        if (str[i] != '*' || str[i] == '*' && str[i - 1] != '*') {
            str[j++] = str[i];
        }
        i++;
    }

    // Null-terminate the modified string
    str[j] = '\0';
}

void asterisk(int* sindex, int* pindex,char* s, char* p ,int* det){  //p[pindex]=='*'
    int i=0,j=0;
    if((*pindex)-1>=0 && p[(*pindex)-1]=='.'){
        if((*pindex)+1>=strlen(p)){
            (*det)=1;
            return;
        }
        (*pindex)++;
        while((*sindex)<strlen(s) && s[*sindex]!=p[*pindex]) (*sindex)++;
        if((*sindex)==strlen(s)) (*det)=2;
        return;

    }
    else{
        if((*pindex)-1>=0 &&  p[(*pindex)-1]!=s[*sindex]){   //注意sindex
        (*pindex)++;
        return;   
        } 
        while(s[(*sindex)]==p[(*pindex)-1])   (*sindex)++;
        (*pindex)+=2;
        return;
    }
}



bool isMatch(char *s, char *p) {
    int sindex = 0, pindex = 0, det = 0, i = 0, det1 = 0, det2=0;
    bool ret = true;

    reduceConsecutiveStars(p);

    while (p[i]) {
        if (p[i] == '.') det1++;
        if (p[i] == '*') det2++;
        i++;
    }
    if (!(det1+det2)) {
        if (strcmp(s, p) == 0)
            return true;
        else
            return false;
    }

    if(!det2){
        if (strlen(s)!=strlen(p))  return false;
    }


    while (pindex<strlen(p) && sindex<strlen(s)) {
        if (p[pindex] == '.') {
            pindex++;
            sindex++;
        }

        if (p[pindex] == '*'){
            asterisk(&sindex, &pindex, s, p, &det);
            if (det==1)
                return true;
            if (det==2)
                return false;
            if(sindex==strlen(s) && pindex==strlen(p))  return true;
        }

        if (!(p[pindex] == '*' || p[pindex] == '.')) {
            if (pindex<strlen(p) && p[pindex] == s[sindex]) {
                pindex++;
                sindex++;
DEBUG
            } 
            else if(pindex<strlen(p) && p[pindex+1]=='*') {
                    pindex+=2;
                    if(pindex>=strlen(p)+2) return false;
                }
                 else return false; 
        }
    }

    return true;
}

int main(){
    char s[10000],p[10000];
    while(1){
    gets(s);
    gets(p);
    if(isMatch(s,p)) printf("true\n");
    else printf("false\n");
    }
    system("pause");
    return 0;
}