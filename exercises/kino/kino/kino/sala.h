#ifndef SALA_H_
#define SALA_H_

class Sala
{
public:
	Sala() = default;
	Sala(unsigned int wielkosc);
	unsigned int get_wielkosc() const;
	unsigned int get_id()		const;
	void set_wielkosc(unsigned int wielkosc);
	void set_id(unsigned int id);
	static void set_counter(unsigned int count);
private:
	static unsigned int counter;
	unsigned int wielkosc_sali;
	unsigned int id_sali;
};

#endif // !1
