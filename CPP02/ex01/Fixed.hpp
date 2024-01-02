/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:57:02 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/10 19:57:09 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed 
{
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        ~Fixed();
        float toFloat() const;
        int toInt() const;
        Fixed& operator=(const Fixed& fixed);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
