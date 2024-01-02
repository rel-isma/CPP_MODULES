/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:51:41 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/28 12:47:00 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool signedS;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class SigTooException : public std::exception {
            public:
                const char* what() const throw();
        };
        const std::string& getName() const;
        bool getsignedS() const;
        int getgradeToSign() const;
        int getgradeToExecute() const;

        void beSigned(const Bureaucrat& bureaucrat);

        virtual void execute(const Bureaucrat& executor) const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
