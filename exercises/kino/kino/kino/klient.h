#ifndef KLIENT_H_
#define KLIENT_H_

#include <iostream>
#include <string>

typedef std::string str;

class Klient
{
private:
	str imie;
	str nazwisko;
	unsigned int klient_id;
	static unsigned int counter;
public:
	Klient() = default;
	Klient(const str& im, const str& nz);
	str get_imie()			const;
	str get_nazwisko()		const;
	unsigned int get_id()	const;
	void set_imie(const str& s);
	void set_nazwisko(const str& s);
	void set_id(unsigned int id);
	static void set_counter(unsigned int count);
};

#endif // !KLIENT_H_
