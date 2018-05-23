#include "database.h"

bool DataBase::isObserver(Employee& emp) const
{
	//CEO and Manager
	CEO* ceo = dynamic_cast<CEO*>(&emp);
	Manager* manager = dynamic_cast<Manager*>(&emp);

	if (ceo != nullptr || manager != nullptr)
		return true;
	else
		return false;
}

void DataBase::addEmployee(Employee& emp)
{
	empsArray.push_back(emp);
	if (isObserver(emp))
		addObsever(emp);
	infromAllObservers();
}

void DataBase::addObsever(DbObserver& ob)
{
	DataBase::observersArray.push_back(&ob);
}

void DataBase::infromAllObservers()
{
	for (auto observator : observersArray)
		observator->actualization();
}