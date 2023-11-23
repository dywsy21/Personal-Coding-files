#include <bits/stdc++.h>

class timefuncs{
    int year;
public:
    timefuncs(int time_in){
        if(time_in <= 2000) year=time_in;
        else year=2000;
    }

    int get_year(){
        return year;
    }

    void set_year(int year_in){
        year=year_in;   
    }
};

void add_year(timefuncs& vari){
    vari.set_year(vari.get_year()+1);
}



int main(){

    timefuncs vari_a(10000);
    timefuncs* vari_a_ptr=&vari_a;

    std::cout << vari_a_ptr -> get_year() << "\n";

    vari_a_ptr -> set_year(1999);
    std::cout << vari_a_ptr -> get_year() << "\n";

    vari_a.set_year(1998);
    std::cout << vari_a_ptr -> get_year() << "\n";

    vari_a.set_year(1997);
    std::cout << (*vari_a_ptr).get_year() << "\n";

    add_year(vari_a);
    std::cout << vari_a.get_year() << "\n";

    system("pause");
    return 0;
}

