#include "pch.h"
#include <vector>
#include <algorithm>

TEST(List, ListDodawanieElementu)
{
	List lista;
	const int X = 10;
	lista.insert(X);
	EXPECT_TRUE(lista.contains(X));
}

TEST(List, ListDodawanieDwaRazyElementu)
{
	List lista;
	const int X = 10;
	lista.insert(X);
	lista.insert(X);
	EXPECT_EQ(2, lista.elemCount());

	const std::string STR = "[10,10]";
	EXPECT_EQ(STR, lista.toString());
}

TEST(List, OdwracanieListy)
{
	List l1, l2;
	const int SIZE = 10;
	for (int i = 0; i < SIZE; i++)
	{
		l1.insert(i);
		l2.insert(i);
	}
	l2.reverse();

	std::string l1str = l1.toString();
	std::string l2str = l2.toString();

	//toString dodaje nawiasy [] 
	reverse(l2str.begin() + 1, l2str.end() - 1);

	EXPECT_EQ(l1str, l2str);
}

TEST(List, OdracanieListyPustej)
{
	List lista;
	EXPECT_NO_THROW(lista.reverse());
}