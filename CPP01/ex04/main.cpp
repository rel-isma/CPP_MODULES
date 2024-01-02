/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:09:20 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/08 13:44:53 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argms.hpp"

int main(int argc, char* argv[])
{
    // check argms
    if (argc != 4) 
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
 
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) 
    {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) 
    {
        std::cerr << "Error: Unable to create output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outputFile << line;
        if (!inputFile.eof())
            outputFile << std::endl;
    }
    inputFile.close();
    outputFile.close();
    std::cout << "File '" << filename << "' has been processed. Modified content saved in '" << outputFilename << "'." << std::endl;
    return 0;
}

