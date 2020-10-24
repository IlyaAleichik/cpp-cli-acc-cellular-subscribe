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

#include "AuthorizationSystem.h"
#include "SubscribeOwner.h"
#include <regex>

using namespace std;


//������� � �������� �����
string InputUserdata = { "Userdata.txt" },
InputSubscribeOwner = { "InputSubscribeOwner.txt" };


//��������� �������
void searchBy(int countSubcsribe, string nameInputFile, int stateMenu); 
void sortBy(int countSubcsribe, string nameInputFile, int stateMenu);
void signToApp();
void readFromFileSubscribeOwner(SubscribeOwner* S, string nameFile);
void administratorMenu(int st);
void writeInFileInputSubscribeOwner(int n, string nameF, SubscribeOwner* C);
void userMenu(int st);
void viewMenu(int n);
void administratorMenu(int st);

//������� � ������� ���� � ������� ������ ������������/�������������� 
void viewMenu(int n) {
	n == 1 ? administratorMenu(0) : userMenu(0);
}

//������� ������
void searchBy(int countSubcsribe, string nameInputFile, int stateMenu) {
	cout << " �����\n"
		<< "  (1) �� ������� � �����\n"
		   "  (2) �� ����� � ��������\n"
		<< "  (3) �� ������ ��������\n"
		<< "  (4) �� ���� ����������� (��������������)\n";

	Phone ph;
	string Surname, Name, Patronymic;

	SubscribeOwner* S1 = new SubscribeOwner[countSubcsribe];

	readFromFileSubscribeOwner(S1, nameInputFile);

	int a,count=0;
	cin >> a;

	switch (a)
	{
	case 1:
		system("cls");

		cout << " ������� ������� �������� ��������\n";
		cin >> Surname;
		cout << " ������� ��� �������� ��������\n";
		cin >> Name;
		for (int i = 0; i < countSubcsribe; i++)
		{
			if (S1[i].GetName() == Name && S1[i].GetSurname() == Surname)
			{
				if (S1[i].GetSurname() != "")
				{
					cout << S1[i].GetSurname() << " " << S1[i].GetName() << " " << S1[i].GetPatronymic() << "\n";
					cout << S1[i].GetConnectYear() << "\n" << S1[i].GetTariffPlan() << "\n" << S1[i].GetPhone() << "\n"
					<< "_____________________________________________________________________________________________\n";

				}

			}
		}
		break;
	case 2:
		system("cls");

		cout << " ������� ��� �������� ��������\n";
		cin >> Name;
		cout << " ������� �������� �������� ��������\n";
		cin >> Patronymic;

		for (int i = 0; i < countSubcsribe; i++)
		{
			if (S1[i].GetName() == Name && S1[i].GetPatronymic() == Patronymic) {
				if (S1[i].GetSurname() != "")
				{
					cout << S1[i].GetSurname() << " " << S1[i].GetName() << " " << S1[i].GetPatronymic() << "\n";
					cout << S1[i].GetConnectYear() << "\n" << S1[i].GetTariffPlan() << "\n" << S1[i].GetPhone() << "\n"
						<< "_____________________________________________________________________________________________\n";

				}
			}		
		}
		break;
	case 3:
		system("cls");

		cout << " ������� ����� �������� �������� �������� \n";
		cin >> ph.NumberPhone;

		for (int i = 0; i < countSubcsribe; i++)
		{
			if (S1[i].GetPhone() == ph.NumberPhone)
			{
				if (S1[i].GetSurname() != "")
				{
					cout << S1[i].GetSurname() << " " << S1[i].GetName() << " " << S1[i].GetPatronymic() << "\n";
					cout << S1[i].GetConnectYear() << "\n" << S1[i].GetTariffPlan() << "\n" << S1[i].GetPhone() << "\n"
						<< "_____________________________________________________________________________________________\n";

				}
			}

		}
		break;

	case 4:
		system("cls");
		
		cout << "������� ��� ����������� ������� ��������� \n";
		cin >> ph.ConnectYear;
		cout << "\n";
		for (int i = 0; i < countSubcsribe; i++)
		{
			if (S1[i].GetConnectYear() == ph.ConnectYear)
			{
				if (S1[i].GetSurname() != "")
				{
					cout << S1[i].GetSurname() << " " << S1[i].GetName() << " " << S1[i].GetPatronymic() << "\n";
					cout << S1[i].GetConnectYear() << "\n" << S1[i].GetTariffPlan() << "\n" << S1[i].GetPhone() << "\n"
						<< "_____________________________________________________________________________________________\n";
					count++;
				}
			}

		}
		cout << "\n���-�� ��������� ������������ � "  + ph.ConnectYear + " ���������: " << count <<"\n";
		break;
	}
	
	_getch();
    viewMenu(stateMenu);

}

