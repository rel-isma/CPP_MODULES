#include <iostream>
#include "Array.hpp"

void malloc_leak_check()
{
    system("leaks ex03");
}
int main()
{
    atexit(malloc_leak_check);

    Array<int> intArray(4);
    for (unsigned int i = 0; i < intArray.size(); ++i)
    {
        intArray[i] = i + 1;
    }

    std::cout << "Array To Int: ";
    for (unsigned int i = 0; i < intArray.size(); ++i)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    Array<int> intArrayCopy(intArray);
    std::cout << "Copy Array To Int: ";
    for (unsigned int i = 0; i < intArrayCopy.size(); ++i)
    {
        std::cout << intArrayCopy[i] << " ";
    }
    std::cout << std::endl;

    Array<std::string> stringArray(3);
    stringArray[0] = "Hi";
    stringArray[1] = "C++";
    stringArray[2] = "Templates";

    std::cout << "Array To String: ";
    for (unsigned int i = 0; i < stringArray.size(); ++i)
    {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    // test out of range
    try
    {
        std::cout << stringArray[3] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
