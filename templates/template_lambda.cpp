#include <bits/stdc++.h>

//返回类型 函数名 = [已有的主参] (形参) 修饰词 {函数体}

struct lambda_factory{
    std::string str;
    int count;

    auto make_lambda(){
        return [this](char target){
            int ret {}; 
            count++;
            for(size_t i = 0; i < str.size(); i++)
                if(target == str[i]) ret++;
            return ret;
        };
    }
    lambda_factory(std::string str_in): str {str_in}, count{} {}

};





int main(){
    char target = 's';
    int total_count {};


    auto check_for_target_1 = [target, &total_count](std::string s){
        int ret = 0;
        for(size_t i = 0; i < s.size(); i++)
            if(s[i] == target) ret++;
        total_count += ret;
        return ret;
    }; //注意要加分号！！
    std::cout << check_for_target_1("sss") << ' ' << total_count << '\n';
    std::cout << check_for_target_1("sss") << ' ' << total_count << '\n';


    auto check_for_target_2 = [&](std::string s){
        int ret = 0;
        for(size_t i = 0; i < s.size(); i++)
            if(s[i] == target) ret++;
        total_count += ret;
        return ret;
    };
    std::cout << check_for_target_2("sss") << ' ' << total_count << '\n';
    std::cout << check_for_target_2("sss") << ' ' << total_count << '\n';


    auto check_for_target_3 = [=](std::string s) mutable { 
        //用=表明的capture  传进来的主参都是只读的const，要加mutable才能修改传进来的主参，
        //但仍不会改变主参在lambda外的值
        int ret = 0;
        for(size_t i = 0; i < s.size(); i++)
            if(s[i] == target) ret++;
        total_count += ret;
        return ret;
    };
    std::cout << check_for_target_3("sss") << ' ' << total_count << '\n';
    std::cout << check_for_target_3("sss") << ' ' << total_count << '\n';


    auto check_for_target_4 = [&, total_count](std::string s) mutable {
        //&和常量混用也可以，但像这里的total_count传进来的就是只读的const
        //非常不推荐使用
        int ret = 0;
        for(size_t i = 0; i < s.size(); i++)
            if(s[i] == target) ret++;
        total_count += ret;
        return ret;
    };
    std::cout << check_for_target_4("sss") << ' ' << total_count << '\n';
    std::cout << check_for_target_4("sss") << ' ' << total_count << '\n';


    lambda_factory LAMBDA_TEST{"sss"};
    auto ret = LAMBDA_TEST.make_lambda();
    std::cout << ret('s') << '\n';
    std::cout << LAMBDA_TEST.make_lambda()('s') << '\n';

    /*auto check_for_target_5 = [](std::string s){
        int ret = 0;
        for(size_t i = 0; i < s.size(); i++)
            if(s[i] == target) ret++;
        total_count += ret;
        return ret;
    };
    std::cout << check_for_target_5("sss") << ' ' << total_count << '\n';
    std::cout << check_for_target_5("sss") << ' ' << total_count << '\n';*/
    //!这样写会报错：'target' is not captured   'total_count' is not captured

    getchar();
    return 0;
}