//������� ����������
void sortBy(int countSubcsribe, string nameInputFile, int stateMenu) {
	Phone ph,ph2;
	string Surname, Name, Patronymic;

	cout << " ����������\n"
		<< "  (1) �� ��������(�����������)\n"
		<< "  (2) �� ��������(��������)\n"
		<< "  (3) �� ���� �����������(��������)\n"
		<< "  (4) �� ���� �����������(�����������)\n"
		<< "  (5) �� �����(�����������) \n"
	    << "  (6) �� �����(��������) \n";

	int sel;
	cin >> sel; 
	SubscribeOwner *C = new SubscribeOwner[countSubcsribe];

	readFromFileSubscribeOwner(C, nameInputFile);

	switch (sel)
	{
	case 1:

		for (int i = 0; i < countSubcsribe; i++)
		{
			for (int j = i + 1; j < countSubcsribe; j++)
			{
				if (C[i].GetSurname() > C[j].GetSurname())
				{
					Surname = C[i].GetSurname();
					Name = C[i].GetName();
					Patronymic = C[i].GetPatronymic();

					ph.ConnectYear = C[i].GetConnectYear();
					ph.TariffPlan = C[i].GetTariffPlan();
					ph.NumberPhone = C[i].GetPhone();

					ph2.ConnectYear = C[j].GetConnectYear();
					ph2.TariffPlan = C[j].GetTariffPlan();
					ph2.NumberPhone = C[j].GetPhone();


					SubscribeOwner Buf(Surname, Name, Patronymic, ph);
					C[i].SetParametrs(C[j].GetSurname(), C[j].GetName(), C[j].GetPatronymic(), C[j].GetModel());
					C[j].SetParametrs(Surname, Name, Patronymic, ph);
				}
			}
		}
		break;
	case 2:

		for (int i = 0; i < countSubcsribe; i++)
		{
			for (int j = i + 1; j < countSubcsribe; j++)
			{
				if (C[i].GetSurname() < C[j].GetSurname())
				{
					Surname = C[i].GetSurname();
					Name = C[i].GetName();
					Patronymic = C[i].GetPatronymic();

					ph.ConnectYear = C[i].GetConnectYear();
					ph.TariffPlan = C[i].GetTariffPlan();
					ph.NumberPhone = C[i].GetPhone();

					ph2.ConnectYear = C[j].GetConnectYear();
					ph2.TariffPlan = C[j].GetTariffPlan();
					ph2.NumberPhone = C[j].GetPhone();


					SubscribeOwner Buf(Surname, Name, Patronymic, ph);
					C[i].SetParametrs(C[j].GetSurname(), C[j].GetName(), C[j].GetPatronymic(), C[j].GetModel());
					C[j].SetParametrs(Surname, Name, Patronymic, ph);
				}
			}
		}
		break;
	case 3:

		for (int i = 0; i < countSubcsribe; i++)
		{
			for (int j = i + 1; j < countSubcsribe; j++)
			{
				if (C[i].GetConnectYear() < C[j].GetConnectYear())
				{
					Surname = C[i].GetSurname();
					Name = C[i].GetName();
					Patronymic = C[i].GetPatronymic();

					ph.ConnectYear = C[i].GetConnectYear();
					ph.TariffPlan = C[i].GetTariffPlan();
					ph.NumberPhone = C[i].GetPhone();

					ph2.ConnectYear = C[j].GetConnectYear();
					ph2.TariffPlan = C[j].GetTariffPlan();
					ph2.NumberPhone = C[j].GetPhone();


					SubscribeOwner Buf(Surname, Name, Patronymic, ph);
					C[i].SetParametrs(C[j].GetSurname(), C[j].GetName(), C[j].GetPatronymic(), C[j].GetModel());
					C[j].SetParametrs(Surname, Name, Patronymic, ph);
				}
			}
		}

		break;
	case 4:

		for (int i = 0; i < countSubcsribe; i++)
		{
			for (int j = i + 1; j < countSubcsribe; j++)
			{
				if (C[i].GetConnectYear() > C[j].GetConnectYear())
				{
					Surname = C[i].GetSurname();
					Name = C[i].GetName();
					Patronymic = C[i].GetPatronymic();

					ph.ConnectYear = C[i].GetConnectYear();
					ph.TariffPlan = C[i].GetTariffPlan();
					ph.NumberPhone = C[i].GetPhone();

					ph2.ConnectYear = C[j].GetConnectYear();
					ph2.TariffPlan = C[j].GetTariffPlan();
					ph2.NumberPhone = C[j].GetPhone();


					SubscribeOwner Buf(Surname, Name, Patronymic, ph);
					C[i].SetParametrs(C[j].GetSurname(), C[j].GetName(), C[j].GetPatronymic(), C[j].GetModel());
					C[j].SetParametrs(Surname, Name, Patronymic, ph);
				}
			}
		}

		break;
	case 5:

		for (int i = 0; i < countSubcsribe; i++)
		{
			for (int j = i + 1; j < countSubcsribe; j++)
			{
				if (C[i].GetName() > C[j].GetName())
				{
					Surname = C[i].GetSurname();
					Name = C[i].GetName();
					Patronymic = C[i].GetPatronymic();

					ph.ConnectYear = C[i].GetConnectYear();
					ph.TariffPlan = C[i].GetTariffPlan();
					ph.NumberPhone = C[i].GetPhone();

					ph2.ConnectYear = C[j].GetConnectYear();
					ph2.TariffPlan = C[j].GetTariffPlan();
					ph2.NumberPhone = C[j].GetPhone();


					SubscribeOwner Buf(Surname, Name, Patronymic, ph);
					C[i].SetParametrs(C[j].GetSurname(), C[j].GetName(), C[j].GetPatronymic(), C[j].GetModel());
					C[j].SetParametrs(Surname, Name, Patronymic, ph);
				}
			}
		}

		break;
	case 6:

		for (int i = 0; i < countSubcsribe; i++)
		{
			for (int j = i + 1; j < countSubcsribe; j++)
			{
				if (C[i].GetName() < C[j].GetName())
				{
					Surname = C[i].GetSurname();
					Name = C[i].GetName();
					Patronymic = C[i].GetPatronymic();

					ph.ConnectYear = C[i].GetConnectYear();
					ph.TariffPlan = C[i].GetTariffPlan();
					ph.NumberPhone = C[i].GetPhone();

					ph2.ConnectYear = C[j].GetConnectYear();
					ph2.TariffPlan = C[j].GetTariffPlan();
					ph2.NumberPhone = C[j].GetPhone();


					SubscribeOwner Buf(Surname, Name, Patronymic, ph);
					C[i].SetParametrs(C[j].GetSurname(), C[j].GetName(), C[j].GetPatronymic(), C[j].GetModel());
					C[j].SetParametrs(Surname, Name, Patronymic, ph);
				}
			}
		}

		break;
	}



	writeInFileInputSubscribeOwner(countSubcsribe,nameInputFile, C);
	cout << "���������� ���������\n";
	_getch();
	viewMenu(stateMenu);
}





