/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:39:00 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/28 12:50:12 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Shrubbery Creation", 100, 120), target("DefaultTarget") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target(target) {
    std::srand(std::time(nullptr));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if(this->getsignedS() == false)
        throw AForm::SigTooException();
    else if (executor.getGrade() > this->getgradeToExecute())
        throw AForm::GradeTooLowException();
    else {
        std::cout << "*drilling noises*" << std::endl;
        if (std::rand() % 2 == 0) {
            std::cout << target << " has been robotomized successfully!" << std::endl;
        } else {
            std::cout << "Robotomy failed for " << target << std::endl;
        }
    }
}

