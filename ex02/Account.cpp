/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:43:25 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/09 15:16:57 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Definition of the static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Parameterized constructor
Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

// Definition of destructor
Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

// Definition of Displaytimestamp()
void Account::_displayTimestamp(void)
{
    std::time_t currentTimeT;
    std::tm* localTime;

    // Get the current time in time_t format
    std::time(&currentTimeT);

    // Convert time_t to local time
    localTime = std::localtime(&currentTimeT);

    // Format the timestamp
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
    std::cout << buffer;
}

// Definition of getNbAccounts()
int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

// Definition of getTotalAmount()
int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

// Definition of getNbDeposits()
int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

// Definition of getNbWithdrawals()
int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

// Definition of displayAccountsInfos()
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";desposits:" \
    << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

// Definition of displayStatus()
void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";desposits:"\
    << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Definition of makeDeposit()
void Account::makeDeposit(int deposit)
{
    int p_amount = _amount;

    _amount += deposit;
    _nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:"\
    << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Definition of checkAmount()
int		Account::checkAmount( void ) const
{
    return (_amount);
}

// Definition of makeWithdrawal()
bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if (withdrawal > _amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}
