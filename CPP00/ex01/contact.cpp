/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:27:57 by rel-isma          #+#    #+#             */
/*   Updated: 2023/09/21 23:10:42 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <istream>

Contact::Contact()
{
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecret = "";
}
std::string Contact::getFirstName()
{
    return firstName;
}
std::string Contact::getLastName()
{
    return lastName;
}
std::string Contact::getNickName()
{
    return nickName;
}
std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}
std::string Contact::getDarkestSecret()
{
    return darkestSecret;
}

void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}
void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}
void Contact::setNickName(std::string nickName)
{
    this->nickName = nickName;
}
void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}
void Contact::displayContactDetails()
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
