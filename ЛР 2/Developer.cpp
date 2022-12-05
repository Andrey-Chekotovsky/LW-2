#include "Developer.h"

const std::vector<std::string> REDACT_MENU = { "��������� � ����", "���", "������", "���������� �����", "���� ��������", "���� ���������������", "������" };

Developer::Developer()
{
	position = 1;
}
void Developer::operator =(Developer& other)
{
	this->date_of_birth = other.date_of_birth;
	this->date_of_employment = other.date_of_employment;
	this->fio = other.fio;
	this->salary = other.salary;
	this->gender = other.gender;
	this->level = other.level;
}
void Developer::set_Employee() 
{
	Employee::set_Employee();
	std::cout << "������� �������" << std::endl;
	this->level = SetLevel();
	std::cout << "������� ������ �� ������� �������� ���������" << std::endl;
	std::cin.ignore();
	getline(std::cin, this->project);
	std::cin.clear();
}
void Developer::get_Employee() 
{
	Employee::get_Employee();
	std::cout << "�������:" << DefineLevel(this->level) << std::endl;
	std::cout << "������:" << this->project << std::endl;
}
void Developer::redact()
{
	Keys keys;
	int switcher = 0;
	while (true)
	{
		keys.all_false();
		system("cls");
		this->get_Employee();
		std::cout << "�������� ��, ��� �� ������ ��������:" << std::endl;
		show_meny(REDACT_MENU, switcher);
		process_keys(keys, switcher, REDACT_MENU);
		if (keys.get_bot() || keys.get_top())
			continue;
		system("cls");
		switch (switcher)
		{
		case 0:
			return;
		case 1:
			this->fio.SetFIO();
			break;
		case 2:
			this->gender = SetGender();
			break;
		case 3:
			std::cout << "������� ���������� �����" << std::endl;
			std::cin >> this->salary;
			break;
		case 4:
			this->date_of_birth.set_Date();
			break;
		case 5:
			this->date_of_employment.set_Date();
			break;
		case 6:
			std::cout << "������� �������� �������" << std::endl;
			std::cin.ignore();
			getline(std::cin, this->project);
			std::cin.clear();
			break;
		default:
			std::cout << "����� ��������� ���� ������� �� ����������, ���������� ����������� �����\n\n";
			switcher = -1;
			break;
		}
		wait();
	}
}