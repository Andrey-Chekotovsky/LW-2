#include "QA.h"

const std::vector<std::string> REDACT_MENU = { "��������� � ����", "���", "������", "���������� �����", "���� ��������", "���� ���������������", "������" };

QA::QA()
{
	position = 3;
}
void QA::operator =(QA& other)
{
	this->date_of_birth = other.date_of_birth;
	this->date_of_employment = other.date_of_employment;
	this->fio = other.fio;
	this->salary = other.salary;
	this->gender = other.gender;
	this->level = other.level;
	this->project = other.project;
}
void QA::set_Employee() 
{
	Developer::set_Employee();

}
void QA::get_Employee() 
{
	Employee::get_Employee();
}
void QA::redact()
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
			getline(std::cin, this->project);
			break;
		default:
			std::cout << "����� ��������� ���� ������� �� ����������, ���������� ����������� �����\n\n";
			switcher = -1;
			break;
		}
		wait();
	}
}