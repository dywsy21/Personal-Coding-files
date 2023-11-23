#include <bits/stdc++.h>




int main(){
    std::string str1{"hello"};
assert(str1=="hello");
assert(str1.length()==5);

    auto str2 {"helloo"};    //这样定义出的str2是const char类型，不能用std::string的各种method
//assert(str2.length()==6);

    int a[5][5] {};
    std::vector<std::vector<int>> vec1 {{1,2,3},{4,5,6}};

    for(auto &row : vec1){
        for(auto i : row) std::cout << i << ' ';
        std::cout << "\n";
    }



//    for(auto i : a) std::cout << *i;



    system("pause");
    return 0;
}