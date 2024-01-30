#include <iostream>
#include <map>

int main() {
    std::map<std::string, int32_t> myMap;

    myMap["One"] = 1;
    myMap["Two"] = 2;
    myMap["Four"] = 4;
    myMap["Five"] = 5;

    std::string keyToFind = "Three";

    // Using lower_bound to find the first element with a key not less than keyToFind
    std::map<std::string, int>::iterator it = myMap.lower_bound(keyToFind);

    if (it != myMap.end()) {
        std::cout << "Key not less than or equal to " << keyToFind << ": " << it->first << ", " << it->second << std::endl;
    } else {
        std::cout << "No key found not less than or equal to " << keyToFind << std::endl;
    }

    return 0;
}


