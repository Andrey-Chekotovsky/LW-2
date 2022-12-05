#include "Employee.h"

const std::vector<std::string> CHOOSE_GENDER_MENU = { "Мужчина", "Женщина", "Другое" };
const std::vector<std::string> CHOOSE_LEVEL_MENU = { "Джун", "Мидл", "Сеньор" };

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
		std::cout << "Выберете гендер:\n";
		show_meny(CHOOSE_GENDER_MENU, switcher);
		process_keys(keys, switcher, CHOOSE_GENDER_MENU);
		if (keys.get_bot() || keys.get_top())
			continue;
		switch (switcher)
		{
		case 0: return MALE;
		case 1: return FEMALE;
		case 2: return OTHER;
		default: std::cout << "Введенного вами варианта не существует, попробуйте снова\n";
		}
	}
}
std::string DefineGender(Gender gender)
{
	switch (gender)
	{
	case MALE: return "Мужчина";
	case FEMALE: return "Женщина";
	case OTHER: return "Что-то";
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
		std::cout << "Выберете уровень:\n";
		show_meny(CHOOSE_LEVEL_MENU, switcher);
		process_keys(keys, switcher, CHOOSE_LEVEL_MENU);
		if (keys.get_bot() || keys.get_top())
			continue;
		switch (switcher)
		{
		case 0: return JUN;
		case 1: return MIDL;
		case 2: return SENJOR;
		default: std::cout << "Введенного вами варианта не существует, попробуйте снова\n";
		}
	}
}
std::string DefineLevel(Level level)
{
	switch (level)
	{
	case JUN: return "Джун";
	case MIDL: return "Мидл";
	case SENJOR: return "Сеньор";
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
		return "Дэвэлопер";
	case 1:
		return "Лид";
	case 2:
		return "Тестировщик";
	}
}
void Employee::set_Employee()
{
	this->fio.SetFIO();
	this->gender = SetGender();
	std::cout << "Осуществиете ввод даты рождения: " << std::endl;
	while (this->date_of_birth.set_Date() != 0) { std::cout << "Ошибка ввода даты, повторите попытку"; }
	std::cout << "Осуществиете ввод даты приема на работу: " << std::endl;
	while (this->date_of_employment.set_Date() != 0) { std::cout << "Ошибка ввода даты, повторите попытку"; }
	std::cout << "Введите заработную плату:";
	std::cin >> this->salary;
}
void Employee::get_Employee()
{
	std::cout << fio.get_string() << std::endl;
	std::cout << "Пол: ";
	switch (gender)
	{
	case MALE: std::cout << "Мужчина\n"; break;
	case FEMALE: std::cout << "Женщина\n"; break;
	case OTHER: std::cout << "Что-то\n"; break;
	}
	std::cout << "Дата рождения: ";
	std::cout << date_of_birth.get_Date() << std::endl;
	std::cout << "Дата найма: ";
	std::cout << date_of_employment.get_Date() << std::endl;
	std::cout << "Заработная плата: ";
	std::cout << this->salary << std::endl;
	std::cout << "Должность: " << get_position() << std::endl;
}

int Employee::get_salary() { return this->salary; }
FullName Employee::get_full_name() { return this->fio; }
