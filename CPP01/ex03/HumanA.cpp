/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:20:24 by rel-isma          #+#    #+#             */
/*   Updated: 2023/09/25 11:35:57 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name)
                                                    , weapon(weapon) {

}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}