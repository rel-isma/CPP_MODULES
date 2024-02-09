/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:24:13 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/09 16:32:17 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : expression("") {}

RPN::RPN(const std::string &expression) : expression(expression) {}

RPN::RPN(const RPN &rpn)
{
    *this = rpn;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rpn)
{
    if (this == &rpn)
        return *this;
    this->expression = rpn.expression;
    return *this;
}


bool RPN::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::performOperation(char op)
{
    if (operandStack.size() < 2)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    int rhs = operandStack.top();
    operandStack.pop();
    int lhs = operandStack.top();
    operandStack.pop();

    switch (op)
    {
        case '+':
            operandStack.push(lhs + rhs);
            break;
        case '-':
            operandStack.push(lhs - rhs);
            break;
        case '*':
            operandStack.push(lhs * rhs);
            break;
        case '/':
            if (rhs == 0)
            {
                std::cerr << "Error: Division by zero" << std::endl;
                exit(1);
            }
            operandStack.push(lhs / rhs);
            break;
        default:
            std::cerr << "Error" << std::endl;
            exit(1);
    }
}

int RPN::calculate()
{
    std::stringstream ss(expression);
    std::string token;

    if (expression.empty())
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    while (getline(ss, token, ' '))
    {
        if (token.length() == 1 && isOperator(token[0]))
        {
            performOperation(token[0]);
        }
        else
        {
            try
            {
                char *end;
                int value = std::strtol(token.c_str(), &end, 10);
                if (*end != '\0')
                    throw std::invalid_argument("Invalid token");
                if (value > 9 || value < 0)
                    throw std::invalid_argument("Invalid token");
                operandStack.push(value);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
        }
    }

    if (operandStack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    return operandStack.top();
}