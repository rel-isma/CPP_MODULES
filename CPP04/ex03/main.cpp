/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:12:37 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/20 11:46:04 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp[5];
    tmp[0] = src->createMateria("ice");
    me->equip(tmp[0]);
    tmp[1] = src->createMateria("cure");
    me->equip(tmp[1]);
    tmp[2] = src->createMateria("khoch");
    me->equip(tmp[2]);
    tmp[3] = src->createMateria("cure");
    me->equip(tmp[3]);
    tmp[4] = src->createMateria("ice");
    me->equip(tmp[4]);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->unequip(1);


    
    delete tmp[0];
    delete tmp[1];
    delete bob;
    delete me;
    delete src;

    return 0;
}
