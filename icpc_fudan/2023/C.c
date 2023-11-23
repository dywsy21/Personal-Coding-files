#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

bool card_bigger(char a, char b){ //true -> a>=b   false-> a<b
    char arr[14]="AKQJT98765432";
    int det_a,det_b;
    for(int i=0;arr[i];i++){
        if(a==arr[i]) det_a=i;
        if(b==arr[i]) det_b=i;
    }
    if(det_a<=det_b) return true;
        else return false;
}

void sort_array(char *c){
    int swapped;  
    char temp;

    do {
        swapped = 0;  

        for (int i = 0; i < 4; i++) {
            if (!card_bigger(c[3 * i], c[3 * (i + 1)])) {

                temp = c[3 * i];
                c[3 * i] = c[3 * (i + 1)];
                c[3 * (i + 1)] = temp;


                temp = c[3 * i + 1];
                c[3 * i + 1] = c[3 * (i + 1) + 1];
                c[3 * (i + 1) + 1] = temp;

                swapped = 1;  
        }
    } while (swapped);
}
}


int num(char a) {
    switch(a){
        case 'A': return 14; break;
        case 'K': return 13; break;
        case 'Q': return 12; break;
        case 'J': return 11; break;
        case 'T': return 10; break;
        case '9': return 9; break;
        case '8': return 8; break;
        case '7': return 7; break;
        case '6': return 6; break;
        case '5': return 5; break;
        case '4': return 4; break;
        case '3': return 3; break;
        case '2': return 2; break;
    }
}

int main(){
    int T,i=1,ans=0;
    scanf("%d",&T);
    getchar();
    char c[18];  int det_Straight=0,det_Flush=0;

    while(i<=T){
        ans=0;
        det_Straight=0; det_Flush=0;

        fgets(c, sizeof(c), stdin);

        sort_array(c); //in descending order

//1
        if(c[0]!=c[3] && c[3]!=c[6] && c[6]!=c[9] && c[9]!=c[12]) ans=1;
        
//2
        if(!(c[0]!=c[3] && c[3]!=c[6] && c[6]!=c[9] && c[9]!=c[12])) ans=2;

//3
        if((c[0]==c[3]&&c[6]==c[9]&&c[0]!=c[6])||(c[0]==c[3]&&c[6]==c[12]&&c[0]!=c[6])||(c[0]==c[3]&&c[9]==c[12]&&c[0]!=c[9])||(c[0]==c[6]&&c[9]==c[12]&&c[0]!=c[9])||(c[3]==c[6]&&c[9]==c[12]&&c[3]!=c[9])) ans=3;

//4
        if((c[0]==c[3]&&c[3]==c[6])||(c[3]==c[6]&&c[6]==c[9])||(c[6]==c[9]&&c[9]==c[12])) ans=4;

//5
        if((num(c[0])==num(c[3])+1 && num(c[3])==num(c[6])+1 && num(c[6])==num(c[9])+1 && num(c[9])==num(c[12])+1)||(num(c[0])==14 && num(c[3])==5 && num(c[6])==4 && num(c[9])==3 && num(c[12])==2)) {ans=5; det_Straight=1;}

//6
        if(c[1]==c[4]&&c[4]==c[7]&&c[7]==c[10]&&c[10]==c[13]) {ans=6; det_Flush=1;}

//7
        if((c[0]==c[3]&&c[3]==c[6]&&c[6]!=c[9]&&c[9]==c[12])||(c[0]==c[3]&&c[3]!=c[6]&&c[6]==c[9]&&c[9]==c[12])) ans=7;

//8
        if((c[0]==c[3]&&c[6]==c[9]&&c[0]==c[6])||(c[0]==c[3]&&c[6]==c[12]&&c[0]==c[6])||(c[0]==c[3]&&c[9]==c[12]&&c[0]==c[9])||(c[0]==c[6]&&c[9]==c[12]&&c[0]==c[9])||(c[3]==c[6]&&c[9]==c[12]&&c[3]==c[9])) ans=8;

//9
        if(det_Straight && det_Flush) ans=9;

//10
        if(det_Straight && det_Flush && c[0]=='A' && c[3]=='K' && c[6]=='Q' && c[9]=='J' && c[12]=='T') ans=10;

if(i<T){
        switch(ans){
            case 1:  printf("Highcard\n"); break;
            case 2:  printf("Pair\n"); break;
            case 3:  printf("Two pairs\n"); break;
            case 4:  printf("Three of a kind\n"); break;
            case 5:  printf("Straight\n"); break;
            case 6:  printf("Flush\n"); break;
            case 7:  printf("Full house\n"); break;
            case 8:  printf("Four of a kind\n"); break;
            case 9:  printf("Straight flush\n"); break;
            case 10: printf("Royal flush\n"); break;
        }
}
if(i==T){
        switch(ans){
            case 1:  printf("Highcard"); break;
            case 2:  printf("Pair"); break;
            case 3:  printf("Two pairs"); break;
            case 4:  printf("Three of a kind"); break;
            case 5:  printf("Straight"); break;
            case 6:  printf("Flush"); break;
            case 7:  printf("Full house"); break;
            case 8:  printf("Four of a kind"); break;
            case 9:  printf("Straight flush"); break;
            case 10: printf("Royal flush"); break;
        }
}




        i++;
    }
    system("pause");
    return 0;
}