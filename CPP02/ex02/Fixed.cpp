/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:27:45 by rel-isma          #+#    #+#             */
/*   Updated: 2023/11/24 03:55:39 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
}

Fixed::Fixed(const int value) {
    fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
    fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
    return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw) {
    this->fixedPointValue = raw;
}

float Fixed::toFloat() const {
    return roundf(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return fixedPointValue >> fractionalBits;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
    if (this != &fixed)
    {
        fixedPointValue = fixed.fixedPointValue;
    }
    return *this;
}

bool    Fixed::operator>(const Fixed& other) const {
     return (toFloat() > other.toFloat());
}

bool    Fixed::operator<(const Fixed& other) const {
    return (fixedPointValue < other.fixedPointValue);
}

bool    Fixed::operator>=(const Fixed& other) const {
     return (toFloat() >= other.toFloat());
}

bool    Fixed::operator<=(const Fixed& other) const {
    return (toFloat() <= other.toFloat());
}

bool    Fixed::operator!=(const Fixed& other) const {
    return (toFloat() != other.toFloat());
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed obj(toFloat() + other.toFloat());
    return (obj);
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed obj(toFloat() - other.toFloat());
    return (obj);
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed obj(toFloat() * other.toFloat());
    return (obj);
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed obj(toFloat() / other.toFloat());
    return (obj);
}

Fixed& Fixed::operator++() {
    ++fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++fixedPointValue;
    return temp;
}

Fixed& Fixed::operator--() {
    --fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --fixedPointValue;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
