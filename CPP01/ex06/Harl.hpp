/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:04:26 by rel-isma          #+#    #+#             */
/*   Updated: 2023/09/27 14:48:57 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#define RED_TEXT "\x1B[31m"
#define GREEN_TEXT "\x1B[32m"
#define BLUE_TEXT "\x1B[34m"
#define YELLOW_TEXT "\x1B[33m"
#define RESET_TEXT "\x1B[0m"

class Harl
{
    public:
        int findLevel(std::string level);
        void debug();
        void info();
        void warning();
        void error();
};

#endif