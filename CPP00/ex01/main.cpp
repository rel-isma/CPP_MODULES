/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:54:01 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/10 23:15:39 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip>
#define RED_TEXT "\x1B[31m"
#define GREEN_TEXT "\x1B[32m"
#define BLUE_TEXT "\x1B[34m"
#define YELLOW_TEXT "\x1B[33m"
#define RESET_TEXT "\x1B[0m"

void printHeader()
{
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "|   " << YELLOW_TEXT << "Index" << RESET_TEXT << "   ";
    std::cout << "| " << YELLOW_TEXT << "First Name" << RESET_TEXT << " ";
    std::cout << "| " << YELLOW_TEXT << "Last Name" << RESET_TEXT << "  ";
    std::cout << "|  " << YELLOW_TEXT << "Nickname" << RESET_TEXT << "  |" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
}

void    searchPhoneBook(Phonebook *phonebook)
{
    int size;

    if (phonebook->isEmpty()) {
            std::cout << "Phonebook is empty. No contacts to search." << std::endl;
            return ;
    }
    printHeader();
    Contact *contacts = phonebook->getContacts();
    size = phonebook->getSize();
    if (phonebook->getSize() > 8) {
       size = 8;
    } // |           |
    for (int i = 0; i < size; ++i) 
    {
        std::cout << "|     " << i + 1 << "     |";
        std::string firstName = contacts[i].getFirstName();
        std::string lastName = contacts[i].getLastName();
        std::string nickname = contacts[i].getNickName();
        if (firstName.length() > 10)
            firstName = firstName.substr(0, 10) + ".";
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 10) + ".";
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 10) + ".";
        std::cout << std::right << std::setw(12) << firstName;
        std::cout << "|" << std::right << std::setw(12) <<  lastName;
        std::cout << "|" << std::right << std::setw(12) << nickname << "|" << std::endl;
    }
    int index;
    std::cout << "Enter the index of the contact to display: ";
    if (!(std::cin >> index)) {
        std::cout << "Invalid input. Please enter a valid index." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }
    if (index < 0 || index >= phonebook->getSize()) {
        std::cout << "Invalid input. Please enter a valid index." << std::endl;
        return ;
    } 
    else {
        contacts[index].displayContactDetails();
        return ;
    }
}

void    addPhoneBook(Phonebook *phonebook)
{
    if (phonebook->isFull())
    {
        std::cout << "Phonebook is full. Oldest contact will be replaced." << std::endl;
        // phonebook->removeOldestContact();
    }
    Contact contact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    std::cout << "Enter First Name: ";
    std::cin >> firstName;
    contact.setFirstName(firstName);
    std::cout << "Enter Last Name: ";
    std::cin >> lastName;
    contact.setLastName(lastName);
    std::cout << "Enter Nickname: ";
    std::cin >> nickname;
    contact.setNickName(nickname);
    std::cout << "Enter Phone Number: ";
    std::cin >> phoneNumber;
    contact.setPhoneNumber(phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::cin >> darkestSecret;
    contact.setDarkestSecret(darkestSecret);
    phonebook->addContact(contact);
}
int main() 
{
    Phonebook phonebook;
    std::string command;

    std::cout << "\033[1;34m";
    std::cout << "******************************" << std::endl;
    std::cout << "*    Welcome to My Awesome   *" << std::endl;
    std::cout << "*      PhoneBook App         *" << std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << "\033[0m" << std::endl;

    while (true) {
        std::cout << "Enter a command (" << GREEN_TEXT << "ADD" << RESET_TEXT;
        std::cout << ", " << GREEN_TEXT << "SEARCH" << RESET_TEXT << ", " << GREEN_TEXT << "EXIT" << RESET_TEXT << "): ";
        if (std::cin.eof()) {
            std::cout << "Goodbye! Your contacts are lost forever." << std::endl;
            break;
        }
        std::cin >> command;
        if (command == "ADD") {
            addPhoneBook(&phonebook);
        }
        else if (command == "SEARCH") {
            searchPhoneBook(&phonebook);
            continue;
        } 
        else if (command == "EXIT") {
            std::cout << "Goodbye! Your contacts are lost forever." << std::endl;
            break;
        } 
        else {
            std::cout << RED_TEXT << "Invalid command. Please enter: " << RESET_TEXT;
            std::cout << GREEN_TEXT << "ADD" << RESET_TEXT << ", " << GREEN_TEXT << "SEARCH" << RESET_TEXT;
            std::cout << ", " << RED_TEXT << "or " << RESET_TEXT << GREEN_TEXT << "EXIT" << RESET_TEXT << std::endl;
        }
    }
    return 0;
}
