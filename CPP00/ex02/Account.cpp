/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:31:37 by rel-isma          #+#    #+#             */
/*   Updated: 2023/09/23 12:11:17 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// constructor
Account::Account(int initial_deposit) :     _accountIndex(_nbAccounts),
                                            _amount(initial_deposit),
                                            _nbDeposits(0),
                                            _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor
Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    _nbAccounts--;
    _totalAmount -= _amount;
}
int Account::getNbAccounts() {
    return _nbAccounts;
}
int Account::getTotalAmount() {
    return _totalAmount;
}
int Account::getNbDeposits() {
    return _totalNbDeposits;
}
int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}


void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    if (deposit > 0)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;

        _amount += deposit;
        _nbDeposits++;
        _totalAmount += deposit;
        _totalNbDeposits++;
        std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
    }
}


bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > 0 && _amount >= withdrawal)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    } 
    else 
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
}
int Account::checkAmount() const {
    return _amount;
}
void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::_displayTimestamp()
{
    std::time_t currentTime = std::time(nullptr);
    char timestamp[20];
    std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", std::localtime(&currentTime));
    std::cout << timestamp << " ";
}
