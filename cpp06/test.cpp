#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <numeric_string>" << std::endl;
        return 1;
    }

    std::string inputString = argv[1];

    try {



        // void ScalarConverter::convertChar(const std::string& str) {
        // std::istringstream iss(str);
        // int result;

        // // Try to extract an integer from the string
        // if (!(iss >> result)) {
        //     std::cout << "char: invalid argument" << std::endl;
        //     return;
        // }

        // // Check if the integer is representable as a char
        // if (isDisplayableChar(result))
        //     std::cout << "char: '" << static_cast<char>(result) << "'" << std::endl;
        // else
        //     std::cout << "char: Non displayable" << std::endl;
        // }
        // Convert to int
        int intValue = std::stoi(inputString);
        std::cout << "Converted int: " << intValue << std::endl;

        // Convert to float
        float floatValue = static_cast<float>(intValue);
        std::cout << "Converted float: " << std::fixed << std::setprecision(1)  << floatValue << std::endl;

        // Convert to char
        char charValue = static_cast<char>(intValue);
        std::cout << "Converted char: '"  << charValue << "'" << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid argument - " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Out of range - " << e.what() << std::endl;
    }

    return 0;
}

