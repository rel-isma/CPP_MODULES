/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:18:14 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/20 11:58:09 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i) {
        if (inventory[i]) {
            delete inventory[i];
        }
    }
}

Character::Character(const Character &other) : name(other.name)
{
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        }
        else {
            inventory[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            }
            else  {
                inventory[i] = NULL;
            }
        }
    }
    return *this;
}

std::string const &Character::getName() const  {
    return name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}
