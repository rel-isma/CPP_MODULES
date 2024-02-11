/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:38:04 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/11 16:48:26 by rel-isma         ###   ########.fr       */
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
		this->sequencePairVector.push_back(std::make_pair(this->sequenceVector.at(i), this->sequenceVector.at(i + 1)));
		i += 2;
		size--;
	}
}



void PmergeMe::sortPairVector()
{
    int tmp;

    for (unsigned int i = 0; i < this->sequencePairVector.size(); i++)
    {
        if (this->sequencePairVector.at(i).first < this->sequencePairVector.at(i).second)
        {
            tmp = this->sequencePairVector.at(i).first;
            this->sequencePairVector.at(i).first = this->sequencePairVector.at(i).second;
            this->sequencePairVector.at(i).second = tmp;
        }
    }
    std::sort(this->sequencePairVector.begin(), this->sequencePairVector.end());
}



void PmergeMe::createMainChainAndPend()
{
    for (unsigned int i = 0; i < this->sequencePairVector.size(); i++)
    {
        this->mainChain.push_back(this->sequencePairVector.at(i).first);
        this->pend.push_back(this->sequencePairVector.at(i).second);
    }
}

int PmergeMe::jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::insertToMC()
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (i < this->sequenceVector.size())
    {
        if (i % 2 == 0)
        {
            this->sequenceVector.at(i) = this->mainChain.at(j);
            j++;
        }
        else
        {
            this->sequenceVector.at(i) = this->pend.at(k);
            k++;
        }
        i++;
    }
}

void PmergeMe::performSort()
{
    createPairVector();
    sortPairVector();
    createMainChainAndPend();
    insertToMC();
}

