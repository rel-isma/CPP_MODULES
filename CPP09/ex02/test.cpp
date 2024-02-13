
#include <iostream>
#include <string>

template <typename T>
void print(T t)
{
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void print(T t, Args... args)
{
    // std::cout << t << std::endl;
    print(args...);
}

int main()
{
    print("hello", 1, 4.5, 'c');

	return 0;
}
