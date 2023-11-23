#include <bits/stdc++.h>
using namespace std;

bool isoperator(string s) {
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'));
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> calculating_stack;

        for (auto str : tokens) {
            if (isoperator(str)) {
                string str_num1 = calculating_stack.top();
                calculating_stack.pop();
                string str_num2 = calculating_stack.top();
                calculating_stack.pop();

                int num1, num2;
                istringstream(str_num1) >> num1;
                istringstream(str_num2) >> num2;

//or:           int num1 = stoi(str_num1);
//              int num2 = stoi(str_num2);

                int result;
                switch (str[0]) {
                case '+':
                    result = num2 + num1;
                    break;
                case '-':
                    result = num2 - num1;
                    break;
                case '*':
                    result = num2 * num1;
                    break;
                case '/':
                    result = num2 / num1;
                    break;
                }

                calculating_stack.push(to_string(result));
            } else {
                calculating_stack.push(str);
            }
        }

        int ans;
        istringstream(calculating_stack.top()) >> ans;
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result = solution.evalRPN(tokens);
    cout << "Result: " << result << endl;
    system("pause");
    return 0;
}
