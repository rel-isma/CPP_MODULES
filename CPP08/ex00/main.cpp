/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:49:38 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/25 23:35:06 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;

    for (int i = 0; i < 10; ++i)
    {
        vec.push_back(i * 2);
    }

    try
    {
        std::vector<int>::iterator result = easyfind(vec, 4);
        std::cout << "Value found at position: " << std::distance(vec.begin(), result) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator result = easyfind(vec, 20);
        std::cout << "Value found at position: " << std::distance(vec.begin(), result) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
