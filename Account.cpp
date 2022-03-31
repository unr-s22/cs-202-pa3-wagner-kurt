#include "Account.h"

Account::Account(int dollars, int cents) : Money(dollars, cents) {}

void Account::makeDeposit(Money m){
	deposits.push_back(m);

	needUpdateBalance = true;
}

void Account::makeWithdrawal(Money m){
	withdrawals.push_back(m);

	needUpdateBalance = true;
}

Money Account::getBalance() const {
	int dollars = getDollars();
	int cents = getCents();
	Money initialBalance = combineMoney(dollars, cents);

	for (int i = 0; i < deposits.size(); i++){
		initialBalance = initialBalance + deposits[i];
	}

	for (int i = 0; i < withdrawals.size(); i++){
		initialBalance = initialBalance - withdrawals[i];
	}

	needUpdateBalance = false;
	return initialBalance;
}
