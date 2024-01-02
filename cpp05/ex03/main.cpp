/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:22:21 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/30 13:31:27 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"


int main() 
{
    try {
        Bureaucrat bureaucrat("John", 50);

        ShrubberyCreationForm shrubberyForm("Garden");

        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);

        Intern intern;
        AForm* newForm = intern.makeForm("shrubbery creation", "Backyard");

        if (newForm) {
            bureaucrat.signForm(*newForm);
            bureaucrat.executeForm(*newForm);
            delete newForm;
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

