#include "menu.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void Menu::show_menu() const
{
	unsigned int i = 0;
	for (auto p : actual_node->nodes)
		cout << i++ << ": " << p->node_name << endl;
}

int Menu::pick()
{
	unsigned int max = actual_node->nodes.size();
	int pick;
	cin >> pick;
	if (pick >= 0 && pick < max)
		return pick;
	else
		return NOT_IN_RANGE;
}

void Menu::menu_loop()
{
	actual_node = &nl[glowne];
	while (true)
	{
		show_menu();
		pick();
	}
}