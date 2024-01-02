/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:18:58 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/07 16:58:31 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed& other);
        ~Fixed();
        Fixed& operator=(const Fixed& other);
        void setRawBits(int const raw);
        int getRawBits() const;
};

#endif