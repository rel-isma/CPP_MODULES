/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:16:10 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/09 18:30:20 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"


Serializer::Serializer() {
}

Serializer::Serializer(const Serializer& other) {
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    if (this != &other) {
    }
    return *this;
}


Serializer::~Serializer() {
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
