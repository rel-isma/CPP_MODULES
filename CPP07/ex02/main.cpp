/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:49:34 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/22 18:56:30 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
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
        std::cout << stringArray[3] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
