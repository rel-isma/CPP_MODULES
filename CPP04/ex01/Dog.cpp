/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:18:25 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/19 22:52:39 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
    std::cout << "Dog defualt constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = NULL;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
std::cout << "Dog destructor called" << std::endl;
delete brain;
}

void Dog::makeSound() const {
std::cout << "woof woof!" << std::endl;
}
