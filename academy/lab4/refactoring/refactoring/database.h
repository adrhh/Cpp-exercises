#ifndef DATABASE_H_
#define DATABASE_H_

#include <vector>
#include "pch.h"

class Subject
{
public:
	void addObsever(DbObserver& ob) = 0;
	void infromAllObservers() const = 0;
};

class DataBase : public Subject
{
private:
	std::vector<Employee> empsArray;
	std::vector<DbObserver*> observersArray;
	DataBase();

	bool isObserver(Employee& emp) const;
public:
	static DataBase& getInstance()
	{
		static DataBase db;
		return db;
	}
	void addEmployee(Employee& emp);
	void addObsever(DbObserver& ob);
	void infromAllObservers();
};

#endif // !DATABASE_H_
