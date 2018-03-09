#ifndef STATIC_H_
#define STATIC_H_

#include <string>

using std::string;

class Client
{
public:
	Client(string name) : Name(name), ID(SavedId++) {}
	static int getSavedID() { return SavedId; }
	string getName() const { return Name; }
	int getID() const { return ID; }
private:
	string Name;
	int ID;
	static int SavedId;
};

#endif // !STATIC_H_
