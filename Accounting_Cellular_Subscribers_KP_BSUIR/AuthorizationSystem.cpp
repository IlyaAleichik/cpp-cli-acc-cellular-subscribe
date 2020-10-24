#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <clocale>
#include <string>
#include <fstream>
#include <iomanip>
#include "AuthorizationSystem.h"

using namespace std;

AuthorizationSystem::AuthorizationSystem()
{
}

AuthorizationSystem::AuthorizationSystem(string login, string password, int role)
{
}

AuthorizationSystem::~AuthorizationSystem()
{
}

void AuthorizationSystem::Print()
{
	if (users.login != "") {
		cout << "Имя пользователя: " << users.login << "  Тип пользователя: " << GetStatus(users.role) << endl;
	}
}

void AuthorizationSystem::SetParametrs(string login, string password, int role)
{
	users.login = login;
	users.password = password;
	users.role = role;
}

void AuthorizationSystem::AddToFile(string nameFile)
{
	ofstream fout(nameFile, std::ios::app);

	if (fout.is_open())
	{
		if (users.login != "")
		{
			fout << users.login << "\n" << users.password << "\n" << users.role << "\n";
		}
	}
	else
	{
		cout << "Ошибка открытия файла\n";
	}
}

string AuthorizationSystem::GetLogin()
{
	return users.login;
}


string AuthorizationSystem::GetPassword()
{
	return users.password;
}

string AuthorizationSystem::GetStatus(int a)
{
	string res;
	a == 0 ? res = "Администратор" : res = "Пользователь";
	return res;
}

int AuthorizationSystem::GetType()
{
	return users.role;
}
