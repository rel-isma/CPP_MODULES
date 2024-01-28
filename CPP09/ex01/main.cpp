/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:31:18 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/28 18:34:34 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

main::main()
{
    std::cout <<  << std::endl;
    std::cout << std::endl;
}

main::~main()
{
        std::cerr << "" << std::endl;
}

main::main(const main& copy)
{
    *this = copy;
}

main& main::operator=(const main& obj)
{
    if (this != &obj)
    {

    }
    return (*this);
}
