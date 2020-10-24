#include "SubscribeOwner.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Main.h"

using namespace std;

SubscribeOwner::SubscribeOwner()
{
}

SubscribeOwner::SubscribeOwner(string s, string n, string p, Phone ph)
{
}

SubscribeOwner::~SubscribeOwner()
{
}



void SubscribeOwner::Print()
{
	if (_surname != "") {
		cout << "ФИО :" << _surname << " " << _name << " " << _patronymic << endl;
		cout << "Номер телефона :" << phone.NumberPhone << "\n";
		cout << "Год подключения :" << phone.ConnectYear << "\n";
		cout << "Тарифный план :" << phone.TariffPlan << "\n";
	}
}

void SubscribeOwner::SetParametrs(string s, string n, string p, Phone ph)
{
	_surname = s;
	_name = n;
	_patronymic = p;
	phone.ConnectYear = ph.ConnectYear;
	phone.NumberPhone = ph.NumberPhone;
	phone.TariffPlan = ph.TariffPlan;

}

Phone SubscribeOwner::GetModel()
{
	return phone;
}

string SubscribeOwner::GetSurname()
{
	return _surname;
}

string SubscribeOwner::GetName()
{
	return _name;
}

string SubscribeOwner::GetPatronymic()
{
	return _patronymic;
}

string SubscribeOwner::GetPhone()
{
	return phone.NumberPhone;
}

string SubscribeOwner::GetConnectYear()
{
	return phone.ConnectYear;
}

string SubscribeOwner::GetTariffPlan()
{
	return phone.TariffPlan;
}



void SubscribeOwner::AddToFile(string nameFile)
{
	ofstream fout(nameFile, std::ios::app);

	if (fout.is_open())
	{
		if (_surname != "")
		{
			fout << _surname << " " << _name << " " << _patronymic << "\n";
			fout << phone.NumberPhone << "\n" << phone.ConnectYear << "\n" << phone.TariffPlan << "\n";
		}

	}
	else
	{
		cout << "Ошибка открытия файла\n";
	}
}
