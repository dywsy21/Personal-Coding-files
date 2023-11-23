#include <iostream>

class Calculator {
public:
    char op; // Changed the variable name to 'op'
    
    Calculator(char operator_in) : op(operator_in) 

    double calculate(double a, double b) { // Changed 'auto' to 'double'
        switch (op) {
            case '+': return a + b; break;
            case '-': return a - b; break;
            case '*': return a * b; break;
            case '/': if (!b) std::cout << "Error: divisor can't be 0.\n";
                      else return a / b; break;
            default: std::cout << "Error: invalid operator.\n"; return 0;
        }
    }
};

int main() {
    Calculator addcac('+');
    Calculator minuscac('-');
    Calculator timecac('*');
    Calculator divicac('/');

    double a = 1.2, b = 0;
    std::cout << divicac.calculate(a, b);
    system("pause");
    return 0;
}
