#include "DeveloperLead.h"


const std::vector<std::string> REDACT_MENU = { "��������� � ����", "���", "������", "���������� �����", "���� ��������", "���� ���������������",
	"���������� �����������", "������" };

DeveloperLead::DeveloperLead()
{
	position = 2;
}
void DeveloperLead::operator =(DeveloperLead& other)
{
	this->date_of_birth = other.date_of_birth;
	this->date_of_employment = other.date_of_employment;
	this->fio = other.fio;
	this->salary = other.salary;
	this->gender = other.gender;
	this->level = other.level;
	this->project = other.project;
	this->num_of_people = other.num_of_people;
}
void DeveloperLead::set_Employee() 
{
	Developer::set_Employee();
	std::cout << "������� ���������� �����������" << std::endl;
	std::cin >> this->num_of_people;
}
void DeveloperLead::get_Employee() 
{
	Developer::get_Employee();
	std::cout << "���������� �����������: " << this->num_of_people << std::endl;
	std::cout << "" << std::endl;
}

void DeveloperLead::redact()
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
			std::cout << "������� ���������� ������������" << std::endl;
			std::cin >> this->num_of_people;
			break;
		case 7:
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