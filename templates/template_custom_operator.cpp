#include <bits/stdc++.h>
using namespace std;


template<typename T>
ostream& operator<<(ostream& s, vector<T> vec){
    for(auto ele: vec) s << ele << ' ';
    return s;
}

int main(){
    vector<string> vec{"123454666234","456"};
    cout << vec;

    getchar();
    return 0;
}