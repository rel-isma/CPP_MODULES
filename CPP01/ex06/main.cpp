/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:10:24 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/07 12:17:31 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) 
{
    int find;
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log_level>" << std::endl;
        return 1;
    }
    std::string logLevel = argv[1];
    std::cout << BLUE_TEXT <<  "Listening to messages at and above log level: "  << RESET_TEXT;
    std::cout << YELLOW_TEXT << logLevel << RESET_TEXT << std::endl;
    Harl harl;
    find = harl.findLevel(logLevel);
    switch (find) 
    {
        case 0:
            harl.debug();
        case 1:
            harl.info();
        case 2:
            harl.warning();
        case 3:
            harl.error();
            break;
        default:
            std::cout << RED_TEXT << "[ Probably complaining about insignificant problems ]" << RESET_TEXT << std::endl;
            break;
    }

    return 0;
}

