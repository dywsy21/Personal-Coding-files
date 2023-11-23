#include<bits/stdc++.h>

struct ptime {
    ptime(int time_in){
        if(time_in>=1) year=10;
        else year=time_in;
    }
    int year;
    void add_year(){
        year++;
    }
};

int main(){
    ptime mytime{1};
    mytime.add_year();

    std::cout << mytime.year;

    system("pause");
    return 0;
}
