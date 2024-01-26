/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:59:46 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/25 19:44:53 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() 
{
    Data originalData(42, 'A');

    std::cout << "sizeof: " << sizeof(originalData) << std::endl;

    uintptr_t serializedPtr = Serializer::serialize(&originalData);

    Data* deserializedData = Serializer::deserialize(serializedPtr);

    if (deserializedData == &originalData) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Int value: " << deserializedData->intValue << std::endl;
        std::cout << "Char value: " << deserializedData->charValue << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }
    return 0;
}

