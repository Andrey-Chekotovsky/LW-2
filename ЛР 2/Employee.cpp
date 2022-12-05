#include "Employee.h"

const std::vector<std::string> CHOOSE_GENDER_MENU = { "�������", "�������", "������" };
const std::vector<std::string> CHOOSE_LEVEL_MENU = { "����", "����", "������" };

enum Gender {
	MALE,
	FEMALE,
	OTHER
};
Gender SetGender()
{
	Keys keys;
	int switcher = 0;
	while (true)
	{
		keys.all_false();
		system("cls");
		std::cout << "�������� ������:\n";
		show_meny(CHOOSE_GENDER_MENU, switcher);
		process_keys(keys, switcher, CHOOSE_GENDER_MENU);
		if (keys.get_bot() || keys.get_top())
			continue;
		switch (switcher)
		{
		case 0: return MALE;
		case 1: return FEMALE;
		case 2: return OTHER;
		default: std::cout << "���������� ���� �������� �� ����������, ���������� �����\n";
		}
	}
}
std::string DefineGender(Gender gender)
{
	switch (gender)
	{
	case MALE: return "�������";
	case FEMALE: return "�������";
	case OTHER: return "���-��";
	}
}

enum Level {
	JUN,
	MIDL,
	SENJOR
};
Level SetLevel()
{
	Keys keys;
	int switcher = 0;
	while (true)
	{
		keys.all_false();
		system("cls");
		std::cout << "�������� �������:\n";
		show_meny(CHOOSE_LEVEL_MENU, switcher);
		process_keys(keys, switcher, CHOOSE_LEVEL_MENU);
		if (keys.get_bot() || keys.get_top())
			continue;
		switch (switcher)
		{
		case 0: return JUN;
		case 1: return MIDL;
		case 2: return SENJOR;
		default: std::cout << "���������� ���� �������� �� ����������, ���������� �����\n";
		}
	}
}
std::string DefineLevel(Level level)
{
	switch (level)
	{
	case JUN: return "����";
	case MIDL: return "����";
	case SENJOR: return "������";
	}
}

Employee::Employee()
{
	this->position = 0;
}
std::string Employee::get_position()
{
	switch (this->position)
	{
	case 0:
		return "���������";
	case 1:
		return "���";
	case 2:
		return "�����������";
	}
}
void Employee::set_Employee()
{
	this->fio.SetFIO();
	this->gender = SetGender();
	std::cout << "������������ ���� ���� ��������: " << std::endl;
	while (this->date_of_birth.set_Date() != 0) { std::cout << "������ ����� ����, ��������� �������"; }
	std::cout << "������������ ���� ���� ������ �� ������: " << std::endl;
	while (this->date_of_employment.set_Date() != 0) { std::cout << "������ ����� ����, ��������� �������"; }
	std::cout << "������� ���������� �����:";
	std::cin >> this->salary;
}
void Employee::get_Employee()
{
	std::cout << fio.get_string() << std::endl;
	std::cout << "���: ";
	switch (gender)
	{
	case MALE: std::cout << "�������\n"; break;
	case FEMALE: std::cout << "�������\n"; break;
	case OTHER: std::cout << "���-��\n"; break;
	}
	std::cout << "���� ��������: ";
	std::cout << date_of_birth.get_Date() << std::endl;
	std::cout << "���� �����: ";
	std::cout << date_of_employment.get_Date() << std::endl;
	std::cout << "���������� �����: ";
	std::cout << this->salary << std::endl;
	std::cout << "���������: " << get_position() << std::endl;
}

int Employee::get_salary() { return this->salary; }
FullName Employee::get_full_name() { return this->fio; }
