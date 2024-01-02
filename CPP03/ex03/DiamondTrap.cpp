/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:25:39 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/04 16:18:20 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
    this->name = "default_clap_name" ;
    ClapTrap::hitPoints = 100;
    ClapTrap::attackDamage = 100;
    ClapTrap::energyPoints = 50;
    std::cout << "DiamondTrap " << BLUE_TEXT << name << GREEN_TEXT << " default constructor is ready for action!" << RESET_TEXT << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name") {
    this->name = name + "_clap_name";
    ClapTrap::hitPoints = 100;
    ClapTrap::attackDamage = 100;
    ClapTrap::energyPoints = 50;
    std::cout << "DiamondTrap " << BLUE_TEXT << name << GREEN_TEXT << " constructor parametrize:: is ready for action!" << RESET_TEXT << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    std::cout << "DiamondTrap " << BLUE_TEXT << name << RESET_TEXT;
    std::cout << GREEN_TEXT << "copy constructor:: is ready for action!" << RESET_TEXT << std::endl;
    *this = other;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << BLUE_TEXT << name << RED_TEXT << " is no more!" << RESET_TEXT << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap " << BLUE_TEXT << this->name << RESET_TEXT;
    std::cout << " and ClapTrap " << BLUE_TEXT << ClapTrap::name << RESET_TEXT;
    std::cout << " together declare: I am a DiamondTrap!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap " << BLUE_TEXT << name << RESET_TEXT;
    std::cout << GREEN_TEXT << " Copy assignment operator called" << RESET_TEXT << std::endl;
    name = other.name;
    ClapTrap::name = other.name + "_clap_name";
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return *this;
}
void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}