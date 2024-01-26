/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:53:49 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/26 16:12:41 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
}
Span::Span(unsigned int n) : N(n)
{
}
Span::Span(const Span &r) : N(r.N), numbers(r.numbers)
{
}

Span &Span::operator=(const Span &r)
{
    if (this == &r)
        return *this;
    this->N = r.N;
    this->numbers = r.numbers;
    return *this;
}
void Span::addNumber(int num)
{
    if (this->numbers.size() >= this->N)
        throw std::runtime_error("Error: Span is full");
    this->numbers.push_back(num);
}

int Span::shortestSpan() const
{
    if (this->numbers.size() <= 1)
        throw std::runtime_error("Error: Span is empty or has only one element");
    std::vector<int> tmp = this->numbers;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size() - 1; i++)
    {
        if (tmp[i + 1] - tmp[i] < min)
            min = tmp[i + 1] - tmp[i];
    }
    return min;
}

int Span::longestSpan() const
{
    if (this->numbers.size() <= 1)
        throw std::runtime_error("Error: Span is empty or has only one element");
    std::vector<int> tmp = this->numbers;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

void Span::addNumbers(const std::vector<int> &nums)
{
    if (this->numbers.size() + nums.size() > this->N)
        throw std::runtime_error("Error: Span is full");
    this->numbers.insert(this->numbers.end(), nums.begin(), nums.end());
}

Span::~Span()
{
}