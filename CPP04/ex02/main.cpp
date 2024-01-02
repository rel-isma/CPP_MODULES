/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:55:09 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/18 11:14:54 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const int size = 4;
    Animal *animals[size];

    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0){
            animals[i] = new Dog();
        }
        else {
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < size; ++i) {
        std::cout << animals[i]->getType() + " :: ";
        animals[i]->makeSound();
        delete animals[i];
    }
    return 0;
}
