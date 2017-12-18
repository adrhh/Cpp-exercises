#ifndef ARR_H_
#define ARR_H_

#include <stdexcept>
#include <string>

template <typename T>
class Arr
{
private:
	int size;
	T* items;
	void copy(int max, T* nitems);
public:
	Arr(int n=0)  { items = new T[n]; size = n; }
	~Arr() { delete[] items; }
	explicit Arr(const T& v); //explicit to block convesrion
	virtual T& operator[](int i);
	virtual T operator[](int i) const;
	virtual int get_size() const { return size; }
	virtual void pop_end();
	virtual void push_back(const T& item);
	
	class index_err : public std::logic_error
	{
	private:
		int index;
	public:
		index_err(int i, const std::string& s = "Blad: nieporawny indeks.");
		int get_index() const { return index; }
		virtual ~index_err() throw() {};
	};
	class size_err : public std::logic_error
	{
	public:
		explicit size_err(const std::string& s = "Nie mozna usunac elemntu.");
		virtual ~size_err() throw() {};
	};
};

template <typename T>
Arr<T>::Arr(const T& v)
{
	for (int i = 0; i < n; i++)
		items[i] = v;
}

template <typename T>
T& Arr<T>::operator[](int i)
{
	if (i < 0 || i >= size)
		throw index_err(i);
	return items[i];
}

template <typename T>
T Arr<T>::operator[](int i) const
{
	if (i < 0 || i >= size)
		throw index_err(i);
	return items[i];
}
template <typename T>
void Arr<T>::copy(int max, T* nitems)
{
	for (int i = 0; i < max; i++)
		nitems[i] = items[i];
}
template <typename T>
void Arr<T>::pop_end()
{
	if (size > 1)
	{
		T* temp;
		temp = new T[size - 1];
		copy(size - 1, temp);
		delete[] items;
		items = temp;
		size--;
	}
	else
		throw size_err();
}

template <typename T>
void Arr<T>::push_back(const T& item)
{
	T* temp = new T[size + 1];
	copy(size, temp);
	delete[] items;
	temp[size] = item;
	items = temp;
	size++;
}

template <typename T>
Arr<T>::Arr::index_err::index_err(int i, const std::string& s)
	: std::logic_error(s), index(i)
{
}

template <typename T>
Arr<T>::Arr::size_err::size_err(const std::string& s)
	: std::logic_error(s)
{
}

#endif // !ARR_H_