/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:12:55 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/06 19:54:01 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include<iostream>
#include<limits>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    std::string inputLiteral = argv[1];
    ScalarConverter::convert(inputLiteral);
    return 0;
}
