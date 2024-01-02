/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:45:33 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/04 15:39:58 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("ClapTrap");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    ScavTrap scav("Scav");
    scav.attack("Enemy");
    scav.guardGate();
    // ScavTrap *d = new ScavTrap("rachid");  
    // ClapTrap *b = d;
    // b->attack("hi");
    // delete b;
    return 0;
}
