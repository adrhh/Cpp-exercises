/*The following is a program skeleton:
#include <iostream>
using namespace std;
#include <cstring>      // for strlen(), strcpy()
struct stringy {
char * str;        // points to a string
int ct;            // length of string (not counting '\0')
};
// prototypes for set(), show(), and show() go here
int main()
{
stringy beany;
char testing[] = "Reality isn't what it used to be.";
set(beany, testing);    // first argument is a reference,
// allocates space to hold copy of testing,
// sets str member of beany to point to the
// new block, copies testing to new block,
// and sets ct member of beany446 Chapter 8 Adventures in Functions
show(beany);      // prints member string once
show(beany, 2);   // prints member string twice
testing[0] = 'D';
testing[1] = 'u';
show(testing);    // prints testing string once
show(testing, 3); // prints testing string thrice
show("Done!");
return 0;
}
Complete this skeleton by providing the described functions and prototypes. Note
that there should be two  show() functions, each using default arguments. Use
const arguments when appropriate. Note that  set() should use  new to allocate
sufficient space to hold the designated string.The techniques used here are similar
to those used in designing and implementing classes. (You might have to alter the
header filenames and delete the  using directive, depending on your compiler.)*/

#include <iostream>
using namespace std;
#include <cstring>      
struct stringy {
	char * str;        
	int ct;            
};

void set(stringy &s, const char* strs);
void show(const stringy &s, int n = 1);
void show(const char* str, int n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);    

	show(beany);     
	show(beany, 2);   
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);    
	show(testing, 3); 
	show("Done!");
	return 0;
}

void set(stringy &s,const char* strs)
{
	int size = sizeof(strs);
	s.str = new char[size+1];
	strcpy(s.str, strs);
	s.ct = size;
}

void show(const stringy &s, int n)
{
	for (int i = 1; i <= n; i++)
		cout << s.str << endl;
}

void show(const char* strs, int n)
{
	for (int i = 1; i <= n; i++)
		cout << strs << endl;
}