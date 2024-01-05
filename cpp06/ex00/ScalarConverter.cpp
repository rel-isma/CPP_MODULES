/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:07:05 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/05 22:31:55 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <sstream>

void ScalarConverter::convert(const std::string& str) {
    std::cout << "Original literal: " << str << std::endl << std::endl;

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

        std::stringstream ss(str);
        int result;
        ss >> result;
        if (ss.fail()) {
            throw "char: impossible";
        }

        if (isDisplayableChar(result))
            std::cout << "char: '" << static_cast<char>(result) << "'" << std::endl;
        else
            throw "char: Non displayable";
    } catch (const char* e) {
        std::cout << e << std::endl;
    }
}

void ScalarConverter::convertInt(const std::string& str) {
    try {
        if (str == "nan" || str == "+inf" || str == "-inf") {
            throw "int: impossible";
        }

        std::stringstream ss(str);
        int result;
        ss >> result;
        if (ss.fail()) {
            throw "int: impossible";
        }

        std::cout << "int: " << result << std::endl;
    } catch (const char* e) {
        std::cout << e << std::endl;
    }
}


void ScalarConverter::convertFloat(const std::string& str) {
    try {
        std::stringstream ss(str);
        float result;
        // std::cout << "str == " << ss.str() << std::endl;
        ss >> result;
        if (ss.fail()) {
            throw "float: impossible";
        }

        std::cout << "float: " << std::fixed << std::setprecision(1) << result << "f" << std::endl;
    } catch (const char* e) {
        std::cout << e << std::endl;
    }
}

void ScalarConverter::convertDouble(const std::string& str) {
    try {
        std::stringstream ss(str);
        double result;
        ss >> result;
        if (ss.fail()) {
            throw "double: impossible";
        }

        std::cout << "double: " << std::fixed << std::setprecision(1) << result << std::endl;
    } catch (const char* e) {
        std::cout << e << std::endl;
    }
}

bool ScalarConverter::isDisplayableChar(int value) {
    return (value >= 32 && value <= 126);
}
