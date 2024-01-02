/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:17:04 by rel-isma          #+#    #+#             */
/*   Updated: 2023/11/30 17:27:11 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
    this->attackDamage = 20;
    this->energyPoints = 50;
    this->hitPoints = 100;
    std::cout << "ScavTrap " << BLUE_TEXT << name << GREEN_TEXT;
    std::cout << " Default constructor:: is ready for action!" <<  RESET_TEXT << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    this->attackDamage = 20;
    this->energyPoints = 50;
    this->hitPoints = 100;
    std::cout << "ScavTrap " << BLUE_TEXT << name  << GREEN_TEXT;
    std::cout << " constructor parametrize:::: is ready for action!" <<  RESET_TEXT << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    std::cout << "ScavTrap " << BLUE_TEXT << name << RESET_TEXT;
    std::cout << GREEN_TEXT << "copy constructor:: is ready for action!" << RESET_TEXT << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << BLUE_TEXT << name;
    std::cout << RED_TEXT << " has fulfilled its duty and is no more!" << RESET_TEXT << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << BLUE_TEXT << name << RESET_TEXT << " is guarding the gate!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap " << BLUE_TEXT << name << RESET_TEXT;
    std::cout << GREEN_TEXT << " Copy assignment operator called" << RESET_TEXT << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ScavTrap " << BLUE_TEXT << name << RESET_TEXT << " attacks ";
        std::cout << target << ", losses " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ScavTrap " << BLUE_TEXT << name << RESET_TEXT;
        std::cout << " he couldn't attack because he lost energy points." << std::endl;
    }
}