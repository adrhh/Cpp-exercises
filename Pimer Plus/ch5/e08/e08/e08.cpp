/* Write a program that uses an array of  char and a loop to read one word at a time
until the word  done is entered.The program should then report the number of
words entered (not counting  done ).A sample run could look like this:
Enter words (to stop, type the word done):
anteater birthday category dumpster
envy finagle geometry done for sure
You entered a total of 7 words.*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const int MAX = 20;
	const char done[5] = "done";
	char word[MAX];
	int counter = 0;

	cout << "Enter words (to stop, type the word done):" << endl;
	cin >> word;
	while (strcmp(done, word))
	{
		cout << "Enter words(to stop, type the word done): "<< endl;
		cin >> word;
		counter++;
	}
	 
	cout << "You entered a total of" << counter <<  "words"<<endl;

	return 0;
}