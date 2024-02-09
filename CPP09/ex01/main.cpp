/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:31:18 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/09 15:23:28 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }

    RPN rpn(argv[1]);
    int result = rpn.calculate();

    if (result != 0) {
        std::cout << result << std::endl;
        return 0;
    } else {
        return 1;
    }
}

