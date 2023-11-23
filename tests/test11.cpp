#include<bits/stdc++.h>

int main(){

    int count = 0;
    auto count_s = [&count](std::string s, char target){
        count++;
        int ret {};
        for(auto a: s) if(a == target) ret++;
        return ret;
    };


    auto make_lambda = [&count](char target){
        return [&count, target](std::string s){
            count++;
            int ret {};
            for(auto a: s) if(a == target) ret++;
            return ret;

        };


    };

    std::vector<std::pair<std::string, std::vector<int>>> pairs;
    for(auto [str, vec]: pairs){

    }

    std::vector<int> vec;
    for(auto i: vec)
    for(int i = 0; i < vec.size(); i++)




    std::cout << make_lambda('s')("sss");


    getchar();
    return 0;
}