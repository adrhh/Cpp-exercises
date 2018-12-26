#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <vector>

typedef std::string str;
using std::vector;

class Menu
{

public:
	static const short NOT_IN_RANGE = -1;
	struct Node
	{
		Node* up;
		vector<Node*> nodes;
		str node_name;
	};
	enum lm
	{
		glowne,
			filmy,
				dodaj_film,
				pokaz_filmy,
			sale
	};
	Node nl[100] = 
	{
		{nullptr,	  {&nl[filmy],		 &nl[sale]},			      "glowne"},
		{&nl[glowne], {&nl[pokaz_filmy], &nl[dodaj_film]},			  "filmy"}
	};
private:
	Node* actual_node;
public:
	void show_menu() const;
	void menu_loop();
	int pick();
};


#endif // !MENU_H_
