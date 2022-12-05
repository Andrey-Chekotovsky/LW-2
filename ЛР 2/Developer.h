#pragma once
#include "Employee.h"
class Developer : public Employee
{
protected:
	Level level;
	std::string project;
public:
	Developer();
	void operator =(Developer& other);
	void set_Employee() override;
	void get_Employee() override;
	void redact() override;
	static std::shared_ptr<Employee> create()
	{
		std::shared_ptr<Developer> worker(new Developer);
		return worker;
	}
	~Developer()
	{
	}
};

