/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:55:09 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/19 22:33:47 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "\n==============================\n" << std::endl;
    const WrongAnimal *_meta = new WrongAnimal();
    const WrongAnimal *_i = new WrongCat();
    std::cout << _i->getType() << std::endl;
    std::cout << _meta->getType() << std::endl;
    _meta->makeSound();
    _i->makeSound();
    delete _meta;
    delete _i;
    return 0;
}
