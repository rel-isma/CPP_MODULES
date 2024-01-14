/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_functions.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:27:53 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/13 10:56:02 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_FUNCTIONS_HPP
#define IDENTIFY_FUNCTIONS_HPP

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate();

void identify(Base *p);

void identify(Base &p);

#endif
