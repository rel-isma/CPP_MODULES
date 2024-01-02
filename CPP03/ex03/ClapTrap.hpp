/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:53:52 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/04 16:20:53 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define RED_TEXT "\x1B[31m"
#define GREEN_TEXT "\x1B[32m"
#define BLUE_TEXT "\x1B[34m"
#define RESET_TEXT "\x1B[0m"

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap(const std::string& name);
        virtual ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
};

#endif
