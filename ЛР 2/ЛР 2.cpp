#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <memory>
#include <fstream>
#include <vector>
#include"FullName.h"
#include"Date.h"
#include"Employee.h"
#include"Developer.h"
#include"DeveloperLead.h"
#include"QA.h"


const std::vector<std::string> MENU = { "Выход", "Добавить сотрудника", "Вывести информацию о сотруднике", "Отрдактировать данные сотрудника", "Вывести всех сотрудников" };

const std::vector<std::string> ADD_MENU = { "Добавить девелопера", "Добавить лида", "Добавить тестировщика" };

template <typename T>
std::shared_ptr<Employee> factory()
{
	std::shared_ptr<T> worker(new T);
	return worker;
}

std::shared_ptr<Employee> Employee_create_menu()
{
	std::shared_ptr<Employee> employee;
	Keys keys;
	int switcher = 0;
	while (true)
	{
		keys.all_false();
		system("cls");
		show_meny(ADD_MENU, switcher); 
		process_keys(keys, switcher, ADD_MENU);
		if (keys.get_bot() || keys.get_top())
			continue;
		switch (switcher)
		{
		case 0:
			system("cls");
			employee = Developer::create();
			employee->set_Employee();
			return employee;
		case 1:
			system("cls");
			employee = DeveloperLead::create();
			employee->set_Employee();
			return employee;
		case 2:
			system("cls");
			employee =QA::create();
			employee->set_Employee();
			return employee;
		}
	}
}

void show_employees(std::vector<std::shared_ptr<Employee>> mas)
{
	for (int i = 0; i < mas.size(); i++)
	{
		std::cout << i + 1 << mas[i]->get_full_name().get_string() << std::endl;
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FullName fio;
	bool find = false;
	Keys keys;
	std::vector<std::shared_ptr<Employee>> mas;
	int switcher = 0;
	while (true)
	{
		keys.all_false();
		system("cls");
		show_meny(MENU, switcher);
		process_keys(keys, switcher, MENU);
		if (keys.get_bot() || keys.get_top())
			continue;
		switch (switcher)
		{
		case 0:
			return 0;
		case 1:
			system("cls");
			std::cout << "Введите количество сощдаваемых людей";
			switcher = input_int();
			for (int i = 0; i < switcher; i++)
			{
				mas.push_back(Employee_create_menu());
			}
			break;
		case 2:
			system("cls");
			show_employees(mas);
			std::cout << "Введмите фамилию, имя и отчество нужного сотрудника";
			fio.SetFIO();
			for (int i = 0; i < mas.size(); i++)
			{
				if (mas[i]->get_full_name() == fio)
				{
					mas[i]->get_Employee();
					find = true;
				}
			}
			if (!find)
				std::cout << "Рабочий не найден, проверьете введенные данные" << std::endl;
			find = false;
			break;

		case 3:
			system("cls");
			show_employees(mas);
			std::cout << "Введмите фамилию, имя и отчество нужного сотрудника";
			fio.SetFIO();
			for (int i = 0; i < mas.size(); i++)
			{
				if (mas[i]->get_full_name() == fio)
				{
					mas[i]->redact();
					find = true;
					break;
				}
			}
			if (!find)
				std::cout << "Рабочий не найден, проверьете введенные данные" << std::endl;
			find = false;
			break;
		case 4:
			system("cls");
			for (int i = 0; i < mas.size(); i++)
			{
				std::cout << i + 1 << ". ";
				mas[i]->get_Employee();
			}
			if (mas.size() == 0)
				std::cout << "Сотрудники еще не были добавлены" << std::endl;
			break;
		default:
			std::cout << "Номер введенной вами команды не существует, проверьете коректность ввода\n\n";
			switcher = -1;
			break;
		}
		wait();
	}
}






