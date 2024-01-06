/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:07:05 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/06 22:07:58 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <sstream>

void ScalarConverter::convert(const std::string& str) {

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
        else 
        {
            char* end;
            double result = std::strtod(str.c_str(), &end);

            if ((*end != '\0' && end[1] != '\0') || (*end != '\0' && result && *end != 'f')) {
                throw "char: impossible";
            }
            else if (result == 0 && !(str.size() > 1))
                result = static_cast<int>(end[0]);
            if (isDisplayableChar(result))
                std::cout << "char: '" << static_cast<char>(result) << "'" << std::endl;
            else
                throw "char: Non displayable";
        }
    } catch (const char* e) {
        std::cout << e << std::endl;
    }
}


void ScalarConverter::convertInt(const std::string& str) {
    try {
        if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "inff" ) {
            throw "int: impossible";
        }
        
        char* end;
        int intResult;
        double result = std::strtod(str.c_str(), &end);
        
        if ((*end != '\0' && end[1] != '\0') || (*end != '\0' && result && *end != 'f')) {
            throw "int: impossible";
        }
        if (result == 0 && !(str.size() > 1))
            intResult = static_cast<int>(end[0]);
        else
        {
            if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
                throw "int: impossible";
            intResult = static_cast<int>(result);
        }
        std::cout << "int: " << intResult << std::endl;
    } catch (const char* e) {
        std::cout << e << std::endl;
    }
}


void ScalarConverter::convertFloat(const std::string& str) {
    try {
        
        char* end;
        float floatResult;
        double result = std::strtod(str.c_str(), &end);

        std::string cv = end;
        if ((*end != '\0' && end[1] != '\0') || (*end != '\0' && result && *end != 'f')) {
            throw "float: impossible";
        }
        if (result == 0 && !(str.size() > 1))
            floatResult = static_cast<float>(end[0]);
        else
            floatResult = static_cast<float>(result);
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatResult << "f" << std::endl;
    } catch (const char* e) {
        std::cout << e << std::endl;
    }
}


void ScalarConverter::convertDouble(const std::string& str) {
    try {
        
        char* end;
        double result = std::strtod(str.c_str(), &end);

        std::string cv = end;
        if ((*end != '\0' && end[1] != '\0') || (*end != '\0' && result && *end != 'f')) {
            throw "double: impossible";
        }
        if (result == 0 && !(str.size() > 1)) {
            result = static_cast<double>(end[0]);
        }
        std::cout << "double: " << std::fixed << std::setprecision(1) << result << std::endl;
        } catch (const char* e) {
            std::cout << e << std::endl;
        }
}

bool ScalarConverter::isDisplayableChar(int value) {
    return (value >= 32 && value <= 126);
}
