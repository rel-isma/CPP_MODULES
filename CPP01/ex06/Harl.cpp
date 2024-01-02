/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:04:49 by rel-isma          #+#    #+#             */
/*   Updated: 2023/09/26 13:08:13 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
    std::cout << GREEN_TEXT << "[ DEBYG ]" << RESET_TEXT << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info() {
    std::cout << GREEN_TEXT << "[ INFO ]" << RESET_TEXT << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning() {
    std::cout << GREEN_TEXT << "[ WARNING ]" << RESET_TEXT << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error() {
    std::cout << GREEN_TEXT << "[ ERROR ]" << RESET_TEXT << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

int Harl::findLevel(std::string level) {
    int i = 0;
    std::string complaintLevels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    while(i < 4)
    {
        if (level == complaintLevels[i]) {
            return i;
        }
        i++;
    }
    return 4;
}

