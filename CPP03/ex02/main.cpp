/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:04:57 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/04 15:50:23 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    // ClapTrap clap("ClapTrap");
    // clap.attack("Target");
    // clap.takeDamage(5);
    // clap.beRepaired(3);
    
    // ScavTrap scav("ScavTrap");
    // scav.attack("Enemy");
    // scav.guardGate();

    FragTrap sa("norm");
    sa.attack("kin");
    sa.takeDamage(50);
    sa.takeDamage(112);
    sa.beRepaired(1000);
    sa.highFivesGuys();
    // FragTrap *d = new FragTrap("rachid");  
    // ClapTrap *b = d;
    // b->attack("hi");
    // delete b;
    return 0;
}
