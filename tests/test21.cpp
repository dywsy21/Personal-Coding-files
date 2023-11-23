#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string inputString = "42 3.14 Hello";
    std::istringstream iss(inputString);

    int intValue;
    double doubleValue;
    std::string stringValue;

    iss >> intValue >> doubleValue >> stringValue;

    std::cout << "Integer: " << intValue << std::endl;
    std::cout << "Double: " << doubleValue << std::endl;
    std::cout << "String: " << stringValue << std::endl;

    system("pause");
    return 0;
}
