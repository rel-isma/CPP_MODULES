/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:57:10 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/04 10:33:35 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
    public:
        static void convert(const std::string& str);

    private:
        static void convertChar(const std::string& str);
        static void convertInt(const std::string& str);
        static void convertFloat(const std::string& str);
        static void convertDouble(const std::string& str);

        static bool isDisplayableChar(int value);
};

#endif

