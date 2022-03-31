#include "Money.h"

Money::Money(int dollars, int cents) : dollars(dollars), cents(cents){}

int Money::getDollars() const { return dollars; }
int Money::getCents() const { return cents; }

int Money::convertToCents() const { return (dollars * 100) + cents; }
