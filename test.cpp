#include <iostream>
#include <deque>

int main() {
    std::deque<int> myDeque;

	for (int i = 0; i < 5; i++)
		myDeque.push_back(i);

    // Using const_iterator to iterate over the deque
    std::deque<int>::const_iterator it = myDeque.begin();
    std::deque<int>::const_iterator end = myDeque.end();

    while (it != end) {
        std::cout << *it << " ";
        ++it;
    }

    std::cout << std::endl;

    return 0;
}