//������� ���-�� ��������� ����� 
int countFromFile(string nameFile) {
	int k = 0;

	ifstream fin(nameFile);

	if (fin.is_open()) {
		fin >> k;
	}
	else {
		cout << "������ �������� �����.\n";
	}
	fin.close();
	return k;
}
//������ � ���� 
void writeInFile(int n, string nameF, AuthorizationSystem* A) {
	ofstream fout(nameF, std::ios::out);

	if (fout.is_open())
	{
		fout << n << endl;
		for (int i = 0; i < n; i++)
		{
			A[i].AddToFile(nameF);
		}
	}
	else {
		cout << "������ �������� ����� \"OutputApartment.txt\".\n";
	}
	fout.close();
}
//������ �� �����
void readFromFile(AuthorizationSystem* A, string nameFile) {
	int k;
	Users user;

	ifstream fin(nameFile);

	if (fin.is_open()) {
		fin >> k;
		for (int i = 0; i < k; i++) {
			fin >> user.login >> user.password >> user.role;

			A[i].SetParametrs(user.login, user.password, user.role);

		}
	}
}
//������� ���������� ������������
void addDataUser(int countUser, string nameInputFile) {

	Users us;
	int NewCountUser = countUser + 1;
	bool isLogin = true;
	AuthorizationSystem* A1 = new AuthorizationSystem[NewCountUser];
	readFromFile(A1, nameInputFile);

	
	
	cout << "������� ����� : ";
	cin >> us.login;



	cout << "������� ������: ";
	cin >> us.password;
	cout << "��� �������: \n" <<
		    "(0) ������������� \n" <<
		    "(1) ������������\n>";

	cin >> us.role;

	for (int i = 0; i < countUser; i++)
	{
		if (us.login == A1[i].GetLogin())
		{
			isLogin = true;
			cout << "������������ � ����� ������� ��� ����������\n";
			break;
		}
		else
		{
			isLogin = false;
		}
	}
	if (isLogin == true)
	{

		cout << "������� ��������� ��� �����? Y/n \n";
		char c = _getch();
		if (c == 'n' || c == 'N')
		{
			administratorMenu(0);
		}
	}
	else
	{
		A1[NewCountUser - 1].SetParametrs(us.login, us.password, us.role);
		writeInFile(NewCountUser, nameInputFile, A1);

		cout << "����� ������������ ������� ������\n";
	}

	_getch();
	administratorMenu(0);

}
//������� ��������� ������ ������������
void alterDataUser(int countUser, string nameInputFile) {

	bool isLogin = true;
	string  login, password;
	int role, altIndex = 0;
	AuthorizationSystem *A = new AuthorizationSystem[countUser];

	readFromFile(A, nameInputFile);

	cout << "������� ����� ������������ ������� ������ ��������: ";
	cin >> login;

	for (int i = 0; i < countUser; i++)
	{
		if (login == A[i].GetLogin())
		{
			altIndex = i;
		}
	}

	cout << "������� ����� ����� : ";
	cin >> login;
	cout << "������� ����� ������: ";
	cin >> password;
	cout << "��� �������: \n" <<
		"(0) ������������� \n" <<
		"(1) ������������\n>";
	cin >> role;
	

	for (int i = 0; i < countUser; i++)
	{
		if (login == A[i].GetLogin())
		{
			isLogin = true;
			cout << "������������ � ����� ������� ��� ����������\n";
			break;
		}
		else
		{
			isLogin = false;
		}
	}
	if (isLogin == true)
	{

		cout << "������� ��������� ��� �����? Y/n \n";
		char c = _getch();
		if (c == 'n' || c == 'N')
		{
			administratorMenu(0);
		}
	}
	else
	{
		A[altIndex].SetParametrs(login, password, role);
		writeInFile(countUser, nameInputFile, A);

		cout << "��������� ������ ������������ ������ �������\n";
	}




	_getch();
	administratorMenu(0);
}
//������� �������� ������������
void deleteDataUser(int countUser, string nameInputFile) {

	AuthorizationSystem *A = new AuthorizationSystem[countUser];
	readFromFile(A, nameInputFile);

	string  login, password = "";
	int delIndex, role = 0;
	cout << "������� ����� ������������ ������� ������ �������: ";
	cin >> login;


	for (int i = 0; i < countUser; i++)
	{
		if (login == A[i].GetLogin())
		{
			delIndex = i;
		}
		else
		{
			delIndex = -1;
		}
	}

	if (delIndex >= 0)
	{
		login = "";

		A[delIndex].SetParametrs(login, password, role);
		writeInFile(countUser, nameInputFile, A);

		A = new AuthorizationSystem[countFromFile(nameInputFile)];
		readFromFile(A, nameInputFile);

		writeInFile(countUser - 1, nameInputFile, A);

		cout << "������������ ������� ������ \n";
		_getch();
		administratorMenu(0);
		system("cls");
	}
	else
	{
		cout << "������������ � ����� ������� �� ����������\n";
	}


	cout << "������� ��������� ��� �����? Y/n \n";
	char c = _getch();
	if (c =='n')
	{
		administratorMenu(0);
	}
}
//������� ������ ������ �������������
void viewDataUser(int countUser, string nameInputFile) {

		AuthorizationSystem* A = new AuthorizationSystem[countUser];
		readFromFile(A, nameInputFile);

		for (int i = 0; i < countUser; i++)
		{
			cout << "������������ �" << i + 1 << " :\n";
			A[i].Print();
		}

	_getch();
	administratorMenu(0);
}



