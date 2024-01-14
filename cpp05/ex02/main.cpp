/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:22:21 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/11 12:29:30 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat john("John", 1);
        ShrubberyCreationForm shrubForm("Garden");
        RobotomyRequestForm robotomyForm("Robot");
        PresidentialPardonForm pardonForm("Criminal");

        std::cout << john << std::endl;

        std::cout << shrubForm << std::endl;
        john.signForm(shrubForm);
        john.executeForm(shrubForm);

        std::cout << robotomyForm << std::endl;
        john.signForm(robotomyForm);
        john.executeForm(robotomyForm);

        std::cout << pardonForm << std::endl;
        john.signForm(pardonForm);
        john.executeForm(pardonForm);
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << "Exception: " << e << std::endl;
    }
    return 0;
}

