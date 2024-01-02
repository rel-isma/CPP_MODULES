/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:15:11 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/20 11:36:19 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        learnedMaterias[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete learnedMaterias[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.learnedMaterias[i])
        {
            learnedMaterias[i] = other.learnedMaterias[i]->clone();
        }
        else
        {
            learnedMaterias[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete learnedMaterias[i];
            if (other.learnedMaterias[i])
            {
                learnedMaterias[i] = other.learnedMaterias[i]->clone();
            }
            else
            {
                learnedMaterias[i] = NULL;
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!learnedMaterias[i])
        {
            learnedMaterias[i] = m;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (learnedMaterias[i] && learnedMaterias[i]->getType() == type)
        {
            return learnedMaterias[i]->clone();
        }
    }
    return NULL;
}
