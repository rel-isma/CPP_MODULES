/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:37:30 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/04 10:41:18 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("defualt"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << BLUE_TEXT << name << GREEN_TEXT << "Default constructor:: is ready for action!" << RESET_TEXT << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << BLUE_TEXT << name << GREEN_TEXT << " constructor parametrize:: is ready for action!" << RESET_TEXT << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap " << BLUE_TEXT << name << RESET_TEXT;
    std::cout << GREEN_TEXT << "copy constructor:: is ready for action!" << RESET_TEXT << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << BLUE_TEXT << name << RED_TEXT << " is no more!" << RESET_TEXT << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << BLUE_TEXT << name << RESET_TEXT << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << BLUE_TEXT << name << RESET_TEXT << " can't attack - not enough hit points or energy points." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0) {
        std::cout << "ClapTrap " << BLUE_TEXT << name << RESET_TEXT << " takes " << amount << " points of damage!" << std::endl;
        hitPoints > amount ? hitPoints -= amount : hitPoints = 0;
    } else {
        std::cout << "ClapTrap " << BLUE_TEXT << name << RESET_TEXT << " is already defeated." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << BLUE_TEXT << name << RESET_TEXT << " is being repaired, gaining " << amount << " hit points!" << std::endl;
        hitPoints += amount;
        energyPoints--;
    }
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap " << BLUE_TEXT << name << RESET_TEXT;
    std::cout << GREEN_TEXT << " Copy assignment operator called" << RESET_TEXT << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return *this;
}
