#pragma once
#include "Developer.h"
class QA : public Developer
{
private:
public:
	QA();
	void operator =(QA& other);
	void set_Employee() override;
	void get_Employee() override;
	void redact() override;
	static std::shared_ptr<Employee> create()
	{
		std::shared_ptr<QA> worker(new QA);
		return worker;
	}
	~QA()
	{
	}
};

