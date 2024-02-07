/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:53:32 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/07 20:13:32 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T &element)
{
    std::cout << element << " ";
}

int main()
{
    int *intArray = NULL;

    std::cout << "IntArray: ";
    iter(intArray, 6, print<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "DoubleArray: ";
    iter(doubleArray, (sizeof(doubleArray) / sizeof(double)), print<double>);
    std::cout << std::endl;

    std::string stringArray[] = {"apple", "banana", "cherry", "date"};

    std::cout << "StringArray: ";
    iter(stringArray, (sizeof(stringArray) / sizeof(std::string)), print<std::string>);
    std::cout << std::endl;

    return 0;
}
