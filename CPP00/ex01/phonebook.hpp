/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:26:50 by rel-isma          #+#    #+#             */
/*   Updated: 2023/09/27 14:16:18 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <string>

class Phonebook
{
    private:
        Contact contacts[8];
        int contactCout;
    public:
        Phonebook();
        bool isFull();
        bool isEmpty();
        int getSize();
        void addContact(Contact &contact);
        void removeOldestContact();
        Contact *getContacts();
        
};

#endif