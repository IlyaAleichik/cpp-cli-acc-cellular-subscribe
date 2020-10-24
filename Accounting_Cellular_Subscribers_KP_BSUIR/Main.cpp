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


//входные и выходыне файлы
string InputUserdata = { "Userdata.txt" },
InputSubscribeOwner = { "InputSubscribeOwner.txt" };


//прототипы функций
void searchBy(int countSubcsribe, string nameInputFile, int stateMenu); 
void sortBy(int countSubcsribe, string nameInputFile, int stateMenu);
void signToApp();
void readFromFileSubscribeOwner(SubscribeOwner* S, string nameFile);
void administratorMenu(int st);
void writeInFileInputSubscribeOwner(int n, string nameF, SubscribeOwner* C);
void userMenu(int st);
void viewMenu(int n);
void administratorMenu(int st);

//переход в главное меню с выбором режима пользователя/администратора 
void viewMenu(int n) {
	n == 1 ? administratorMenu(0) : userMenu(0);
}

//функция поиска
void searchBy(int countSubcsribe, string nameInputFile, int stateMenu) {
	cout << " ПОИСК\n"
		<< "  (1) по фамилии и имени\n"
		   "  (2) по имени и отчеству\n"
		<< "  (3) по номеру телефона\n"
		<< "  (4) по году подключения (индивидуальное)\n";

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

		cout << " Введите фамилию искомого абонента\n";
		cin >> Surname;
		cout << " Введите имя искомого абонента\n";
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

		cout << " Введите имя искомого абонента\n";
		cin >> Name;
		cout << " Введите отчество искомого абонента\n";
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

		cout << " Введите номер телефона искомого абонента \n";
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
		
		cout << "Введите год подключения искомых абонентов \n";
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
		cout << "\nКол-во абонентов подключенных с "  + ph.ConnectYear + " сотавляет: " << count <<"\n";
		break;
	}
	
	_getch();
    viewMenu(stateMenu);

}

//функция сортировки
void sortBy(int countSubcsribe, string nameInputFile, int stateMenu) {
	Phone ph,ph2;
	string Surname, Name, Patronymic;

	cout << " СОРТИРОВКА\n"
		<< "  (1) по алфавиту(возрастанию)\n"
		<< "  (2) по алфавиту(убыванию)\n"
		<< "  (3) по году подключения(убыванию)\n"
		<< "  (4) по году подключения(возростанию)\n"
		<< "  (5) по имени(возрастанию) \n"
	    << "  (6) по имени(убыванию) \n";

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
	cout << "Сортировка закончена\n";
	_getch();
	viewMenu(stateMenu);
}





