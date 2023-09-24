#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class Payment
{
private:
	char* initials;
	unsigned int user_workdays=0, all_workdays=0,begin_workyear=0;
	float salary=0, surcharge_percent=0, income_payment=0, withheld_payment=0, income_tax=0;
	
public:
	Payment();
	Payment(const char* initials);
	Payment(const char* initials, unsigned int begin_workyear, unsigned int user_workdays, unsigned int all_workdays, float salary, float surcharge_percent);
	~Payment();
	Payment(const Payment& b);
	Payment& operator = (const Payment& b);
	unsigned int get_all_workyears()const;
	float get_income_payment()const;
	float get_withheld_payment();
	float get_all_payment();
	unsigned int get_user_workdays()const;
	unsigned int get_all_workdays()const;
	unsigned int get_begin_workyear()const;
	char* get_name()const;
	float get_salary()const;
	float get_surcharge_percent()const;
	void set_user_workdays(unsigned int user_workdays);
	void set_all_workdays(unsigned int all_workdays);
	void set_begin_workyear(unsigned int begin_workyear);
	void set_salary (float salary);
	void set_surcharge_percent (float surcharge_percent);
	void set_name(const char* initials);
};

