#include <vector>

#include <functional>
#include <algorithm>

using std::vector;

template <unsigned Dim = 2, typename T = int>
class Vector:	public vector<T>
{
protected:
	typedef vector<T>	container_t;

public:
	static_assert(Dim >= 1, "Vector dimension must be greater than 0!");

	static const unsigned dim = Dim;

	Vector()
		:	container_t(Dim)
	{ }

	Vector(const Vector &vec)
		:	container_t(vec)
	{ }

	Vector(std::initializer_list<T> vals)
		:	container_t { vals }
	{ }

	virtual ~Vector()
	{ }

	Vector	&operator=(const Vector &vec)
	{
		container_t::operator=(vec);
		return *this;
	}

	Vector &operator+=(const Vector  &vec)
	{
		std::transform
		(
			container_t::begin(), container_t::end(),
			vec.begin(),
			container_t::begin(),
			std::plus<T>()
		);
		return *this;
	}

	Vector &operator-=(const Vector  &vec)
	{
		std::transform
		(
			container_t::begin(), container_t::end(),
			vec.begin(),
			container_t::begin(),
			std::minus<T>()
		);
		return *this;
	}

	Vector &operator*=(const Vector  &vec)
	{
		std::transform
		(
			container_t::begin(), container_t::end(),
			vec.begin(),
			container_t::begin(),
			std::multiplies<T>()
		);
		return *this;
	}

	Vector &operator/=(const Vector  &vec)
	{
		std::transform(
			container_t::begin(), container_t::end(),
			vec.begin(),
			container_t::begin(),
			std::divides<T>()
		);
		return *this;
	}


	Vector &operator%=(const Vector  &vec)
	{
		std::transform(
			container_t::begin(), container_t::end(),
			vec.begin(),
			container_t::begin(),
			std::modulus<T>()
		);
		return *this;
	}
};

template <unsigned Dim, typename T>
Vector<Dim, T>	operator+(const Vector<Dim, T> &a, const Vector<Dim, T> &b)
{
	Vector<Dim, T>	tmp;

	std::transform(a.begin(), a.end(), b.begin(), tmp.begin(), std::plus<T>());

	return tmp;
}

template <unsigned Dim, typename T>
Vector<Dim, T>	operator-(const Vector<Dim, T> &a, const Vector<Dim, T> &b)
{
	Vector<Dim, T>	tmp;

	std::transform(a.begin(), a.end(), b.begin(), tmp.begin(), std::minus<T>());

	return tmp;
}

template <unsigned Dim, typename T>
Vector<Dim, T>	operator-(const Vector<Dim, T> &vec)
{
	Vector<Dim, T>	tmp;

	std::transform(vec.begin(), vec.end(), tmp.begin(), std::negate());

	return tmp;
}

template <unsigned Dim, typename T>
Vector<Dim, T>	operator*(const Vector<Dim, T> &a, const Vector<Dim, T> &b)
{
	Vector<Dim, T>	tmp;

	std::transform(a.begin(), a.end(), b.begin(), tmp.begin(), std::multiplies<T>());

	return tmp;
}

template <unsigned Dim, typename T>
Vector<Dim, T>	operator/(const Vector<Dim, T> &a, const Vector<Dim, T> &b)
{
	Vector<Dim, T>	tmp;

	std::transform(a.begin(), a.end(), b.begin(), tmp.begin(), std::divides<T>());

	return tmp;
}

struct	max
{
	template <class T>
	const T	&operator()(const T &a, const T &b) const
	{ return std::max(a, b); }
};

struct	min
{
	template <class T>
	const T	&operator()(const T &a, const T &b) const
	{ return std::min(a, b); }
};

template <unsigned Dim, typename T>
Vector<Dim, T>	clamp(const Vector<Dim, T> &vec,
	const Vector<Dim, T> &minVec, const Vector<Dim, T> &maxVec)
{
	Vector<Dim, T>	tmp;

	std::transform(vec.begin(), vec.end(), minVec.begin(), tmp.begin(), max());
	std::transform(tmp.begin(), tmp.end(), maxVec.begin(), tmp.begin(), min());

	return tmp;
}
