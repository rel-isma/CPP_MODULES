/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:07:37 by rel-isma          #+#    #+#             */
/*   Updated: 2023/11/26 12:09:15 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) 
{
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value) 
{
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const {
    return roundf(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt() const 
{
    return fixedPointValue >> fractionalBits;
}

Fixed& Fixed::operator=(const Fixed& fixed) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
    {
        fixedPointValue = fixed.fixedPointValue;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
    out << fixed.toFloat();
    return out;
}