//подсчет кол-ва элементов файла 
int countFromFile(string nameFile) {
	int k = 0;

	ifstream fin(nameFile);

	if (fin.is_open()) {
		fin >> k;
	}
	else {
		cout << "Ошибка открытия файла.\n";
	}
	fin.close();
	return k;
}
//запись в файл 
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
		cout << "Ошибка открытия файла \"OutputApartment.txt\".\n";
	}
	fout.close();
}
//чтение из файла
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
//функция добовления пользователя
void addDataUser(int countUser, string nameInputFile) {

	Users us;
	int NewCountUser = countUser + 1;
	bool isLogin = true;
	AuthorizationSystem* A1 = new AuthorizationSystem[NewCountUser];
	readFromFile(A1, nameInputFile);

	
	
	cout << "Введите логин : ";
	cin >> us.login;



	cout << "Введите пароль: ";
	cin >> us.password;
	cout << "Тип профиля: \n" <<
		    "(0) Администратор \n" <<
		    "(1) Пользователь\n>";

	cin >> us.role;

	for (int i = 0; i < countUser; i++)
	{
		if (us.login == A1[i].GetLogin())
		{
			isLogin = true;
			cout << "Пользователь с таким логином уже существует\n";
			break;
		}
		else
		{
			isLogin = false;
		}
	}
	if (isLogin == true)
	{

		cout << "Желаете повторить или выйти? Y/n \n";
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

		cout << "Новый пользователь успешно создан\n";
	}

	_getch();
	administratorMenu(0);

}
//функция изменения данных пользователя
void alterDataUser(int countUser, string nameInputFile) {

	bool isLogin = true;
	string  login, password;
	int role, altIndex = 0;
	AuthorizationSystem *A = new AuthorizationSystem[countUser];

	readFromFile(A, nameInputFile);

	cout << "Введите логин пользователя которго хотите изменить: ";
	cin >> login;

	for (int i = 0; i < countUser; i++)
	{
		if (login == A[i].GetLogin())
		{
			altIndex = i;
		}
	}

	cout << "Введите новый логин : ";
	cin >> login;
	cout << "Введите новый пароль: ";
	cin >> password;
	cout << "Тип профиля: \n" <<
		"(0) Администратор \n" <<
		"(1) Пользователь\n>";
	cin >> role;
	

	for (int i = 0; i < countUser; i++)
	{
		if (login == A[i].GetLogin())
		{
			isLogin = true;
			cout << "Пользователь с таким логином уже существует\n";
			break;
		}
		else
		{
			isLogin = false;
		}
	}
	if (isLogin == true)
	{

		cout << "Желаете повторить или выйти? Y/n \n";
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

		cout << "Изменение данных пользователя прошло успешно\n";
	}




	_getch();
	administratorMenu(0);
}
//функция удаления пользователя
void deleteDataUser(int countUser, string nameInputFile) {

	AuthorizationSystem *A = new AuthorizationSystem[countUser];
	readFromFile(A, nameInputFile);

	string  login, password = "";
	int delIndex, role = 0;
	cout << "Введите логин пользователя которго хотите удалить: ";
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

		cout << "Пользователь успешно удален \n";
		_getch();
		administratorMenu(0);
		system("cls");
	}
	else
	{
		cout << "Пользователя с таким логином не существует\n";
	}


	cout << "Желаете повторить или выйти? Y/n \n";
	char c = _getch();
	if (c =='n')
	{
		administratorMenu(0);
	}
}
//функция вывода списка пользователей
void viewDataUser(int countUser, string nameInputFile) {

		AuthorizationSystem* A = new AuthorizationSystem[countUser];
		readFromFile(A, nameInputFile);

		for (int i = 0; i < countUser; i++)
		{
			cout << "Пользователь №" << i + 1 << " :\n";
			A[i].Print();
		}

	_getch();
	administratorMenu(0);
}



//запись в файл данных абонента
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
		cout << "Ошибка открытия файла \"OutputApartment.txt\".\n";
	}
	fout.close();
}
//чтение из файла данных абонента
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


