#include <iostream>
#include <vector>
#include "person.h"
#include "event.h"
#include "todb.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void main_menu();
void e_menu();
void e_fun(int i);    //event function
void a_menu();
void a_event(int i);   //add event
void a_shop(int i);   //add shoping
void a_met(int i);	  //add meeting

vector<Person> p_list;

int main()
{
	//print
	main_menu();

	char ch;
	cin >> ch;
	//clear buffor
	cin.clear();
	cin.sync();

	while (ch != 'q')
	{
		switch (ch)
		{
		case 'd':
			{
			string temp_n, temp_s;
			cout << "podaj imie i nazwisko" << endl;
			cin >> temp_n >> temp_s;
			p_list.push_back(Person(temp_n, temp_s));
			break;
			}
		case 'p':
			{
			if (p_list.size())
				for (auto i : p_list)
					cout << i << endl;
			else
				cout << "brak ludzi" << endl;
			break;
			}
		case 'e':
			if (p_list.size())
			{
				for (unsigned int i = 0; i < p_list.size(); i++)
					cout << i << " :" << p_list[i].get_name() << endl;
				cout << "wybierz numer osoby" << endl;

				unsigned int choice;
				cin >> choice;
				cin.clear();
				cin.sync();
				while (choice < 0 && choice > p_list.size())
				{
					cout << "nieporawny wybor wpisz liczbe od 0 do" << p_list.size() - 1 << endl;
					cin >> choice;
					cin.clear();
					cin.sync();
				}

				e_fun(choice);

			}
			else
				cout << "brak ludzi" << endl;
			break;
		default:
			cout << "zly wybor" << endl;
		}

		main_menu();
		cin >> ch;
		//clear buffor
		cin.clear();
		cin.sync();
	}

	/* --------------test---------------
	vector<Event*> list(3);
	list[0] = new Meeting;
	list[1] = new Meeting("test");
	list[2] = new Shopping;
	list[2]->add_item("ziemniaki", 10, 2.5);
	list[2]->add_item("papryka", 2, 10);
	list[0]->set_time(2016, 16, 10);
	for (auto e : list)
	{	
		e->show();
		cout << "\n--------------" << endl;
	}
	cout << list[1]->get_stime() << endl;

	Person test;
	test.add_event(list[0]);
	test.add_event(list[1]);
	test.show_events();
	*/
	
	try
	{
		Todb test1;
		test1.open_db("test.db");
		test1.make_columns();
		for(auto i: p_list)
			test1.add(i);
		
	}
	catch (Todb::db_err& e)
	{
		cout << e.what() << " : " << e.info() << endl;
	}

	return 0;
}

void main_menu()
{
	cout << "wybierz:" << endl
		<< "d - doaj osobe" << endl
		<< "p - pokaz liste osob" << endl
		<< "e - edytuj osobe" << endl
		<< "q - zakoncz" << endl;
}

void e_menu()
{
	cout << "wybierz:" << endl
		<< "d - dodaj zdarzenie" << endl
		<< "p - pokaz liste zdarze" << endl
		<< "q - wyjdz z menu" << endl;
}

void e_fun(int i)
{
	e_menu();
	char ch;
	cin >> ch;
	//clear buffor
	cin.clear();
	cin.sync();
	switch (ch)
	{
	case 'p':
		p_list[i].show_events();
		break;
	case 'd':
		a_event(i);
		break;
	default:
		cout << "zly wybor" << endl;
	}
}

void a_event(int i)
{
	a_menu();
	char ch;
	cin >> ch;
	//clear buffor
	cin.clear();
	cin.sync();
	switch (ch)
	{
	case 'z':
		a_shop(i);
		break;
	case 's':
		a_met(i);
		break;
	default:
		cout << "zly wybor" << endl;
	}
}

void a_menu()
{
	cout << "wybierz:" << endl
		<< "z - zakupy" << endl
		<< "s - spotkanie" << endl
		<< "q - wyjdz z menu" << endl;
}

void a_shop(int i)
{
	Shopping* temp = new Shopping();
	int temp_y, temp_m, temp_d, temp_h;
	cout << "podaj date:" << endl;

	cout << "rok:" << endl;
	cin >> temp_y;
	cin.clear();
	cin.sync();

	cout << "miesiac:" << endl;
	cin >> temp_m;
	cin.clear();
	cin.sync();

	cout << "dzien:" << endl;
	cin >> temp_d;
	cin.clear();
	cin.sync();

	cout << "godzine:" << endl;
	cin >> temp_h;
	cin.clear();
	cin.sync();

	temp->set_time(temp_y, temp_m, temp_d, temp_h);

	string temp_s;
	int temp_qu;
	float temp_pr;

	cout << "dodaj przemidot do listy zakupow (q-zakoncz):" << endl;
	cin >> temp_s;
	while (temp_s != "q")
	{
		cout << "podaj ilosc:" << endl;
		cin >> temp_qu;
		cin.clear();
		cin.sync();

		cout << "podaj cene:" << endl;
		cin >> temp_pr;
		cin.clear();
		cin.sync();

		temp->add_item(temp_s, temp_qu, temp_pr);

		cout << "dodaj koljeny przemidot do listy zakupow (q-zakoncz):" << endl;
		cin >> temp_s;
	}

	p_list[i].add_event(temp);
}

void a_met(int i)
{
	
	int temp_y, temp_m, temp_d, temp_h;
	cout << "podaj date:" << endl;

	cout << "rok:" << endl;
	cin >> temp_y;
	cin.clear();
	cin.sync();

	cout << "miesiac:" << endl;
	cin >> temp_m;
	cin.clear();
	cin.sync();

	cout << "dzien:" << endl;
	cin >> temp_d;
	cin.clear();
	cin.sync();

	cout << "godzine:" << endl;
	cin >> temp_h;
	cin.clear();
	cin.sync();

	string temp_plac;
	cout << "podaj miejsce:" << endl;
	cin >> temp_plac;

	Meeting* temp = new Meeting(temp_plac);
	temp->set_time(temp_y, temp_m, temp_d, temp_h);

	p_list[i].add_event(temp);
}