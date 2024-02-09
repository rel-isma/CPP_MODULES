/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:24:10 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/09 16:32:52 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class RPN
{
    private:
        std::string expression;
        std::stack<int> operandStack;
        
        bool isOperator(char c);
        void performOperation(char op);

    public:
        RPN();
        RPN(const std::string &expression);
        RPN(const RPN &rpn);
        RPN &operator=(const RPN &rpn);
        ~RPN();

        int calculate();

};

#endif // RPN_HPP
