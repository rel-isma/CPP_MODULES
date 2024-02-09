/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:24:13 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/09 15:25:18 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>


RPN::RPN() : expression("") {}

RPN::RPN(const std::string &expression) : expression(expression) {}

RPN::RPN(const RPN &rpn) {
    *this = rpn;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rpn)
{
    this->expression = rpn.expression;
    return *this;
}


int RPN::calculate()
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            operandStack.push(std::atoi(token.c_str()));
        } else if (token.size() == 1 && isOperator(token[0])) {
            performOperation(token[0]);
        } else {
            std::cerr << "Error: Invalid token - " << token << std::endl;
            return 0;
        }
    }

    if (operandStack.size() == 1) {
        return operandStack.top();
    } else {
        std::cerr << "Error: Invalid expression" << std::endl;
        return 0;
    }
}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::performOperation(char op) {
    if (operandStack.size() < 2) {
        std::cerr << "Error: Not enough operands for operator " << op << std::endl;
        return;
    }

    int operand2 = operandStack.top();
    operandStack.pop();
    int operand1 = operandStack.top();
    operandStack.pop();

    int result;

    switch (op) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                std::cerr << "Error: Division by zero" << std::endl;
                return;
            }
            break;
        default:
            std::cerr << "Error: Unknown operator " << op << std::endl;
            return;
    }

    operandStack.push(result);
}
