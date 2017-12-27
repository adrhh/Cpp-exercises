#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::tolower;



int main()
{
	//get word list from file
	string fname = "test.txt";
	std::ifstream file;
	file.open(fname.c_str(), std::fstream::in);
	if (!file.is_open())
		exit(EXIT_FAILURE);
	string temp;
	vector<string> wordlist;
	while (file >> temp)
		wordlist.push_back(temp);
	file.close();
	int wsize = wordlist.size();

	srand(time(0));
	char play;
	cout << "czy chcesz zagrac w gre <t/n> ?" << endl;
	cin >> play;
	play = tolower(play);
	while (play == 't')
	{
		string target = wordlist[rand() % wsize];
		int length = target.length();
		string attemp(length, '-');
		string badchars;
		int guesess = 6;
		cout << "zagdnij slowo, ma ono " << length << " liter" << endl;
		cout << "Twoje slowo: " << attemp << endl;
		while (guesess > 0 && attemp != target)
		{
			char letter;
			cout << "zgadnij litere: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attemp.find(letter) != string::npos)
			{
				cout << "ta litera juz byla wybierana" << endl;
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "nie ma takiej litery" << endl;
				guesess--;
				badchars += letter;
			}
			else
			{
				cout << "poprawna litera" << endl;
				attemp[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attemp[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Twoje slowo: " << attemp << endl;
			if (attemp != target)
			{
				if (badchars.length() > 0)
					cout << "nieporawne litery: " << badchars << endl;
				cout << "ilosc zyc: " << guesess << endl;
			}
		}
		if (guesess > 0)
			cout << "to juz cale slowo" << endl;
		else
			cout << "niestety szukane slowo to: " << target << endl;

		cout << "czy chesz zagrac jeszcze raz <t/n>" << endl;
		cin >> play;
		play = tolower(play);
	}


	return 0;
}