//������ � ���� ������ ��������
void writeInFileInputSubscribeOwner(int n, string nameF, SubscribeOwner *C) {
	
	ofstream fout(nameF, std::ios::out);

	if (fout.is_open())
	{
		fout << n << endl;
		for (int i = 0; i < n; i++)
		{
			C[i].AddToFile(nameF);
		}
	}
	else {
		cout << "������ �������� ����� \"OutputApartment.txt\".\n";
	}
	fout.close();
}
//������ �� ����� ������ ��������
void readFromFileSubscribeOwner(SubscribeOwner *S, string nameFile) {
	int k;
	string Name, Surname, Patronymic;
	Phone ph;

	ifstream fin(nameFile);

	if (fin.is_open()) {
		fin >> k;
		for (int i = 0; i < k; i++) {
			fin >> Surname >> Name >> Patronymic;
			fin >> ph.NumberPhone >> ph.ConnectYear >> ph.TariffPlan;

			S[i].SetParametrs(Surname, Name, Patronymic, ph);

		}
	}
}


//���������� ��������
void addData(int countSubcsribe, string nameInputFile, int stateMenu) {


	string Surname, Name, Patronymic;
	Phone ph;

	regex phone("[+](375)[0-9]{2}[0-9]{7}");
	regex year("[0-9]{4}");
	regex text("^[�-��-߸�a-zA-Z]+$");

	int setType;
	int NewCountSubscribeOwner = countSubcsribe + 1;

	SubscribeOwner *S1 = new SubscribeOwner[NewCountSubscribeOwner];
	readFromFileSubscribeOwner(S1, nameInputFile);

	bool isValueName = false;

	cin.ignore(32767, '\n');
	do
	{
		isValueName = false;
		cout << "������� �������: ";
		getline(cin,Surname);
		if (Surname == "")
		{
			cout << "������ ������� ���� ������\n";
			isValueName = true;
		}
		else
		{
			if (regex_match(Surname, text))
			{
				isValueName = false;
			}
			else
			{
				cout << "��� ����� �������� ������ ����� �������� �/��� ����� ���������� ��������  \n";
				isValueName = true;
			}
		}
	} while (isValueName != false);

	do
	{
		isValueName = false;
		cout << "������� ���: ";
		getline(cin, Name);
		if (Name == "")
		{
			cout << "������ ������� ���� ������\n";
			isValueName = true;
		}
		else
		{
			if (regex_match(Name, text))
			{
				isValueName = false;
			}
			else
			{
				cout << "��� ����� �������� ������ ����� �������� �/��� ����� ���������� ��������  \n";
				isValueName = true;
			}
		}
	} while (isValueName != false);

	do
	{
		isValueName = false;
		cout << "������� ��������: ";
		getline(cin, Patronymic);
		if (Patronymic == "")
		{
			cout << "������ ������� ���� ������\n";
			isValueName = true;
		}
		else
		{
			if (regex_match(Patronymic, text))
			{
				isValueName = false;
			}
			else
			{
				cout << "��� ����� �������� ������ ����� �������� �/��� ����� ���������� ��������  \n";
				isValueName = true;
			}
		}

	} while (isValueName != false);

	do
	{
		isValueName = false;
		cout << "������� ����� ��������: ";
		getline(cin, ph.NumberPhone);
		if (ph.NumberPhone == "")
		{
			cout << "������ ������� ���� ������\n";
			isValueName = true;
		}
		else
		{
			if (regex_match(ph.NumberPhone, phone))
			{
				isValueName = false;
			}
			else
			{
				cout << "����� �������� ������ ���� � ������� +375XXxxxxxxx \n";
				isValueName = true;
			}
		}
	
	} while (isValueName != false);

	do
	{
		isValueName = false;
		cout << "��� �����������:\n";
		getline(cin, ph.ConnectYear);
		if (ph.ConnectYear == "")
		{
			cout << "������ ������� ���� ������\n";
			isValueName = true;
		}
		else
		{
			if (regex_match(ph.ConnectYear, year))
			{
				isValueName = false;
			}
			else
			{
				cout << "��� ������ ���� � ������� ���� \n";
				isValueName = true;
			}
		}

	} while (isValueName != false);



        cout << "������� �������� ����: \n"
			<< "(1):�������  (2):�����  (3):������  (4):�������\n";

	
		 
		 do {

			 while (!(cin >> setType) || (cin.peek() != '\n')) {

				 cin.clear();

				 while (cin.get() != '\n');
				 cout << "������ �����, ������ �� ������ ��� ������! ��������� ������� �����" << endl;
			 }

			 isValueName = false;
			 if (setType >= 1 && setType <= 4)
			 {
				 isValueName = false;
				 switch (setType) {
				 case TariffType::Likes:
					 ph.TariffPlan = "�������";
					 break;
				 case TariffType::Maxi:
					 ph.TariffPlan = "�����";
					 break;
				 case TariffType::Ultra:
					 ph.TariffPlan = "������";
					 break;
				 case TariffType::Absolut:
					 ph.TariffPlan = "�������";
					 break;
				 }
			 }
			 else
			 {
				 isValueName = true;
				 cout << "���������� ������ � �����:" << setType << "�� ����������\n";
			 }

		 } while (isValueName != false);


	

	    S1[NewCountSubscribeOwner - 1].SetParametrs(Surname, Name, Patronymic, ph);
		writeInFileInputSubscribeOwner(NewCountSubscribeOwner, nameInputFile, S1);
		cout << "������� ������� ��������\n";
		_getch();
	    viewMenu(stateMenu);
}
//��������� ������ ��������
void alterData(int countSubcsribe, string nameInputFile, int stateMenu) {
	system("cls");

	string Surname, Name, Patronymic;
	Phone P;
	int altIndex;

	SubscribeOwner *S1 = new SubscribeOwner[countSubcsribe];

	readFromFileSubscribeOwner(S1, nameInputFile);

	cout << "������� ��� �������� �������� ����� ��������: ";
	cin >> Surname >> Name >> Patronymic;
	for (int i = 0; i < countSubcsribe; i++)
	{
		if (Surname == S1[i].GetSurname())
		{
			if (Name == S1[i].GetName())
			{
				if (Patronymic == S1[i].GetPatronymic())
				{
					altIndex = i;
				}

			}

		}
	}

	cout << "������� ����� ��� ��������:";
	cin >> Surname >> Name >> Patronymic;
	cout << "����� ����� ��������: ";
	cin >> P.NumberPhone;
	cout << "��� �����������: ";
	cin >> P.ConnectYear;
	cout << "�������� ����: ";
	cin >> P.TariffPlan;

	S1[altIndex].SetParametrs(Surname, Name, Patronymic, P);
	writeInFileInputSubscribeOwner(countSubcsribe, nameInputFile, S1);
	cout << "������ �������� ������� ��������\n";
	_getch();

	viewMenu(stateMenu);
}
//�������� ��������
void deleteData(int countSubcsribe, string nameInputFile, int stateMenu) {

	string Surname, Name, Patronymic;
	Phone P;
	int delIndex;

	SubscribeOwner *S1 = new SubscribeOwner[countSubcsribe];

	readFromFileSubscribeOwner(S1, nameInputFile);

	cout << "������� ���: ";
	cin >> Surname >> Name >> Patronymic;

	for (int i = 0; i < countSubcsribe; i++)
	{
		if (Surname == S1[i].GetSurname())
		{
			if (Name == S1[i].GetName())
			{
				if (Patronymic == S1[i].GetPatronymic())
				{
					delIndex = i;
				}

			}
	
		}
	}

	Surname ="", Name = "", Patronymic = "";
	S1[delIndex].SetParametrs(Surname, Name, Patronymic, P);
	writeInFileInputSubscribeOwner(countSubcsribe-1, nameInputFile, S1);

	cout << "������� ������� ������\n";
	_getch();

	viewMenu(stateMenu);

}
//����� ������ ���������
void viewData(int countSubcsribe, string nameInputFile, int stateMenu) {

		countSubcsribe = countFromFile(nameInputFile);
		SubscribeOwner *S = new SubscribeOwner[countSubcsribe];
		readFromFileSubscribeOwner(S, nameInputFile);

		for (int i = 0; i < countSubcsribe; i++)
		{
			cout << "������� �" << i + 1 << " :\n";
			S[i].Print();
			cout << "_______________________________\n";
		}

	_getch();
	viewMenu(stateMenu);
}


