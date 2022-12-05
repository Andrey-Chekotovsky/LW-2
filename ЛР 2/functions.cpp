#include "functions.h"

const std::vector<std::string> choose_prior_menu = { "Водитель", "Бухгалтер", "Мэнеджер", "Начальник" };

void wait()
{
    char a;
    std::cout << "Для продолжения нажмите любую клавишу...";
    a = _getch();
}

void process_keys(Keys& keys, int& num, std::vector<std::string> vect)
{
    int a;
    while (true)
    {
        a = int(_getch());

        if (a == 72)
        {
            if (num - 1 > -1)
            {
                keys.set_top(true);
                num--;
                break;
            }
        }
        else if (a == 80)
        {
            if (num != vect.size() - 1)
            {
                keys.set_bot(true);
                num++;
                break;
            }
        }
        else if (a == 13)
        {
            keys.set_ent(true);
            break;
        }
    }
}

void show_meny(std::vector<std::string> meny, int num)
{
    for (int i = 0; i < meny.size(); i++)
    {
        if (i == num)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 << 4 | 0);
            std::cout << meny[i] << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        else
        {
            std::cout << meny[i] << std::endl;
        }
    }
}

int input_int()
{
    int num;
    while (true)
    {
        std::cin >> num;
        if (std::cin.good())
            break;
        std::cin.clear();
        std::cout << "некоректный ввод" << std::endl;
        std::cin.ignore();
    }
    return num;
}

