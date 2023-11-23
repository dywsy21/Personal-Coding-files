
#define max(a,b) ((a)>(b)?(a):(b))

char* output(int type){
    char* ret = (char*) malloc(strlen("Three of a Kind")*sizeof(int));
    switch (type)
    {
    case 1:  strcpy(ret, "Flush"); break;
    case 2:  strcpy(ret, "Three of a Kind"); break;
    case 3:  strcpy(ret, "Pair");  break;
    case 4:  strcpy(ret, "High Card");  break;
    }
    return ret;
}

char * bestHand(int* ranks, int ranksSize, char* suits, int suitsSize){
    int type = 0 , max_duplicate = 0;

    int hashtable[13] = {0};
    for(int i = 0; i < 5; i++) hashtable[ranks[i]-1]++;
    for(int i = 0; i < 13; i++) max_duplicate = max(max_duplicate,hashtable[i]);

    if(max_duplicate >= 1) type = 4;
    if(max_duplicate >= 2) type = 3;
    if(max_duplicate >= 3) type = 2;
    if(suits[0]==suits[1] && suits[1]==suits[2] && suits[2]==suits[3] && suits[3]==suits[4]) type = 1;

    char* ret = output(type);
    return ret;
}