/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:52:18 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/26 16:12:09 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        unsigned int N;
        std::vector<int> numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &r);
        Span &operator=(const Span &r);
        ~Span();
        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;
        void addNumbers(const std::vector<int> &nums);
};

#endif
