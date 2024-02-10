/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:38:04 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/10 19:15:27 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe [number1] [number2] [number3] ..." << std::endl;
        exit(1);
    }
    for (int i = 1; i < argc; i++)
    {
        char *end;
        int number = std::strtol(argv[i], &end, 10);
        if (*end || number < 0)
        {
            std::cerr << "Invalid number:: " << argv[i] << std::endl;
            exit(1);
        }
        sequenceVector.push_back(number);
        sequenceList.push_back(number);
    }

    std::cout << "vector: ";
    for (std::vector<int>::iterator it = sequenceVector.begin(); it != sequenceVector.end(); it++)
        std::cout << *it << " "; 
    std::cout << std::endl;
    std::cout << "list: ";
    for (std::list<int>::iterator it = sequenceList.begin(); it != sequenceList.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::displaySequence(const std::string &message)
{
    std::cout << message << std::endl;
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = sequenceVector.begin(); it != sequenceVector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "List: ";
    for (std::list<int>::iterator it = sequenceList.begin(); it != sequenceList.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::displayTime(const std::string &containerType, std::chrono::microseconds duration)
{
    std::cout << containerType << " time: " << duration.count() << " microseconds" << std::endl;
}

void PmergeMe::createPairVector()
{
    int size;
	unsigned int i;

	i = 0;
	size = this->sequenceVector.size() / 2;
	while (size != 0)
	{
		this->sequenceVector.push_back(std::make_pair(this->sequenceVector.at(i), this->sequenceVector.at(i + 1)));
		i += 2;
		size--;
	}
}