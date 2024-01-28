#include <iostream>
#include <string>

void trimString(std::string &str)
{
    str.erase(0, str.find_first_not_of(" "));

    str.erase(str.find_last_not_of(" ")+1 );
}

int main()
{
    std::string exampleString = "    Hello, World!    ";

    std::cout << "Original String: \"" << exampleString << "\"" << std::endl;

    trimString(exampleString);

    std::cout << "Trimmed String: \"" << exampleString << "\"" << std::endl;

    return 0;
}
