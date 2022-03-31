#include "Money.h"
#include "Account.h"

int main(){
	Account account(300, 23);
	std::cout << account << "\n";

	Money deposit1(200,00);
	Money deposit2(300,24);
	Money deposit3(501,22);
	account.makeDeposit(deposit1);
	account.makeDeposit(deposit2);
	account.makeDeposit(deposit3);
	std::cout << account << "\n";

	Money withdrawal1(300,10);
	Money withdrawal2(201,34);
	account.makeWithdrawal(withdrawal1);
	account.makeWithdrawal(withdrawal2);
	std::cout << account << "\n";


//operator tests
	std::cout << "\n\n\nOperator tests\n\n";

	Money m(12,70);
	Money n(1750,49);
	Money mnp = m + n;
	Money mnm = m - n;
	std::cout << m << " plus " << n << " is " << mnp << "\n";
	std::cout << m << " minus " << n << " is " << mnm << "\n\n";

	if (m > n){ std::cout << m << " > " << n << "\n"; } else { std::cout << n << " > " << m << "\n"; }
	if (m < n){ std::cout << m << " < " << n << "\n"; } else { std::cout << n << " < " << m << "\n"; }

	if (m != n){ std::cout << m << " != " << n << "\n\n"; } else { std::cout << m << " == " << n << "\n\n"; }

	Money o(1,11);
	Money p(0,111);	//$1.11 = 111c
	if (o == p){ std::cout << o << " == " << p << "\n\n"; } else { std::cout << o << " != " << p << "\n\n"; }

	Money q(234,43);
	Money r(652,34);
	if (q >= r){ std::cout << q << " >= " << r << "\n"; } else { std::cout << q << " <= " << r << "\n"; }
	if (r <= q){ std::cout << r << " <= " << q << "\n\n"; } else { std::cout << r << " >= " << q << "\n\n"; }

	return 0;
}
