#include <iostream>
// #include <string>



class Bureaucrat {
    public:
        class High : public std::exception {
        public:
            const char* what() const throw() ;
        };

        class Low : public std::exception {
        public:
            const char* what() const throw() ;
        };
        Bureaucrat();
        ~Bureaucrat();
};

const char* Bureaucrat::High::what() const throw() {

      return "high";
}

const char* Bureaucrat::Low::what() const throw(){
    return "lowdsds";
}

int divide(int a, int b) {
    if (b == 0) {
       throw "jvhdshjds";
    }
    return a / b;
}

int main() {
    int num1, num2;

    std::cout << "Enter two numbers for division: ";
    std::cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        std::cout << "The result is: " << result << std::endl;
    } catch (const char * e) {
        std::cerr << "Error: " << e << std::endl;
    }
    
    return 0;
}
