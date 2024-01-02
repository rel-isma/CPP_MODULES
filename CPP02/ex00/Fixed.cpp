/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:22:38 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/07 17:15:30 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        fixedPointValue = other.getRawBits();
    }
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}