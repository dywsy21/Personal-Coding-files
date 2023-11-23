#include <iostream>


auto f(auto a, auto b){
    return a + b;
}

auto f(double a, double b){
    return a*b;
}




int main(){
    auto x = f(1, 2);

    auto y = f("12", "34");
    std::cout << x << ' ' << y;
    system("pause");
    return 0;

}