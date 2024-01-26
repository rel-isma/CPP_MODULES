/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:49:31 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/25 21:08:14 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    for (; it != ite; ++it)
    {
        if (*it == value)
            return it;
    }
    throw std::invalid_argument("Value not found");
}

#endif
