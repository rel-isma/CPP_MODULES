/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:38:04 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/13 05:22:00 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*-----------Orthodox Canonical Form-----------------*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        this->sequenceVector = obj.sequenceVector;
        this->sequencePairVector = obj.sequencePairVector;
        this->mainChain = obj.mainChain;
        this->pend = obj.pend;
        this->jacobS = obj.jacobS;
        this->positions = obj.positions;

        this->sequenceList = obj.sequenceList;
        this->sequencePairList = obj.sequencePairList;
        this->mainChainList = obj.mainChainList;
        this->pendList = obj.pendList;
        this->jacobSList = obj.jacobSList;
        this->positionsList = obj.positionsList;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

/*-----------Member Function-----------------for vector--------------------*/

void PmergeMe::displaySequenceInfo()
{
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = sequenceVector.begin(); it != sequenceVector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "After: ";
    for (std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::getSequenceVector(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe [number1] [number2] [number3] ..." << std::endl;
        exit(1);
    }
    for (int i = 1; i < argc; i++)
    {
        char *end;
        if (argv[i][0] == '\0')
        {
            std::cerr << "Invalid number: " << argv[i] << std::endl;
            exit(1);
        }
        int number = std::strtol(argv[i], &end, 10);
        if (*end || number < 0)
        {
            std::cerr << "Invalid number:: " << argv[i] << std::endl;
            exit(1);
        }
        sequenceVector.push_back(number);
    }
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

void PmergeMe::createMainChainAndPendVector()
{
    this->mainChain.push_back(this->sequencePairVector.at(0).second);

    for (unsigned int i = 0; i < this->sequencePairVector.size(); i++)
    {
        this->mainChain.push_back(this->sequencePairVector.at(i).first);
        this->pend.push_back(this->sequencePairVector.at(i).second);
    }
}

int PmergeMe::jacobsthalVector(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthalVector(n - 1) + 2 * jacobsthalVector(n - 2);
}

void PmergeMe::generateJacobVector()
{
    size_t size;
    size_t jcobSIndex;
    size_t index;

    size = this->pend.size();
    index = 3;
    while ((jcobSIndex = this->jacobsthalVector(index)) < size - 1)
    {
        this->jacobS.push_back(jcobSIndex);
        index++;
    }
}

void PmergeMe::generatePositionsVector()
{
    size_t value;
    size_t pos;
    size_t lastPos;
    size_t i;

    if (this->pend.empty())
        return;
    this->generateJacobVector();
    lastPos = 1;
    value = 1;
    i = 0;

    while (i < this->jacobS.size())
    {
        value = this->jacobS.at(i);
        this->positions.push_back(value);

        pos = value - 1;
        while (pos > lastPos)
        {
            this->positions.push_back(pos);
            pos--;
        }
        lastPos = value;
        i++;
    }
    while (value++ < this->pend.size())
    {
        this->positions.push_back(value);
    }
}

void PmergeMe::insertToMCVector()
{
    int target;
    size_t endPos;
    size_t addedCount;
    size_t pos;
    std::vector<int>::iterator lower;

    this->generatePositionsVector();
    addedCount = 0;
    for (std::vector<int>::iterator it = this->positions.begin(); it != this->positions.end(); it++)
    {
        target = this->pend.at(*it - 1);
        endPos = *it + addedCount;
        lower = std::lower_bound(this->mainChain.begin(), this->mainChain.end(), target);
        pos = lower - this->mainChain.begin();
        this->mainChain.insert(this->mainChain.begin() + pos, target);
        addedCount++;
    }
    if (this->sequenceVector.size() % 2 != 0)
    {
        target = this->sequenceVector.at(this->sequenceVector.size() - 1);
        lower = std::lower_bound(this->mainChain.begin(), this->mainChain.end(), target);
        pos = lower - this->mainChain.begin();
        this->mainChain.insert(this->mainChain.begin() + pos, target);
    }
}

void PmergeMe::performSortIVector(int argc, char *argv[])
{
    getSequenceVector(argc, argv);
    if (this->sequenceVector.size() == 1)
    {
        this->mainChain.push_back(this->sequenceVector.at(0));
        return;
    }
    createPairVector();
    sortPairVector();
    createMainChainAndPendVector();
    insertToMCVector();
}

/*-----------Member Function-----------------for list--------------------*/

void PmergeMe::getSequenceList(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe [number1] [number2] [number3] ..." << std::endl;
        exit(1);
    }
    for (int i = 1; i < argc; i++)
    {
        char *end;
        if (argv[i][0] == '\0')
        {
            std::cerr << "Invalid number: " << argv[i] << std::endl;
            exit(1);
        }
        int number = std::strtol(argv[i], &end, 10);
        if (*end || number < 0)
        {
            std::cerr << "Invalid number:: " << argv[i] << std::endl;
            exit(1);
        }
        sequenceList.push_back(number);
    }
}

void PmergeMe::createPairList()
{
    int size;
    unsigned int i;

    std::list<int>::iterator it;
    it = this->sequenceList.begin();

    i = 0;
    size = this->sequenceList.size() / 2;
    while (size != 0)
    {
        this->sequencePairList.push_back(std::make_pair(*it, *(++it)));
        it++;
        size--;
    }
}

void PmergeMe::sortPairList()
{
    int tmp;

    for (std::list<std::pair<int, int> >::iterator it = this->sequencePairList.begin(); it != this->sequencePairList.end(); it++)
    {
        if (it->first < it->second)
        {
            tmp = it->first;
            it->first = it->second;
            it->second = tmp;
        }
    }
    this->sequencePairList.sort();
}

void PmergeMe::createMainChainAndPendList()
{

    for (std::list<std::pair<int, int> >::iterator it = this->sequencePairList.begin(); it != this->sequencePairList.end(); it++)
    {
        this->mainChainList.push_back(it->first);
        this->pendList.push_back(it->second);
    }
    this->mainChainList.push_front(this->pendList.front());
}

int PmergeMe::jacobsthalList(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthalList(n - 1) + 2 * jacobsthalList(n - 2);
}

void PmergeMe::generateJacobList()
{
    size_t size;
    size_t jcobSIndex;
    size_t index;

    size = this->pendList.size();
    index = 3;
    while ((jcobSIndex = this->jacobsthalList(index)) < size - 1)
    {
        this->jacobSList.push_back(jcobSIndex);
        index++;
    }
}

void PmergeMe::generatePositionsList()
{
    size_t value;
    size_t pos;
    size_t lastPos;
    size_t i;

    if (this->pendList.empty())
        return;
    this->generateJacobList();
    lastPos = 1;
    value = 1;
    i = 0;

    while (i < this->jacobSList.size())
    {
        value = this->jacobSList.front();
        this->positionsList.push_back(value);

        pos = value - 1;
        while (pos > lastPos)
        {
            this->positionsList.push_back(pos);
            pos--;
        }
        lastPos = value;
        i++;
    }
    while (value++ < this->pendList.size())
    {
        this->positionsList.push_back(value);
    }
}

void PmergeMe::insertToMCList()
{
    int target;
    size_t endPos;
    size_t addedCount;
    std::list<int>::iterator lower;

    this->generatePositionsList();
    addedCount = 0;
    this->pendList.pop_front();
    for (std::list<int>::iterator it = this->positionsList.begin(); it != this->positionsList.end(); it++)
    {
        if (this->pendList.empty())
            break;
        target = this->pendList.front();
        this->pendList.pop_front();
        endPos = *it + addedCount;
        lower = std::lower_bound(this->mainChainList.begin(), this->mainChainList.end(), target);
        for (std::list<int>::iterator it = this->mainChainList.begin(); it != this->mainChainList.end(); it++)
        {
            if (*it == *lower)
            {
                this->mainChainList.insert(it, target);
                break;
            }
        }
        addedCount++;
    }
    if (this->sequenceList.size() % 2 != 0)
    {
        target = this->sequenceList.front();
        this->sequenceList.pop_front();
        lower = std::lower_bound(this->mainChainList.begin(), this->mainChainList.end(), target);
        for (std::list<int>::iterator it = this->mainChainList.begin(); it != this->mainChainList.end(); it++)
        {
            if (*it == *lower)
            {
                this->mainChainList.insert(it, target);
                break;
            }
        }
    }
}

void PmergeMe::performSortIList(int argc, char *argv[])
{
    getSequenceList(argc, argv);
    if (this->sequenceList.size() == 1)
    {
        this->mainChainList.push_back(this->sequenceList.front());
        return;
    }
    createPairList();
    sortPairList();
    createMainChainAndPendList();
    insertToMCList();
}
