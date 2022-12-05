#pragma once
#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<windows.h>
#include<winuser.h>
#include"Keys.h"
#include<conio.h>
#include <iomanip>


void wait();

void process_keys(Keys& keys, int& num, std::vector<std::string> vect);

void show_meny(std::vector<std::string> meny, int num);

int input_int();

