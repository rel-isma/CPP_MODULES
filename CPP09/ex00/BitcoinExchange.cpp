/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:13:05 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/28 23:29:42 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &inputFilename)
{
    // readExchangeRates("data.csv");
    inputFile.open(inputFilename.c_str());

    if (!inputFile.is_open())
    {
        throw std::runtime_error("could not open file.");
    }
}

void BitcoinExchange::readExchangeRates(const std::string &exchangeRatesFilename)
{

    std::ifstream file(exchangeRatesFilename);
    if (!file.is_open())
    {
        throw std::runtime_error("could not open exchange rates file.");
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream iss(line);
        std::string date;
        double rate = 0.0;

        if (getline(iss, date, ','))
        {
            iss >> rate;
            exchangeRates[date] = rate;
            std::cout << "date: " << date << " rate: " << rate << std::endl;
        }
    }
    file.close();
}

// double BitcoinExchange::getExchangeRate(const std::string &date) const
// {
//     std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);

//     if (it == exchangeRates.begin() && it->first > date) {
//         return it->second;
//     }

//     return (it != exchangeRates.begin()) ? (--it)->second : it->second;
// }

void BitcoinExchange::processInput()
{
    
    std::string line;
    while (std::getline(inputFile, line))
    {
        try
        {
            processLine(line);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}


void BitcoinExchange::processLine(const std::string &line)
{
    std::stringstream iss(line);
    std::string dateStr;
    std::string valueStr;
    double value;

    // 2011-01-03 | 2
    if (std::getline(iss, dateStr, '|'))
    {
        // strtrim
        dateStr.erase(0, dateStr.find_first_not_of(" \t\n\r\f\v"));
        dateStr.erase(dateStr.find_last_not_of(" \t\n\r\f\v") + 1);

        if (std::getline(iss, valueStr))
        {
            std::stringstream valueIss(valueStr);
            if (!(valueIss >> value)) {
                throw std::invalid_argument("bad input => " + dateStr + valueStr);
            }

            if (value > 1000) {
                throw std::out_of_range("too large a number.");
            }
            if (value <= 0) {
                throw std::out_of_range("not a positive number.");
            }
            std::cout << "Date: " << dateStr << ", Value: " << value << std::endl;
        } 
        else
        {
            throw std::invalid_argument("bad input => " + line);
        }
    }
    else
    {
        throw std::invalid_argument("bad input => " + line);
    }
    // double exchangeRate = getExchangeRate(dateStr);
    // printResult(dateStr, value, exchangeRate);
}


void BitcoinExchange::printResult(const std::string &date, double value, double exchangeRate) const
{
    std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
}
