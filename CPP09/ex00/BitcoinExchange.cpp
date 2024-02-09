/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:13:05 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/09 16:34:50 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : inputFile("") {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange)
{
    *this = bitcoinExchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange)
{
    if (this == &bitcoinExchange)
        return *this;
    this->exchangeRates = bitcoinExchange.exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    inputFile.close();
}
void BitcoinExchange::processFirstLine(std::string &line)
{
    line.erase(0, line.find_first_not_of(" "));
    line.erase(line.find_last_not_of(" ") + 1);
    if (line != "date | value")
    {
        throw std::invalid_argument("bad input: no title ");
    }
}

BitcoinExchange::BitcoinExchange(const std::string &inputFilename)
{
    std::string line;

    readExchangeRates("data.csv");
    inputFile.open(inputFilename.c_str());
    if (!inputFile.is_open())
    {
        throw std::runtime_error("could not open file.");
    }
    std::getline(inputFile, line);
    processFirstLine(line);

}

void BitcoinExchange::readExchangeRates(const std::string &exchangeRatesFilename)
{

    std::ifstream file(exchangeRatesFilename);
    if (!file.is_open())
    {
        throw std::runtime_error("could not open exchange rates file.");
    }

    std::string line;
    if (std::getline(file, line))
    {
        if (line != "date,exchange_rate")
        {
            throw std::invalid_argument("bad input: no title");
        }
    }
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        exit(0);
        std::stringstream iss(line);
        std::string date;
        double rate = 0.0;

        if (getline(iss, date, ','))
        {
            iss >> rate;
            exchangeRates[date] = rate;
        }
    }
    file.close();
}

void BitcoinExchange::processInput()
{
    
    std::string line;
    std::getline(inputFile, line);
    if (line.empty())
        return;
    if (line == "date | value")
        throw std::invalid_argument("bad input : double => " + line);
    else
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

void ft_check_year(std::string year, std::string date)
{
    char *str;
    long yearlong;
    yearlong = std::strtol(year.c_str(), &str, 10);
    if (*str != '\0')
        throw std::invalid_argument("bad input => " + date);
    if (year.size() != 4)
        throw std::invalid_argument("bad input => " + date);
    if (yearlong < 2009)
        throw std::invalid_argument("bad input => " + date);
}
void ft_check_month(std::string month)
{
    char *str;
    long monthlong;
    monthlong = std::strtol(month.c_str(), &str, 10);
    if (*str != '\0')
        throw std::invalid_argument("bad input in month => " + month);
    if (month.size() != 2)
        throw std::invalid_argument("bad input in month => " + month);
    if (monthlong < 1 || monthlong > 12)
        throw std::invalid_argument("bad input in month => " + month);
}

void ft_check_day(std::string day , std::string month, std::string date, std::string year)
{
    int leapYear = 0;
    char *str;
    long daylong;
    daylong = std::strtol(day.c_str(), &str, 10);
    if (*str != '\0')
        throw std::invalid_argument("bad input => " + date);
    char *str2;
    long monthlong;
    monthlong = std::strtol(month.c_str(), &str2, 10);
    if (*str2 != '\0')
        throw std::invalid_argument("bad input => " + date);
    if (day.size() != 2)
        throw std::invalid_argument("bad input => " + day);
    if (daylong < 1 || daylong > 31)
        throw std::invalid_argument("bad input => " + date);
    leapYear = std::strtol(year.c_str(), NULL, 10);
    if ((leapYear % 4 == 0 && leapYear % 100 != 0) || leapYear % 400 == 0)
        leapYear = 1;
    else
        leapYear = 0;
    if (monthlong == 2)
    {
        if (leapYear == 1)
        {
            if (daylong > 29)
                throw std::invalid_argument("bad input => " + date);
        }
        else
        {
            if (daylong > 28)
                throw std::invalid_argument("bad input => " + date);
        }
    }
    if (monthlong == 1 || monthlong == 3 || monthlong == 5 || monthlong == 7 || monthlong == 8 || monthlong == 10 || monthlong == 12)
    {
        if (daylong > 31)
            throw std::invalid_argument("bad input => " + date);
    }
    if (monthlong == 4 || monthlong == 6 || monthlong == 9 || monthlong == 11)
    {
        if (daylong > 30)
            throw std::invalid_argument("bad input => " + date);
    }
}

void ft_check_date(std::string date)
{
    std::string year;
    std::string month;
    std::string day;
    std::stringstream iss(date);
    
    if (date.size() != 10)
        throw std::invalid_argument("bad input => " + date);
    std::getline(iss, year, '-');
    std::getline(iss, month, '-');
    std::getline(iss, day, '-');
    ft_check_year(year, date);
    ft_check_month(month);
    ft_check_day(day, month, date, year);
}

double BitcoinExchange::getExchangeRate(const std::string &dateStr) const
{
    std::map<std::string, double>::const_iterator it = exchangeRates.find(dateStr);
    if (it != exchangeRates.end()) 
    {
        return it->second;
    }
    std::map<std::string, double>::const_iterator lowerBound = exchangeRates.lower_bound(dateStr);
    if (lowerBound != exchangeRates.begin())
    {
        --lowerBound;
        return lowerBound->second;
    }
    throw std::out_of_range("Exchange rate not available for the specified date: " + dateStr);
}

int BitcoinExchange::checkWhiteSpace(std::string str)
{
    int count = 0;
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ')
            count++;
    }
    return count;
}

void BitcoinExchange::processLine(const std::string &line)
{
    std::stringstream iss(line);
    std::string dateStr;
    std::string valueStr;
    double value;

    if (line.empty())
        throw std::invalid_argument("bad input => " + line);
    if (line.find('|') == std::string::npos)
        throw std::invalid_argument("bad input => " + line);
    
    if (std::getline(iss, dateStr, '|'))
    {
        if (checkWhiteSpace(dateStr) != 1 || dateStr.size() != 11)
            throw std::invalid_argument("bad input => " + line);
        if (dateStr.back() != ' ')
            throw std::invalid_argument("bad input => " + line);
        
        dateStr.erase(dateStr.find_last_not_of(" ") + 1);
        ft_check_date(dateStr);
        if (std::getline(iss, valueStr))
        {
            if (checkWhiteSpace(valueStr) != 1)
                throw std::invalid_argument("bad input =>> " + line);
            if (valueStr.front() != ' ')
                throw std::invalid_argument("bad input => " + line);
            char *str;
            value = std::strtod(valueStr.c_str(), &str);
            if (*str != '\0') {
                throw std::invalid_argument("bad input => " + line);
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
