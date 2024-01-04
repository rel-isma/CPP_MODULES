/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:07:05 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/04 19:42:00 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cstdlib>

void ScalarConverter::convert(const std::string& str) {
    std::cout << "Original literal: " << str << std::endl;

    convertChar(str);
    convertInt(str);
    convertFloat(str);
    convertDouble(str);
}


void ScalarConverter::convertChar(const std::string& str) {
    try {
        if (str == "nan" || str == "+inf" || str == "-inf") {
            throw "char: impossible";
        }
        char result = std::stoi(str);
        if (isDisplayableChar(static_cast<int>(result)))
            std::cout << "char: '" << result << "'" << std::endl;
        else
            throw "char: Non displayable";
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
}

void ScalarConverter::convertInt(const std::string& str) {
    try {
        if (str == "nan" || str == "+inf" || str == "-inf") {
            throw "char: impossible";
        }

        int result = std::stoi(str);
        std::cout << "int: " << result << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
}


void ScalarConverter::convertFloat(const std::string& str) {
    try {
        float result = std::stof(str);
        std::cout << "float: " << std::fixed << std::setprecision(1) \
            << result << "f" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "float: impossible" << std::endl;
    }
}

void ScalarConverter::convertDouble(const std::string& str) {
    try {
            double result = std::stod(str);
            std::cout << "double: " << std::fixed << std::setprecision(1) \
             << result << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "double: impossible" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "double: impossible" << std::endl;
    }
}


bool ScalarConverter::isDisplayableChar(int value) {
    return (value >= 32 && value <= 126);
}
