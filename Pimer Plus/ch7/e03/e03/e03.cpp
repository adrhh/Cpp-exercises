/* Here is a structure declaration:
struct box
{
char maker[40];
float height;
float width;
float length;
float volume;
};
a. Write a function that passes a  box structure by value and that displays the
value of each member.
b. Write a function that passes the address of a  box structure and that sets the
volume member to the product of the other three dimensions.
c. Write a simple program that uses these two functions.*/

#include <iostream>

using namespace std;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_box(box);
void volume_box(box*);

int main()
{
	box test_box =
	{	"Asd",
		100,
		20,
		5,
		0,
	};

	show_box(test_box);
	volume_box(&test_box);
	show_box(test_box);

	return 0;
}

void show_box(box s)
{
	cout << "Producent: " << s.maker << endl;
	cout << "Wysokosc: " << s.height << endl;
	cout << "Szerokosc: " << s.width << endl;
	cout << "Dlugosc: " << s.length << endl;
	if (s.volume)
		cout << "Objetosc: " << s.volume << endl;
	else
		cout << "Objetosc nie obliczona." << endl;
}

void volume_box(box* s)
{ 
	if ((s->height && s->length) && s->width)
		s->volume = s->height * s->length * s->length;
	else
		cout << "Nie pelne dane" << endl;
};