#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ret {};
        if(!num) return ret;

        if(1000<=num && num<=3999){
            ret.push_back('M');
            ret += intToRoman(num - 1000);
        }

        if(900<=num && num<1000){
            ret += "CM";
            ret += intToRoman(num - 900);
        }

        if(500<= num && num<900){
            ret.push_back('D');
            ret += intToRoman(num - 500);
        }

        if(400<= num && num<500){
            ret += "CD";
            ret += intToRoman(num - 400);
        }

        if(100<=num && num<400){
            ret.push_back('C');
            ret += intToRoman(num - 100);
        }

        if(90<=num && num<100){
            ret += "XC";
            ret += intToRoman(num - 90);
        }

        if(50<=num && num<90){
            ret.push_back('L');
            ret += intToRoman(num - 50);
        }

        if(40<=num && num<50){
            ret += "XL";
            ret += intToRoman(num - 40);
        }

        if(10<=num && num<40){
            ret.push_back('X');
            ret += intToRoman(num - 10);
        }

        if(num == 9){
            ret += "IX";
            return ret;
        }

        if(5<=num && num<9){
            ret.push_back('V');
            ret += intToRoman(num - 5);
        }

        if(num == 4){
            ret += "IV";
            return ret;
        }

        if(1<=num && num<4){
            ret.push_back('I');
            ret += intToRoman(num - 1);
        }
        return ret;
    }
};