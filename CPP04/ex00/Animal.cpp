/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:31:18 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/16 18:17:54 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal defualt constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal::Animal(const std::string& type_name) : type(type_name) {

    std::cout << "Animal Parameterized constructor called" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}
void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

const std::string& Animal::getType() const {
    return type;
}
