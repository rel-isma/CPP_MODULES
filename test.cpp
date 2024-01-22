#include <iostream>


void fun(int t) {
    std::cout << t << std::endl;
}

void fun(std::string t) {
    std::cout << t << std::endl;
}

int main()
{
    fun(1);
    return 0;
}