/*Write a program that reads input a word at a time until a lone  q is entered.The
program should then report the number of words that began with vowels, the num-
ber that began with consonants, and the number that fit neither of those categories.
One approach is to use  isalpha() to discriminate between words beginning with
letters and those that don’t and then use an  if or switch statement to further iden-
tify those passing the  isalpha() test that begin with vowels.A sample run might
look like this:
Enter words (q to quit):
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q
5 words beginning with vowels
4 words beginning with consonants
2 others*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	unsigned int vowels = 0;
	unsigned int cons = 0;
	unsigned int others = 0;
	unsigned int i = 0;
	string word, words;
	char ch;

	cout << "Enter words (q to quit):" << endl;
	cin >> word;
	ch = word[0];
	words += word;

	while (word != "q")
	{
		if (isalpha(ch))
		{
			ch = toupper(ch);
			switch (ch)
			{
			case'A':
			case'E':
			case'I':
			case 'O':
			case 'U':
				vowels++;
				break;
			default:
				cons++;
			}
		}
		else
			others++;

		cin >> word;
		ch = word[0];
		if(word != "q")
			words += ' ' + word;
	}

	cout << "W zdaniu \"" << words << "\"" << endl;
	cout << vowels << " wyrazow zaczyna sie od samgloski" << endl;
	cout << cons << " wyrazow zaczyna sie od wspolgloski" << endl;
	cout << others << " wyrazow zaczyna sie od pozsotalych znakow" << endl;

	return 0;
}