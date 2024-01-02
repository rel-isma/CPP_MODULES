/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:26:34 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/03 10:58:47 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap 
{
    private:
        std::string name;

    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap(const std::string& name);
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap& other);
        void attack(const std::string& target);
        void whoAmI();
};

#endif
