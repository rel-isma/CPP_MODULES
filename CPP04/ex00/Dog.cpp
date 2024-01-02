/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:18:25 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/19 22:30:40 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog defualt constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog::Dog(const std::string& type_name) : Animal(type_name) {

    std::cout << "Dog Parameterized constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

void Dog::makeSound() const {
    std::cout << type << " Woof!" << std::endl;
}
