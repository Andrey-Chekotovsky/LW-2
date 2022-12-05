#pragma once
#include<string>
#include"Keys.h"
#include"FullName.h"
#include"Date.h"
#include"functions.h"

enum Gender;
Gender SetGender();
std::string DefineGender(Gender gender);

enum Level;
Level SetLevel();
std::string DefineLevel(Level level);


class Employee
{
protected:
	int position;
	Gender gender;
	int salary;
	Date date_of_birth, date_of_employment;
	FullName fio;
public:
	Employee();
	std::string get_position();
	virtual void set_Employee();
	virtual void get_Employee();

	int get_salary();
	FullName get_full_name();

	virtual void redact() = 0;
	~Employee()
	{
	}
};
