/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:55:05 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/13 10:55:43 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify_functions.hpp"
#include <iostream>

int main()
{
    Base *obj = generate();

    std::cout << "Identifying through pointer: ";
    identify(obj);

    std::cout << "Identifying through reference: ";
    identify(*obj);

    delete obj;

    return 0;
}
