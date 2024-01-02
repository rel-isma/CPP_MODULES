/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:55:09 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/19 22:45:34 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() 
{
    Brain* brain = new Brain();
    brain->printIdeas();
    const int arraySize = 4;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize; ++i) 
    {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    for (int i = 0; i < arraySize; ++i) {
        animals[i]->makeSound();
        delete animals[i];
    }
    delete brain;
    return 0;
}