/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:50:42 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/08 16:16:15 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const std::string& type);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();
    void makeSound() const;
};

#endif
