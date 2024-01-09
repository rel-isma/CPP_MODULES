/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:17:47 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/08 22:01:04 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data {

    int intValue;
    char charValue;

    Data();
    Data(int intValue, char charValue);
    ~Data();

    bool operator==(const Data& other) const;
};

#endif
