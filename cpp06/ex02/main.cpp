/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:55:05 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/15 14:39:49 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify_functions.hpp"
#include <iostream>

int main()
{
    Base *obj = generate();

    std::cout << "Identifying pointer: ";
    identify(obj);

    std::cout << "Identifying reference: ";
    identify(*obj);

    delete obj;

    return 0;
}
