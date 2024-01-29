/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:13:05 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/29 12:22:15 by rel-isma         ###   ########.fr       */
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

void ft_check_year(std::string year)
{
    if (year.size() != 4)
    {
        throw std::invalid_argument("bad input => " + year);
    }
    if (std::atoi(year.c_str()) < 2009 || std::atoi(year.c_str()) > 2022)
    {
        throw std::invalid_argument("bad input => " + year);
    }
}
void ft_check_month(std::string month)
{
    if (month.size() != 2)
    {
        throw std::invalid_argument("bad input => " + month);
    }
    if (std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
    {
        throw std::invalid_argument("bad input => " + month);
    }
}
void ft_check_day(std::string day , std::string month, std::string date)
{
    if (day.size() != 2)
    {
        throw std::invalid_argument("bad input => " + day);
    }
    if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 1 && std::atoi(day.c_str()) > 31)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 2 && std::atoi(day.c_str()) > 29)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 3 && std::atoi(day.c_str()) > 31)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 4 && std::atoi(day.c_str()) > 30)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 5 && std::atoi(day.c_str()) > 31)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 6 && std::atoi(day.c_str()) > 30)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 7 && std::atoi(day.c_str()) > 31)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 8 && std::atoi(day.c_str()) > 31)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 9 && std::atoi(day.c_str()) > 30)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 10 && std::atoi(day.c_str()) > 31)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 11 && std::atoi(day.c_str()) > 30)
    {
        throw std::invalid_argument("bad input => " + date);
    }
    if (std::atoi(month.c_str()) == 12 && std::atoi(day.c_str()) > 31)
    {
        throw std::invalid_argument("bad input => " + date);
    }
}
void ft_check_date(std::string date)
{
    std::string year;
    std::string month;
    std::string day;
    std::stringstream iss(date);
    
    std::getline(iss, year, '-');
    std::getline(iss, month, '-');
    std::getline(iss, day, '-');

    ft_check_year(year);
    ft_check_month(month);
    ft_check_day(day, month, date);
}


double BitcoinExchange::getExchangeRate(const std::string &dateStr) const
{
    auto it = exchangeRates.find(dateStr);
    if (it != exchangeRates.end()) {
        return it->second;
    }
    auto lowerBound = exchangeRates.lower_bound(dateStr);
    if (lowerBound != exchangeRates.begin()) {
        --lowerBound;
        int daysDifference = getDaysDifference(lowerBound->first, dateStr);
        if (daysDifference <= 7) {
            std::cout << "Using closest lower date: " << lowerBound->first << std::endl;
            return lowerBound->second;
        }
    }
    throw std::out_of_range("Exchange rate not available for the specified date: " + dateStr);
}

int getDaysDifference(const std::string &date1, const std::string &date2)
{
    
    return 30;
}

void BitcoinExchange::processLine(const std::string &line)
{
    std::stringstream iss(line);
    std::string dateStr;
    std::string valueStr;
    double value;

    if (line.find('|') == std::string::npos)
    {
        throw std::invalid_argument("bad input => " + line);
    }
    
    if (std::getline(iss, dateStr, '|'))
    {
        if (dateStr.back() != ' ')
            throw std::invalid_argument("bad input => " + line);
        
        dateStr.erase(0, dateStr.find_first_not_of(" \t\n\r\f\v"));
        dateStr.erase(dateStr.find_last_not_of(" \t\n\r\f\v") + 1);
        ft_check_date(dateStr);
        if (std::getline(iss, valueStr))
        {
            if (valueStr.front() != ' ')
                throw std::invalid_argument("bad input => " + line);
            
            // std::cout << "valueStr: |" << valueStr << "|" << std::endl;
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
    double exchangeRate = getExchangeRate(dateStr);
    printResult(dateStr, value, exchangeRate);
}


void BitcoinExchange::printResult(const std::string &date, double value, double exchangeRate) const
{
    std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
}
