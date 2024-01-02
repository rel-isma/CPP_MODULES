/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:12:40 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/17 17:18:17 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain defualt constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const std::string& type) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = type;
    }
    std::cout << "Brain constructor paramitr called with type: " << type << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
    return *this;
}

void Brain::printIdeas() const {
    for (int i = 0; i < 100; ++i) {
        std::cout << "Idea " << i + 1 << ": " << ideas[i] << std::endl;
    }
}
