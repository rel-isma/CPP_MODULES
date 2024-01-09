/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:57:13 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/08 21:50:13 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : intValue(0), charValue('\0') {}

Data::Data(int intValue, char charValue) : intValue(intValue), charValue(charValue) {}

Data::~Data() {}


bool Data::operator==(const Data& other) const {
    return intValue == other.intValue && charValue == other.charValue;
}