//���� ������ ��������������
void administratorMenu(int st) {
	cout << "���� ��������������\n"
		<< "  (0) ������� ���������.\n"
		<< "  (1) ������� � ����� �����.\n"
		<< " ������ � ������� �������������\n"
		<< "  (2) ���������� ������������\n"
		<< "  (3) �������� ������������\n"
		<< "  (4) ��������� ������ ������������\n"
		<< "  (5) ����� ����������\n"
		<< " ������ � ������� ���������\n"
		<< "  (6) ���������� ������\n"
		<< "  (7) �������� ������\n"
		<< "  (8) ��������� ������\n"
		<< "  (9) ����� ����������\n"
		<< "  (10) ���������� (3 ����)\n"
		<< "  (11) ����� (3 ����)\n";
	cout << "->"; cin >> st;
	

	while (st != 0) {
		if (st == 1) {
			system("cls");
			signToApp();
		}
		if (st == 2) {	
			addDataUser(countFromFile(InputUserdata), InputUserdata);
		}
		if (st == 3) {
			deleteDataUser(countFromFile(InputUserdata), InputUserdata);
		}
		if (st == 4) {
			alterDataUser(countFromFile(InputUserdata), InputUserdata);
		}
		if (st == 5) {
			viewDataUser(countFromFile(InputUserdata), InputUserdata);
		}
		if (st == 6) {
			addData(countFromFile(InputSubscribeOwner), InputSubscribeOwner,1);
		}
		if (st == 7) {
			deleteData(countFromFile(InputSubscribeOwner), InputSubscribeOwner,1);
		}
		if (st == 8) {
			alterData(countFromFile(InputSubscribeOwner), InputSubscribeOwner,1);
		}
		if (st == 9) {
			viewData(countFromFile(InputSubscribeOwner), InputSubscribeOwner,1);
		}
		if (st == 10) {
			sortBy(countFromFile(InputSubscribeOwner), InputSubscribeOwner,1);
		}
		if (st == 11) {
			searchBy(countFromFile(InputSubscribeOwner), InputSubscribeOwner,1);
		}

	}
	exit(0);
}

