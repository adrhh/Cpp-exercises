#ifndef ARR_H_
#define ARR_H_

#include <stdexcept>
#include <string>

template <typename T, int n>
class Arr
{
private:
	T items[n];
public:
	Arr() {};
	~Arr() {};
	explicit Arr(const T& v); //explicit for block convesrion
	virtual T& operator[](int i);
	virtual T operator[](int i) const;

	class index_err : public std::logic_error
	{
	private:
		int index;
	public:
		explicit index_err(int i, const std::string& s = "Blad: nieporawny indeks.");
		int get_index() const { return index; }
		virtual ~index_err() throw() {};
	};
};

template <typename T, int n>
Arr<T, n>::Arr(const T& v)
{
	for (int i = 0; i < n; i++)
		items[i] = v;
}

template <typename T, int n>
T& Arr<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
		throw index_err(i);
	return items[i];
}

template <typename T, int n>
T Arr<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
		throw index_err(i);
	return items[i];
}

template <typename T, int n>
Arr<T, n>::Arr::index_err::index_err(int i, const std::string& s)
	: std::logic_error(s), index(i)
{

}

#endif // !ARR_H_