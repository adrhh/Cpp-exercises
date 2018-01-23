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

int main()
{
	
	//print
	main_menu();

	char ch;
	cin >> ch;
	//clear buffor
	cin.clear();
	cin.sync();

	vector<Person> p_list;

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
	
	try
	{
		Todb test1;
		test1.open_db("test.db");
		test1.make_columns();
		test1.add(test);
		
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
