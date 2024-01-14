#include <iostream>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

int main() {
    Base derivedObj;
    Base& baseRef = derivedObj;

    try {
        Derived& derivedRef = dynamic_cast<Derived&>(baseRef);
        // Casting successful
        std::cout << "Casting successful." << std::endl;
    } catch (const std::bad_cast& e) {
        // Casting failed
        std::cout << "Casting failed: " << e.what() << std::endl;
    }

    return 0;
}
