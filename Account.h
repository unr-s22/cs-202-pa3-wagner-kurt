#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Money.h"
#include <iostream>
#include <vector>

class Account : public Money {
private:
	Money money;
	mutable bool needUpdateBalance = true;
	std::vector<Money> deposits;
	std::vector<Money> withdrawals;
public:
	void makeDeposit(Money m);
	void makeWithdrawal(Money m);

	Money getBalance() const ;

	friend std::ostream &operator << (std::ostream &out, const Account &a){
		out <<
		"Account Details\n" <<
		"-------------------------\n" <<
		"Current Balance: " << a.getBalance() << "\n" <<
		"-------------------------\n" <<
		"Number of Deposits: " << a.deposits.size() << "\n" <<
		"-------------------------\n";
		for (int i = 0; i < a.deposits.size(); i++){
			out << "(" << i+1 << ") " << a.deposits[i] << "\n";
		}
		out <<
		"-------------------------\n" <<
		"Number of Withdrawals: " << a.withdrawals.size() << "\n" <<
		"-------------------------\n";
		for (int i = 0; i < a.withdrawals.size(); i++){
			out << "(" << i+1 << ") " << a.withdrawals[i] << "\n";
		}
		return out;
	}

	Account(int dollars, int cents);
};

#endif //ACCOUNT_H
