/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:41:51 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/30 11:38:05 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) {
    *this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& rhs) {
    (void) rhs;
    return (*this);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {

    std::string formNames[] = {"robotomy request","presidential pardon","shrubbery creation"};
    AForm*      form;
    int         i;
    
    for (i = 0; i <= 2; i++ ) {
        if ( formName == formNames[i] ) {
            break ;
        }
    }

    switch (i)
    {
        case(0):
            form = new RobotomyRequestForm( target );
            std::cout << "Intern creates: " << *form << std::endl;
            break;
        case(1):
            form = new PresidentialPardonForm( target );
            std::cout << "Intern creates: " << *form << std::endl;
            break;
        case(2):
            form = new ShrubberyCreationForm( target );
            std::cout << "Intern creates: " << *form << std::endl;
            break;
        default:
            form = NULL;
            std::cout << "Intern couldn't create form. Unknown form name: " << formName << " form" << std::endl;
    }
    return form;
}
