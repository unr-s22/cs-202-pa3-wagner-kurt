#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money {
private:
	int dollars;
	int cents;
public:
	int getDollars() const;
	int getCents() const;

	int convertToCents() const;

	Money combineMoney(Money m){
		Money money;
		int totalCents = m.convertToCents();
		money.dollars = totalCents / 100;
		money.cents = totalCents % 100;
		return money;
	}

	Money combineMoney(int d, int c) const {
		Money money;
		int totalCents = (d * 100) + c;
		money.dollars = totalCents / 100;
		money.cents = totalCents % 100;
		return money;
	}

	bool operator < (Money m){
		if (convertToCents() < m.convertToCents()){
			return true;
		} else { return false; }
	}

	bool operator > (Money m){
		if (convertToCents() > m.convertToCents()){
			return true;
		} else { return false; }
	}

	bool operator <= (Money m){
		if ((convertToCents() < m.convertToCents()) || (m.convertToCents() == convertToCents())){
			return true;
		} else { return false; }
	}

	bool operator >= (Money m){
		if ((convertToCents() > m.convertToCents()) || (m.convertToCents() == convertToCents())){
			return true;
		} else { return false; }
	}

	bool operator != (Money m){
		if (convertToCents() != m.convertToCents()){
			return true;
		} else { return false; }
	}

	bool operator == (Money m){
		if (convertToCents() == m.convertToCents()){
			return true;
		} else { return false; }
	}

	Money operator + (const Money &m){
		Money money;
		money.dollars = this->dollars + m.dollars;
		money.cents = this->cents + m.cents;
		return combineMoney(money);
	}

	Money operator - (const Money &m){
		Money money;
		money.dollars = this->dollars - m.dollars;
		money.cents = this->cents - m.cents;
		return combineMoney(money);
	}

	friend std::ostream &operator << (std::ostream &out, const Money &m){
		out << "$" << m.getDollars() << "." << m.getCents();
		return out;
	}

	Money(){}
	Money(int dollars, int cents);
};

#endif //MONEY_H
