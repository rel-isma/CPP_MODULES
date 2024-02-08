/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:12:26 by rel-isma          #+#    #+#             */
/*   Updated: 2024/02/08 17:44:22 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> exchangeRates;
        std::ifstream inputFile;
        int checkWhiteSpace(std::string str);
        void processFirstLine(std::string &line);
        void readExchangeRates(const std::string &exchangeRatesFilename);
        double getExchangeRate(const std::string &date) const;
        void processLine(const std::string &line);
        void printResult(const std::string &date, double value, double exchangeRate) const;

    public:
        BitcoinExchange(const std::string &inputFilename);

        void processInput();

};

#endif
