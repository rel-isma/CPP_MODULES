#include <iostream>

class A
{
    private:
        int a;
    public:
        A() { a = 15;}
        virtual ~A() {};
};

class B : public A
{
    private:
        int a;
    public:
        B() { a = 15;}
};

int main() {
    A a;
    B *b = static_cast<B*>(&a);
    B *bd = dynamic_cast<B*>(&a);
    std::cout << b << "\n";
    std::cout << bd << "\n";
    return 0;
}

