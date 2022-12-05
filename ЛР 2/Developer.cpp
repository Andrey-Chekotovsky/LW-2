#include "Developer.h"

const std::vector<std::string> REDACT_MENU = { "Вернуться в меню", "ФИО", "Гендер", "Зароботная плата", "Дата рождения", "Дата трудоустройства", "Проэкт" };

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
	std::cout << "Ввудите уровень" << std::endl;
	this->level = SetLevel();
	std::cout << "Введите проэкт на котором работает сотрудник" << std::endl;
	std::cin.ignore();
	getline(std::cin, this->project);
	std::cin.clear();
}
void Developer::get_Employee() 
{
	Employee::get_Employee();
	std::cout << "Уровень:" << DefineLevel(this->level) << std::endl;
	std::cout << "Проэкт:" << this->project << std::endl;
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
		std::cout << "Выберите то, что вы хотите изменить:" << std::endl;
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
			std::cout << "Введите заработную плату" << std::endl;
			std::cin >> this->salary;
			break;
		case 4:
			this->date_of_birth.set_Date();
			break;
		case 5:
			this->date_of_employment.set_Date();
			break;
		case 6:
			std::cout << "Введите название проэкта" << std::endl;
			std::cin.ignore();
			getline(std::cin, this->project);
			std::cin.clear();
			break;
		default:
			std::cout << "Номер введенной вами команды не существует, проверьете коректность ввода\n\n";
			switcher = -1;
			break;
		}
		wait();
	}
}