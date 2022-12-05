#pragma once
#include <string>
#include <iostream>

class FullName
{
private:
	char name[30], surname[30];
public:
	FullName();
	FullName(char name[30], char surname[30]);
	FullName(const FullName& other);
	void set_surname(char* surname);
	char* get_surname();
	void set_name(char* name);
	char* get_name();
	std::string get_string();
	void SetFIO();
	bool operator <(FullName& other);
	bool operator >(FullName& other);
	void operator =(const FullName& other);
	bool operator ==(FullName& other);
};

