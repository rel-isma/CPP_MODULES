/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:43:07 by rel-isma          #+#    #+#             */
/*   Updated: 2023/09/30 12:12:51 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <istream>

Phonebook::Phonebook()
{
    contactCout = 0;
}

bool Phonebook::isFull()
{
    return (contactCout == 8);
}
bool Phonebook::isEmpty()
{
    return (contactCout == 0);
}

int Phonebook::getSize()
{
    return contactCout;
}
void Phonebook::addContact(Contact &contact)
{
     contacts[contactCout % 8] = contact;
        contactCout++;
}
Contact *Phonebook::getContacts()
{
   return contacts;
}

void Phonebook::removeOldestContact()
{
    if (!isEmpty())
    {
        for (int i = 0; i < contactCout - 1; i++)
        {
            contacts[i] = contacts[i + 1];
        }
        contactCout--;
    }
}




