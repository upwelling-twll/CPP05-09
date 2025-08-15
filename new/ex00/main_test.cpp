#include <iostream>
#include <vector>
#include <string>
#include "ScalarConverter.hpp"

int main()
{
    const char* arr[] = {
        "0", "42", "-42",
        "a", "A", " ", "\n", "127",
        "42.0f", "42.5f", "-42.5f", ".5f", "-0.0f",
        "42.0", "42.5", "-42.5", ".5", "-0.0",
        "1e3", "1.2e3", "1E-3", "1e3f", "-1e-3f",
        "nan", "+inf", "-inf", "nanf", "+inff", "-inff",
        "2147483647", "-2147483648", "2147483648",
        "3.4028235e38f", "-3.4028235e38f",
        "1.7976931348623157e308", "-1.7976931348623157e308",
        "1e309", "-1e309"
    };

    std::vector<std::string> tests(arr, arr + sizeof(arr)/sizeof(arr[0]));

    for (std::vector<std::string>::iterator it = tests.begin(); it != tests.end(); ++it)
    {
        std::cout << "\n=== Test input: \"" << *it << "\" ===\n";
        ScalarConverter::convert(*it);
    }

    return 0;
}
