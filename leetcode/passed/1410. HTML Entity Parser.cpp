#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string entityParser(string text) {
        string ret;
        size_t i {};
        while(i < text.size()){
            if(text[i] != '&'){
                ret.push_back(text[i]);
                i++;
            }
            else{
                    if(i + 5 < text.size() && text.substr(i, 6) == "&quot;"){
                        ret.push_back(34); i += 6;
                    } 
                    
                    else if(i + 5 < text.size() && text.substr(i, 6) == "&apos;"){
                        ret.push_back(39); i += 6; 
                    } 

                    else if(i + 4 < text.size() && text.substr(i, 5) == "&amp;"){
                        ret.push_back('&'); i += 5; 
                    } 

                    else if(i + 3 < text.size() && text.substr(i, 4) == "&gt;"){
                        ret.push_back('>'); i += 4; 
                    } 

                    else if(i + 3 < text.size() && text.substr(i, 4) == "&lt;"){
                        ret.push_back('<'); i += 4; 
                    } 

                    else if(i + 6 < text.size() && text.substr(i, 7) == "&frasl;"){
                        ret.push_back('/'); i += 7; 
                    }
                    else{
                        ret.push_back(text[i]);
                        i++;
                    }
            }
        }
        return ret;








    }
};