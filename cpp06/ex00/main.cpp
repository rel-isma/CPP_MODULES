/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:12:55 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/04 18:19:39 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    std::string inputLiteral = argv[1];
    ScalarConverter::convert(inputLiteral);
    return 0;
}

// #include<iostream>
// #include<limits>

// using namespace std;

// int main(){
//     // Assigning the value of Infinity to Inf variable.
//     int Inf = numeric_limits<int>::max();  
//     // Converting the value to negative and assigning it to negative_Inf.
//     int negative_Inf= Inf*-1;        

//     cout << "The value of Positive infinity is : " << Inf << endl;
//     cout << "The value of Negative infinity is : " << negative_Inf << endl;

//     return 0;
// }