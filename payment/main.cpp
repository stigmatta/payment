#include <iostream>
#include "Payment.h"
using namespace std;
void operator+(Payment a, int b)
{
	a.set_salary(a.get_salary() + b);
}
void operator+(Payment a, float b)
{
	a.set_surcharge_percent(a.get_surcharge_percent() + b);
}
void operator-(Payment a, int b)
{
	a.set_salary(a.get_salary() - b);
}
void operator-(Payment a, float b)
{
	a.set_surcharge_percent(a.get_surcharge_percent() - b);
}
ostream& operator << (ostream& os, Payment& b)
{
	os << "Name: " << b.get_name() << endl;
	os << "Initial year of working: " << b.get_begin_workyear() << endl;
	os << "Work days in month: " << b.get_all_workdays() << endl;
	os << b.get_name() << " days worked: " << b.get_user_workdays() << endl;
	os << "Salary: " << b.get_salary() << endl;
	os << "Income payment: " << b.get_income_payment() << endl;
	os << "Withheld payment: " << b.get_withheld_payment() << endl;
	os << "All payment he will get: " << b.get_all_payment() << endl;
	os << "Surcharge percentage: " << b.get_surcharge_percent() << endl << endl;
	return os;
}
int main()
{
	Payment john("John Jones", 2018, 15, 20, 400, 4.5);
	cout << john;
	Payment johnny(john);
	cout << johnny;
}