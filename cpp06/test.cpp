#include <iostream>

class Animal
{
public:
    void eat()
    {
        std::cout << "I can eat!" << std::endl;
    }
    virtual void sleep()
    {
        std::cout << "khach!" << std::endl;
    }
};

class Dog : public Animal
{
public:
   virtual void sleep()
    {
        std::cout << "3aw 3aw!" << std::endl;
    }
};

int main()
{
    Dog myDog;

    myDog.sleep();

    return 0;
}