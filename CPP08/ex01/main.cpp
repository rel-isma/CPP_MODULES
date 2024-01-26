/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:12:54 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/26 17:56:07 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

int RandomNumber ()
{
    return (std::rand()%100);
}

int main()
{
    try
    {
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        Span sp2 = Span(10);
        std::vector<int> moreNumbers(10);
        std::generate(moreNumbers.begin(), moreNumbers.end(), RandomNumber);

        std::cout << "myvector contains:";
	    for (std::vector<int>::iterator it = moreNumbers.begin(); it != moreNumbers.end(); ++it)
		    std::cout << ' ' << *it;
	    std::cout << std::endl;

        sp2.addNumbers(moreNumbers);
        std::cout << "Shortest Span after adding more numbers: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span after adding more numbers: " << sp2.longestSpan() << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}


