/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:52:14 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/28 12:47:28 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default Form"), signedS(false), gradeToSign(50), gradeToExecute(75) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), signedS(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
        if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    }

AForm::AForm(const AForm& other) : name(other.name), signedS(other.signedS),
                                   gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        signedS = other.signedS;
    }
    return *this;
}

AForm::~AForm() {}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}
const char* AForm::SigTooException::what() const throw() {
    return "Form not signed";
}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getsignedS() const {
    return signedS;
}

int AForm::getgradeToSign() const {
    return gradeToSign;
}

int AForm::getgradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= gradeToSign) {
        signedS = true;
    } else {
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() << ", Sign Grade: " << form.getgradeToSign() << ", Execute Grade: " << form.getgradeToExecute() << ", Signed: " << (form.getsignedS() ? "Yes" : "No");
    return os;
}
