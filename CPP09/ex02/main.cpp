/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:47:26 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/13 19:55:59 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    clock_t start, end, startList, endList;
    double cpu_time_usedList;
    double cpu_time_used;
    PmergeMe pmergeMe;

    /// for vector
    start = clock();
    pmergeMe.performSortIVector(argc, argv);
    end = clock();

    /// for list
    startList = clock();
    pmergeMe.performSortIList(argc, argv);
    endList = clock();


    // display the seque
    pmergeMe.displaySequenceInfo();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of  " << argc - 1;
    std::cout << " elements with std::vector : " << std::fixed << cpu_time_used << " s" << std::endl;
    cpu_time_usedList = ((double) (endList - startList)) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of  " << argc - 1;
    std::cout << " elements with std::list : " << std::fixed << cpu_time_usedList << " s" << std::endl;
    return 0;
}
