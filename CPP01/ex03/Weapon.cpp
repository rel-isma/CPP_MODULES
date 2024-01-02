/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:04:47 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/08 13:48:34 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("") {
}

Weapon::Weapon(const std::string& type) : type(type) {
}

const std::string& Weapon::getType() {
    return type;
}

void Weapon::setType(const std::string newType) {
    if (newType.empty())
        type = "default";
    type = newType;
}
