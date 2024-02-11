/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:38:01 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/11 16:46:58 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>

class PmergeMe
{
    private:
        std::vector<int> sequenceVector;
        std::vector<std::pair<int, int> > sequencePairVector;
        std::vector<int> mainChain;
        std::vector<int> pend;
        std::list<int> sequenceList;
        std::vector<int> jacobS;

        void displaySequence(const std::string &message);
        void displayTime(const std::string &containerType, std::chrono::microseconds duration);
        void createPairVector();
        void sortPairVector();
        void createMainChainAndPend();
        void insertToMC();
        int jacobsthal(int n);
        void generateJacob();

    public:
        PmergeMe(int argc, char *argv[]);
        void performSort();

};

#endif // PMERGEME_HPP
