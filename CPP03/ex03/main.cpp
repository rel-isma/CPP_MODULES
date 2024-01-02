/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:54:49 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/04 16:23:57 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main()
{
    // DiamondTrap ash("rachid");
    // DiamondTrap ash2;
    // ash2 = ash;
    // DiamondTrap ash3(".");
    // ash2.takeDamage(8);
    // ash2.attack("rel-isma");


    // ash.whoAmI();
    // ash2.whoAmI();
    // ash3 = ash;
    // ash3.whoAmI();

    // ash.attack( "the air" );
    // ash.takeDamage( 10 );
    // ash.beRepaired( 10 );
    DiamondTrap *d = new DiamondTrap("rachid");  
    FragTrap *b = d;
    b->attack("hi");
    delete b;

    return 0;
}


