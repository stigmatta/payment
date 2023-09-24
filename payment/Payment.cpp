#include "Payment.h"
#include <string>
#include <ctime>
using namespace std;
Payment::Payment()
{
	user_workdays = all_workdays = begin_workyear = 0;
	salary = surcharge_percent = income_payment = withheld_payment = income_tax = 0;
}
Payment::Payment(const char* initials) :Payment()
{
	strcpy_s(this->initials, strlen(initials)+1, initials);
}
Payment::Payment(const char* initials, unsigned int begin_workyear, unsigned int user_workdays, unsigned int all_workdays, float salary, float surcharge_percent)
{
	this->initials = new char[strlen(initials) + 1];
	strcpy_s(this->initials, strlen(initials) + 1, initials);
	this->begin_workyear = begin_workyear;
	this->user_workdays = user_workdays;
	this->all_workdays = all_workdays;
	this->salary = salary;
	this->surcharge_percent = surcharge_percent;
	income_payment = get_income_payment();
	withheld_payment = get_withheld_payment();
}
Payment::Payment(const Payment& b)
{
	this->initials = new char[strlen(b.initials) + 1];
	strcpy_s(this->initials, strlen(b.initials) + 1, b.initials);

	this->user_workdays = b.user_workdays;
	this->all_workdays = b.all_workdays;
	this->begin_workyear = b.begin_workyear;
	this->salary = b.salary;
	this->surcharge_percent = b.surcharge_percent;
}
Payment& Payment::operator=(const Payment& b)
{
	if (this == &b)
		return *this;
	delete[] this->initials;
	this->initials = new char[strlen(b.initials) + 1];
	strcpy_s(this->initials, strlen(b.initials) + 1, b.initials);
	this->user_workdays = b.user_workdays;
	this->all_workdays = b.all_workdays;
	this->begin_workyear = b.begin_workyear;
	this->salary = b.salary;
	this->surcharge_percent = b.surcharge_percent;
	return *this;
}

Payment::~Payment()
{
	if (initials!=nullptr)
		delete[]initials;
}
unsigned int Payment:: get_all_workyears()const
{
	int this_year = 2023;
	return this_year- begin_workyear;
}
float Payment:: get_income_payment()const
{
	return (salary * user_workdays) + surcharge_percent;
}
float Payment::get_withheld_payment()
{
	income_tax = get_income_payment() / 100 * 13;
	return (get_income_payment() / 100) + income_tax;
}
float Payment::get_all_payment()
{
	return get_income_payment() - get_withheld_payment();
}
unsigned int Payment::get_user_workdays()const
{
	return user_workdays;
}
unsigned int Payment:: get_all_workdays()const
{
	return all_workdays;
}
unsigned int Payment:: get_begin_workyear()const
{
	return begin_workyear;
}
float Payment:: get_salary()const
{
	return salary;
}
float Payment::get_surcharge_percent()const
{
	return surcharge_percent;
}
char* Payment::get_name()const
{
	return initials;
}
void Payment:: set_user_workdays(unsigned int user_workdays)
{
	this->user_workdays = user_workdays;
}
void Payment::set_all_workdays(unsigned int all_workdays)
{
	this->all_workdays = all_workdays;
}
void Payment::set_begin_workyear(unsigned int begin_workyear)
{
	this->begin_workyear = begin_workyear;
}
void Payment::set_salary(float salary)
{
	this->salary = salary;
}
void Payment::set_surcharge_percent(float surcharge_percent)
{
	this->surcharge_percent = surcharge_percent;
}
void Payment::set_name(const char* initials)
{
	delete[]this->initials;
	this->initials = new char[strlen(initials) + 1];
	strcpy_s(this->initials, strlen(initials) + 1, initials);
}