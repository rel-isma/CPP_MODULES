/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:35:01 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/05 16:19:39 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) 
{
    int i = 0;
    std::string complaintLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*complaintFunctions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    bool found = false;
    while(i < 4)
    {
        if (level == complaintLevels[i])
        {
            (this->*complaintFunctions[i])();
            found = true;
            break;
        }
        i++;
    }
    if (!found) {
        std::cout << "Invalid complaint level: " << level << std::endl;
    }
}

