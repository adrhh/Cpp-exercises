#ifndef REZERWACJA_H_
#define REZERWACJA_H_

#include "seans.h"
#include "klient.h"

class Rezerwacja
{
private:
	unsigned int rezerwacja_id;
	unsigned int seans_id;
	bool oplacona;
	const Seans*  seans_ptr;
	static unsigned int counter;
public:
	Rezerwacja() = default;
	Rezerwacja(unsigned int sid, bool op = false);
	void set_id(unsigned int id);
	void set_seans_id(unsigned int id);
	void set_seans(const Seans* se);
	void set_oplacona(bool czy_oplacona);
	static void set_counter(unsigned int count);
	const Seans*		get_seans()		const;
	unsigned int		get_seans_id()	const;
	unsigned int		get_id()		const;
	bool				get_oplacona()  const;
};

class Rezerwacje
{
private:
	unsigned int aa_rezerwacje_id;
	unsigned int rezerwacja_id;
	unsigned int klient_id;
	const Klient* ptr_to_klient;
	const Rezerwacja* ptr_to_rezerwacja;
	
	static unsigned int counter;
public:
	Rezerwacje() = default;
	Rezerwacje(const Klient* kl_ptr, const Rezerwacja* rz_ptr);
	void set_rezerwacja_id(unsigned int id);
	void set_klient_id(unsigned int id);
	void set_id(unsigned int id);
	void set_klient(const Klient* kl_ptr);
	void set_rezerwacja(const Rezerwacja* rz_ptr);
	static void set_counter(unsigned int count);
	unsigned int get_id()				const;
	unsigned int get_klient_id()		const;
	unsigned int get_rezerwacja_id()	const;
	const Klient* get_klient()			const;
	const Rezerwacja* get_rezerwacja()	const;
};

#endif // !REZERWACJA_H_
