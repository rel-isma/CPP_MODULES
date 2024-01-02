/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:54:14 by rel-isma          #+#    #+#             */
/*   Updated: 2023/11/30 16:11:35 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->attackDamage = 30;
    this->energyPoints = 100;
    this->hitPoints = 100;
    std::cout << "FragTrap " << BLUE_TEXT << name << GREEN_TEXT;
    std::cout << " Default constructor:: is ready for action!" <<  RESET_TEXT << std::endl;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->attackDamage = 30;
    this->energyPoints = 100;
    this->hitPoints = 100;
    std::cout << "FragTrap " << BLUE_TEXT << name  << GREEN_TEXT;
    std::cout << " constructor parametrize:: is ready for action!" <<  RESET_TEXT << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
    std::cout << "FragTrap " << BLUE_TEXT << name << RESET_TEXT;
    std::cout << GREEN_TEXT << "copy constructor:: is ready for action!" << RESET_TEXT << std::endl;
    *this = other;
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << BLUE_TEXT << name << RED_TEXT << " is no more!" << RESET_TEXT << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << BLUE_TEXT << name << RESET_TEXT << " requests a positive high five!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap " << BLUE_TEXT << name << RESET_TEXT;
    std::cout << GREEN_TEXT << " Copy assignment operator called" << RESET_TEXT << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "FragTrap " << BLUE_TEXT << name << RESET_TEXT << " attacks ";
        std::cout << target << ", losses " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << BLUE_TEXT << name << RESET_TEXT;
        std::cout << " he couldn't attack because he lost energy points." << std::endl;
    }
}