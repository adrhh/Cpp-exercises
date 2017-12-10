#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string first_name = "";
	string friend_name = "";
	char friend_sex = ' ';
	int age = 0;

	cout << "Podaj imie:" << endl;
	cin >> first_name;
	cout << "Podja imie przyjaciela" << endl;
	cin >> friend_name;
	cout << "Podaj jego plec:" << endl;
	while (cin.get() != '\n')
		continue;
	while (cin.get(friend_sex) && !(friend_sex == 'k' || friend_sex == 'm'))
	{
		cout << "wpisz k lub m" << endl;
		while (cin.get() != '\n')
			continue;
	}
	cout << "Podaj jego wiek" << endl;
	cin >> age;

	string k_or_m = (friend_sex == 'k') ? "ja" : "go";

	cout << "Drogi " << first_name << " co u Ciebie ?" << endl
		<< "Ponoc widzales sie z " << friend_name << endl
		<< "Jesli " << k_or_m << " zobaczysz popros go o nr telefonu" << endl;

	if (age < 0 || age > 110)
		cout << "Chyba zartujesz z wiekiem" << endl;
	else
	{
		if (age == 12)
			cout << "Za rok bedziesz miec " << age + 1 << " lat" << endl;
		else if (age == 17)
			cout << "Za rok mozesz glosowac." << endl;
		else if (age > 70)
			cout << "Zycze milego czasu na emeryturze." << endl;
		else
			cout << "Podobna miales urodziny i masz " << age << " lat" << endl;
	}

	cout << endl << endl << "Pozdrawiam!" << endl;

	return 0;
}