//добовление абонента
void addData(int countSubcsribe, string nameInputFile, int stateMenu) {


	string Surname, Name, Patronymic;
	Phone ph;

	regex phone("[+](375)[0-9]{2}[0-9]{7}");
	regex year("[0-9]{4}");
	regex text("^[а-яА-ЯёЁa-zA-Z]+$");

	int setType;
	int NewCountSubscribeOwner = countSubcsribe + 1;

	SubscribeOwner *S1 = new SubscribeOwner[NewCountSubscribeOwner];
	readFromFileSubscribeOwner(S1, nameInputFile);

	bool isValueName = false;

	cin.ignore(32767, '\n');
	do
	{
		isValueName = false;
		cout << "Введите фамилию: ";
		getline(cin,Surname);
		if (Surname == "")
		{
			cout << "Строка неможет быть пустой\n";
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
				cout << "ФИО может содерать только знаки кирилицы и/или знаки латинского алфавита  \n";
				isValueName = true;
			}
		}
	} while (isValueName != false);

	do
	{
		isValueName = false;
		cout << "Введите имя: ";
		getline(cin, Name);
		if (Name == "")
		{
			cout << "Строка неможет быть пустой\n";
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
				cout << "ФИО может содерать только знаки кирилицы и/или знаки латинского алфавита  \n";
				isValueName = true;
			}
		}
	} while (isValueName != false);

	do
	{
		isValueName = false;
		cout << "Введите отчество: ";
		getline(cin, Patronymic);
		if (Patronymic == "")
		{
			cout << "Строка неможет быть пустой\n";
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
				cout << "ФИО может содерать только знаки кирилицы и/или знаки латинского алфавита  \n";
				isValueName = true;
			}
		}

	} while (isValueName != false);

	do
	{
		isValueName = false;
		cout << "Введите номер телефона: ";
		getline(cin, ph.NumberPhone);
		if (ph.NumberPhone == "")
		{
			cout << "Строка неможет быть пустой\n";
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
				cout << "Номер телефона доолен быть в формате +375XXxxxxxxx \n";
				isValueName = true;
			}
		}
	
	} while (isValueName != false);

	do
	{
		isValueName = false;
		cout << "Год подключения:\n";
		getline(cin, ph.ConnectYear);
		if (ph.ConnectYear == "")
		{
			cout << "Строка неможет быть пустой\n";
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
				cout << "Год должен быть в формате ХХХХ \n";
				isValueName = true;
			}
		}

	} while (isValueName != false);



        cout << "Текущий тарифный план: \n"
			<< "(1):Любимый  (2):Макси  (3):Ультра  (4):Абсолют\n";

	
		 
		 do {

			 while (!(cin >> setType) || (cin.peek() != '\n')) {

				 cin.clear();

				 while (cin.get() != '\n');
				 cout << "Ошибка ввода, введен не верный тип данных! Повторите попытку ввода" << endl;
			 }

			 isValueName = false;
			 if (setType >= 1 && setType <= 4)
			 {
				 isValueName = false;
				 switch (setType) {
				 case TariffType::Likes:
					 ph.TariffPlan = "Любимый";
					 break;
				 case TariffType::Maxi:
					 ph.TariffPlan = "Макси";
					 break;
				 case TariffType::Ultra:
					 ph.TariffPlan = "Ультра";
					 break;
				 case TariffType::Absolut:
					 ph.TariffPlan = "Абсолют";
					 break;
				 }
			 }
			 else
			 {
				 isValueName = true;
				 cout << "Тарифоного пплана с кодом:" << setType << "не существует\n";
			 }

		 } while (isValueName != false);


	

	    S1[NewCountSubscribeOwner - 1].SetParametrs(Surname, Name, Patronymic, ph);
		writeInFileInputSubscribeOwner(NewCountSubscribeOwner, nameInputFile, S1);
		cout << "Абонент успешно добавлен\n";
		_getch();
	    viewMenu(stateMenu);
}
//изменение данных абонента
void alterData(int countSubcsribe, string nameInputFile, int stateMenu) {
	system("cls");

	string Surname, Name, Patronymic;
	Phone P;
	int altIndex;

	SubscribeOwner *S1 = new SubscribeOwner[countSubcsribe];

	readFromFileSubscribeOwner(S1, nameInputFile);

	cout << "Введите ФИО абонента которого нужно изменить: ";
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

	cout << "Введите новое ФИО абонента:";
	cin >> Surname >> Name >> Patronymic;
	cout << "Новый номер телефона: ";
	cin >> P.NumberPhone;
	cout << "Год подключения: ";
	cin >> P.ConnectYear;
	cout << "Тарифный план: ";
	cin >> P.TariffPlan;

	S1[altIndex].SetParametrs(Surname, Name, Patronymic, P);
	writeInFileInputSubscribeOwner(countSubcsribe, nameInputFile, S1);
	cout << "Данные абонента успешно изменены\n";
	_getch();

	viewMenu(stateMenu);
}
//удаление абонента
void deleteData(int countSubcsribe, string nameInputFile, int stateMenu) {

	string Surname, Name, Patronymic;
	Phone P;
	int delIndex;

	SubscribeOwner *S1 = new SubscribeOwner[countSubcsribe];

	readFromFileSubscribeOwner(S1, nameInputFile);

	cout << "Введите ФИО: ";
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

	cout << "Абонент успешно удален\n";
	_getch();

	viewMenu(stateMenu);

}
//вывод списка абонентов
void viewData(int countSubcsribe, string nameInputFile, int stateMenu) {

		countSubcsribe = countFromFile(nameInputFile);
		SubscribeOwner *S = new SubscribeOwner[countSubcsribe];
		readFromFileSubscribeOwner(S, nameInputFile);

		for (int i = 0; i < countSubcsribe; i++)
		{
			cout << "Абонент №" << i + 1 << " :\n";
			S[i].Print();
			cout << "_______________________________\n";
		}

	_getch();
	viewMenu(stateMenu);
}


