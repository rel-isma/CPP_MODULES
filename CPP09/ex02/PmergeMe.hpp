/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:38:01 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/13 19:08:36 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class Timer {
private:
    clock_t start_time;

public:
    void start() {
        start_time = clock();
    }

    double elapsed() const {
        return static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC;
    }
};

class PmergeMe
{
    private:
    /*---------------this for vector---------------------------*/
        std::vector<int> sequenceVector;
        std::vector<std::pair<int, int> > sequencePairVector;
        std::vector<int> mainChain;
        std::vector<int> pend;
        std::vector<int> jacobS;
        std::vector<int> positions;

        void getSequenceVector(int argc, char *argv[]);
        void createPairVector();
        void sortPairVector();
        void createMainChainAndPendVector();
        void insertToMCVector();
        int jacobsthalVector(int n);
        void generateJacobVector();
        void generatePositionsVector();
    /*----------------------------------------------------------*/
    
    /*---------------this for list---------------------------*/
        std::list<int> sequenceList;
        std::list<std::pair<int, int> > sequencePairList;
        std::list<int> mainChainList;
        std::list<int> pendList;
        std::list<int> jacobSList;
        std::list<int> positionsList;

        void getSequenceList(int argc, char *argv[]);
        void createPairList();
        void sortPairList();
        void createMainChainAndPendList();
        void insertToMCList();
        int jacobsthalList(int n);
        void generateJacobList();
        void generatePositionsList();
    /*----------------------------------------------------------*/

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &pmergeMe);
        PmergeMe &operator=(const PmergeMe &pmergeMe);
        ~PmergeMe();


        void performSortIVector(int argc, char *argv[]);
        void performSortIList(int argc, char *argv[]);
        void displaySequenceInfo();

};

#endif // PMERGEME_HPP
