#pragma once
#include "Developer.h"
class DeveloperLead : public Developer
{
private:
	int num_of_people;

public:
	DeveloperLead();
	void operator =(DeveloperLead& other);
	void set_Employee() override;
	void get_Employee() override;

	void redact() override;
	static std::shared_ptr<Employee> create()
	{
		std::shared_ptr<DeveloperLead> worker(new DeveloperLead);
		return worker;
	}
	~DeveloperLead()
	{
	}
};