//меню режима администратора
void administratorMenu(int st) {
	cout << "МЕНЮ АДМИНИСТРАТОРА\n"
		<< "  (0) Закрыть программу.\n"
		<< "  (1) Перейти к форме входа.\n"
		<< " РАБОТА С ДАННЫМИ ПОЛЬЗОВАТЕЛЕЙ\n"
		<< "  (2) Добовление пользователя\n"
		<< "  (3) Удаление пользователя\n"
		<< "  (4) Изменение данных пользователя\n"
		<< "  (5) Вывод информации\n"
		<< " РАБОТА С ДАННЫМИ АБОНЕНТОВ\n"
		<< "  (6) Добовление данных\n"
		<< "  (7) Удаление данных\n"
		<< "  (8) Изменение данных\n"
		<< "  (9) Вывод информации\n"
		<< "  (10) Сортировка (3 вида)\n"
		<< "  (11) Поиск (3 вида)\n";
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

//меню режима пользователя
void userMenu(int st) {
	cout << "МЕНЮ\n"
		<< " (0) Закрыть программу.\n"
		<< " (1) Перейти к форме входа.\n"
		<< " (2) Вывод информации о абонентах\n"
		<< " (3) Сортировка (4 вида)\n"
		<< " (4) Поиск (3 вида)\n";
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

// функция переключения режима
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
		cout << " Добро пожаловать в систему " << A[i].GetLogin() << "(" << A[i].GetStatus(A[i].GetType()) << ")" << "для продолжения нажимте любую клавишу...\n";
		_getch();
		mainMenu(A[i].GetType());
	}
	else {
		cout << "Произошла ошибка ввода, имя пользователя или пароль не верны!\n";
		cout << "Желаете повторить или выйти? Y/n \n";
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

//функция авторизации
void signToApp() {
	
	char c;
	string tLogin = "", tPassword = "";
	int index = 0;

	int NewCountUserData = countFromFile(InputUserdata);

	AuthorizationSystem *A = new AuthorizationSystem[NewCountUserData];

	readFromFile(A, InputUserdata);

	cout << "Логин: " << "";
	cin >> tLogin; cout << "\n";
	cout << "Пароль: " << "";
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
//функция очистки консоли
void clear() {
	system("cls");
}

//инициализация данных при первом входе
void dataUserInizialization(int countUser, string nameInputFile) {
	cout << "\nПервый вход в программу | Создание администратора" << "\n";
	int count = 0;
	Users us;
	string tmpPassword;
	int NewCountSubscribeOwner = countUser + 1;


	AuthorizationSystem *A1 = new AuthorizationSystem[NewCountSubscribeOwner];

	readFromFile(A1, nameInputFile);

	cout << "Введите логин : ";
	cin >> us.login;
	cout << "Введите пароль: ";
	cin >> us.password;
	cout << "Потвердите пароль: ";
	cin >> tmpPassword;


	if (tmpPassword == us.password)
	{
		cout << "Создание файла учетных записей ... " << "\n";
		A1[NewCountSubscribeOwner - 1].SetParametrs(us.login, us.password, 0);
		writeInFile(NewCountSubscribeOwner, nameInputFile, A1);
	}
	else
	{
		count++;
		cout << "Желаете повторить или выйти? Y/n";
		char c = _getch();
		if (count != 0)
		{
			clear();
		}
		c == 'y' ? dataUserInizialization(countUser, nameInputFile) : c == 'n' ? exit(0) : exit(0);

	}
	delete[] A1;
}


//инициализация данных если это необходимо с проверкой существования файла пользователй 
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
		cout << "Файл учетных записей существует " << "\n";

		if (countAdmin > 0)
		{
			cout << "Администратор системы существует " << "\n";
		}
		else
		{
			cout << "Администратора системы не существует " << "\n";
			cout << "Переход к системе создания администратора " << "\n";
			dataUserInizialization(count, nameFile);
		}
		uout.close();
	}
	else {
		
		dataUserInizialization(count, nameFile);

	}
}


//точка входа
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