//���� ������ ������������
void userMenu(int st) {
	cout << "����\n"
		<< " (0) ������� ���������.\n"
		<< " (1) ������� � ����� �����.\n"
		<< " (2) ����� ���������� � ���������\n"
		<< " (3) ���������� (4 ����)\n"
		<< " (4) ����� (3 ����)\n";
	cout << "->"; cin >> st;

	while (st != 0) {
		if (st == 1) {
			system("cls");
			signToApp();
		}
		if (st == 2) {
			viewData(countFromFile(InputSubscribeOwner), InputSubscribeOwner,0);
		}
		if (st == 3) {
			sortBy(countFromFile(InputSubscribeOwner), InputSubscribeOwner,0);
		}
		if (st == 4) {
			searchBy(countFromFile(InputSubscribeOwner), InputSubscribeOwner,0);
		}

	}
	exit(0);
}

// ������� ������������ ������
void mainMenu(int userMode) {
	system("cls");
	int stateMenu = 0;

	userMode == 0 ? administratorMenu(stateMenu) : userMenu(stateMenu);

	mainMenu(userMode);
}

#pragma endregion

void checkUserPassword(int i, string l,string p, AuthorizationSystem *A) {
	if (l == A[i].GetLogin() && p == A[i].GetPassword())
	{
		cout << " ����� ���������� � ������� " << A[i].GetLogin() << "(" << A[i].GetStatus(A[i].GetType()) << ")" << "��� ����������� ������� ����� �������...\n";
		_getch();
		mainMenu(A[i].GetType());
	}
	else {
		cout << "��������� ������ �����, ��� ������������ ��� ������ �� �����!\n";
		cout << "������� ��������� ��� �����? Y/n \n";
		char c = _getch();
		if (c == 'n')
		{
			exit(0);
		}

		_getch();
		system("cls");
		signToApp();
	}
}

