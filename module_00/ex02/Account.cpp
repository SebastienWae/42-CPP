#include "Account.hpp"

#include <iostream>
#include <iterator>

#define TIME_BUFF_SIZE 19

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposit:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
            << std::endl;
}

Account::Account(int initial_deposit) {
  _amount = initial_deposit;
  _totalAmount += initial_deposit;
  _accountIndex = _nbAccounts;
  _nbWithdrawals = 0;
  _nbDeposits = 0;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
  _nbAccounts++;
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit
            << ";deposits:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits
            << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  if (_amount < withdrawal) {
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused"
              << std::endl;
    return false;
  }
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal
            << ";withdrawal:" << withdrawal << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
            << ";withdrawls:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  const time_t now = time(NULL);
  const struct tm *time_info = localtime(&now);
  char buffer[TIME_BUFF_SIZE];

  strftime(buffer, TIME_BUFF_SIZE, "[%Y%m%d_%H%M%S] ", time_info);
  std::cout << buffer;
}
