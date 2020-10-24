#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

enum TariffType
{
	Likes = 1,
	Maxi = 2,
	Ultra = 3,
	Absolut = 4

};

struct Phone
{
	string NumberPhone;
	string TariffPlan;
	string ConnectYear;
};

class SubscribeOwner
{
private:
	string _name, _surname, _patronymic;
	Phone phone;
protected:
public:

	SubscribeOwner();
	SubscribeOwner(string s, string n, string p, Phone ph);
	~SubscribeOwner();

	void Print();
	void SetParametrs(string s, string n, string p, Phone ph);

	Phone GetModel();
	string GetSurname();
	string GetName();
	string GetPatronymic();
	string GetPhone();
	string GetConnectYear();
	string GetTariffPlan();

	void AddToFile(string nameFile);

};
