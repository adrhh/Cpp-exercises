template <class T, class S>
class Pair
{
private:
	T a;
	S b;
public:
	T & first();
	S & second();
	T first() const { return a; };
	S sceond() const { return b; };
	Pair(const T& aval, const S& bval) : a(aval), b(bval) {};
	Pair() {};
};


template <class T, class S>
T& Pair<T, S>::first()
{
	return a;
}

template <class T, class S>
S& Pair<T, S>::second()
{
	return b;
}