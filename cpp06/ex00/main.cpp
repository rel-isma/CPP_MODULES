/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:12:55 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/05 20:42:03 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include<iostream>
#include<limits>

int main(int argc, char **argv)
{
    // int nn;
    // nn = std::numeric_limits<int>::max();
    // std::cout << "The value of Positive infinity is : " << nn << std::endl;
    // nn = std::numeric_limits<int>::min();
    // std::cout << "The value of Positive infinity is2 : " << nn << std::endl;
    // nn = std::numeric_limits<int>::infinity();
    // std::cout << "The value of Positive infinity is3 : " << nn << std::endl;



    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    std::string inputLiteral = argv[1];
    ScalarConverter::convert(inputLiteral);
    return 0;
}
