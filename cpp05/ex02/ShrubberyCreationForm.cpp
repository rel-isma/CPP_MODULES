/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:28:53 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/11 12:29:28 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery Creation", 100, 120), target("DefaultTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {
        
    }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if(this->getsignedS() == false)
        throw AForm::SigTooException();
    if (executor.getGrade() > this->getgradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream outfile(target + "_shrubbery");
    if (!outfile.good())
        throw "failed to open the file";
    
    outfile << "          &&& &&  & &&\n"
            << "      && &\\/&\\|& ()|/ @, &&\n"
            << "      &\\/(/&/&||/& /_/)_&/_&\n"
            << "   &() &\\/&|()|/&\\/ '%" << " & ()\n"
            << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
            << "&&   && & &| &| /& & % ()& /&&\n"
            << " ()&_---()&\\&\\|&&-&&--%---()~\n"
            << "     &&     \\|||\n"
            << "             |||\n"
            << "             |||\n"
            << "             |||\n"
            << "       , -=-~  .-^- _" << std::endl;
    
    outfile.close();
}

