#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> A{"123","456"};
    vector<string> B{"123","456"};
    auto x = A==B ? 1 : 0;
    cout << x;

    auto y = [](){ return 1; };
    cout << y();

    getchar();
}