//������� �����������
void signToApp() {
	
	char c;
	string tLogin = "", tPassword = "";
	int index = 0;

	int NewCountUserData = countFromFile(InputUserdata);

	AuthorizationSystem *A = new AuthorizationSystem[NewCountUserData];

	readFromFile(A, InputUserdata);

	cout << "�����: " << "";
	cin >> tLogin; cout << "\n";
	cout << "������: " << "";
	cin >> tPassword; cout << "\n";

	for (int i = 0; i < NewCountUserData; i++)
	{
		if (tLogin == A[i].GetLogin())
		{
			index = i;
		}
	}

	checkUserPassword(index, tLogin,tPassword,A);

}

#pragma endregion

#pragma region DataInizializtion
//������� ������� �������
void clear() {
	system("cls");
}

//������������� ������ ��� ������ �����
void dataUserInizialization(int countUser, string nameInputFile) {
	cout << "\n������ ���� � ��������� | �������� ��������������" << "\n";
	int count = 0;
	Users us;
	string tmpPassword;
	int NewCountSubscribeOwner = countUser + 1;


	AuthorizationSystem *A1 = new AuthorizationSystem[NewCountSubscribeOwner];

	readFromFile(A1, nameInputFile);

	cout << "������� ����� : ";
	cin >> us.login;
	cout << "������� ������: ";
	cin >> us.password;
	cout << "���������� ������: ";
	cin >> tmpPassword;


	if (tmpPassword == us.password)
	{
		cout << "�������� ����� ������� ������� ... " << "\n";
		A1[NewCountSubscribeOwner - 1].SetParametrs(us.login, us.password, 0);
		writeInFile(NewCountSubscribeOwner, nameInputFile, A1);
	}
	else
	{
		count++;
		cout << "������� ��������� ��� �����? Y/n";
		char c = _getch();
		if (count != 0)
		{
			clear();
		}
		c == 'y' ? dataUserInizialization(countUser, nameInputFile) : c == 'n' ? exit(0) : exit(0);

	}
	delete[] A1;
}


//������������� ������ ���� ��� ���������� � ��������� ������������� ����� ������������ 
void dataInitialization(int count, string nameFile, AuthorizationSystem *A) {
	int countAdmin = 0;

	ifstream uout(nameFile);

	for (int i = 0; i < count; i++)
	{

		if (A[i].GetType() != 0)
		{

		}

		if (A[i].GetType() == 0)
		{
			countAdmin++;
		}

	
	}


	if (uout) {
		cout << "���� ������� ������� ���������� " << "\n";

		if (countAdmin > 0)
		{
			cout << "������������� ������� ���������� " << "\n";
		}
		else
		{
			cout << "�������������� ������� �� ���������� " << "\n";
			cout << "������� � ������� �������� �������������� " << "\n";
			dataUserInizialization(count, nameFile);
		}
		uout.close();
	}
	else {
		
		dataUserInizialization(count, nameFile);

	}
}


//����� �����
int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int CountUserData = countFromFile(InputUserdata);

	AuthorizationSystem *A = new AuthorizationSystem[CountUserData];

	readFromFile(A, InputUserdata);

	dataInitialization(CountUserData, InputUserdata, A);

	system("cls");

	signToApp();

	delete[] A;
	_getch();

}
