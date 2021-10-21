#pragma once

#include <vector>

#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <iterator>

using std::vector;

template <typename T>
T testFloor(T val)
{ return std::floor(val); }

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

	template <typename O>
	Vector(const Vector<Dim, O> &vec)
		:	container_t(vec.begin(), vec.end())
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

	Vector &operator+=(const Vector &vec)
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

	Vector &operator-=(const Vector &vec)
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

	Vector &operator*=(const Vector &vec)
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

	Vector &operator/=(const Vector &vec)
	{
		std::transform(
			container_t::begin(), container_t::end(),
			vec.begin(),
			container_t::begin(),
			std::divides<T>()
		);
		return *this;
	}


	Vector &operator%=(const Vector &vec)
	{
		std::transform(
			container_t::begin(), container_t::end(),
			vec.begin(),
			container_t::begin(),
			std::modulus<T>()
		);
		return *this;
	}

	constexpr T	sum() const
	{ return std::accumulate(container_t::begin(), container_t::end(), T()); }

	Vector	floor() const
	{
		Vector<Dim, T> tmp;

		std::transform(
			container_t::begin(), container_t::end(),
			tmp.begin(),
			testFloor<T>
		);

		return tmp;
	}
};

template <unsigned Dim, typename T, typename O>
auto	add(const Vector<Dim, T> &a, const Vector<Dim, O> &b, std::false_type)
{
	using C = typename std::common_type<T, O>::type;

	Vector<Dim, C>	tmp;

	std::transform(a.begin(), a.end(), b.begin(), tmp.begin(), std::plus<C>());

	return tmp;
}

template <unsigned Dim, typename T, typename S>
auto	add(const Vector<Dim, T> &vec, S scalar, std::true_type)
{
	using C = typename std::common_type<T, S>::type;

	Vector<Dim, C>	tmp;

	std::transform(vec.begin(), vec.end(), vec.begin(), tmp.begin(),
		std::bind(std::plus<C>(), std::placeholders::_1, scalar));

	return tmp;
}

template <unsigned Dim, typename T, typename O>
auto	sub(const Vector<Dim, T> &a, const Vector<Dim, O> &b, std::false_type)
{
	using C = typename std::common_type<T, O>::type;

	Vector<Dim, C>	tmp;

	std::transform(a.begin(), a.end(), b.begin(), tmp.begin(), std::minus<C>());

	return tmp;
}

template <unsigned Dim, typename T, typename S>
auto	sub(const Vector<Dim, T> &vec, S scalar, std::true_type)
{
	using C = typename std::common_type<T, S>::type;

	Vector<Dim, C>	tmp;

	std::transform(vec.begin(), vec.end(), vec.begin(), tmp.begin(),
		std::bind(std::minus<C>(), std::placeholders::_1, scalar));

	return tmp;
}

template <unsigned Dim, typename T, typename O>
auto	mul(const Vector<Dim, T> &a, const Vector<Dim, O> &b, std::false_type)
{
	using C = typename std::common_type<T, O>::type;

	Vector<Dim, C>	tmp;

	std::transform(a.begin(), a.end(), b.begin(), tmp.begin(), std::multiplies<C>());

	return tmp;
}

template <unsigned Dim, typename T, typename S>
auto	mul(const Vector<Dim, T> &vec, S scalar, std::true_type)
{
	using C = typename std::common_type<T, S>::type;

	Vector<Dim, C>	tmp;

	std::transform(vec.begin(), vec.end(), vec.begin(), tmp.begin(),
		std::bind(std::multiplies<C>(), std::placeholders::_1, scalar));

	return tmp;
}

template <unsigned Dim, typename T, typename O>
auto	div(const Vector<Dim, T> &a, const Vector<Dim, O> &b, std::false_type)
{
	using C = typename std::common_type<T, O>::type;

	Vector<Dim, C>	tmp;

	std::transform(a.begin(), a.end(), b.begin(), tmp.begin(), std::divides<C>());

	return tmp;
}

template <unsigned Dim, typename T, typename S>
auto	div(const Vector<Dim, T> &vec, S scalar, std::true_type)
{
	using C = typename std::common_type<T, S>::type;

	Vector<Dim, C>	tmp;

	std::transform(vec.begin(), vec.end(), vec.begin(), tmp.begin(),
		std::bind(std::divides<C>(), std::placeholders::_1, scalar));

	return tmp;
}

template <unsigned Dim, typename T, typename O>
auto	mod(const Vector<Dim, T> &a, const Vector<Dim, O> &b, std::false_type)
{
	using C = typename std::common_type<T, O>::type;

	Vector<Dim, C>	tmp;

	std::transform(a.begin(), a.end(), b.begin(), tmp.begin(), std::modulus<C>());

	return tmp;
}

template <unsigned Dim, typename T, typename S>
Vector<Dim, T>	mod(const Vector<Dim, T> &vec, S scalar, std::true_type)
{
	using C = typename std::common_type<T, S>::type;

	Vector<Dim, C>	tmp;

	std::transform(vec.begin(), vec.end(), vec.begin(), tmp.begin(),
		std::bind(std::modulus<C>(), std::placeholders::_1, scalar));

	return tmp;
}

template <unsigned Dim, typename T, typename O>
Vector<Dim, T>	operator+(const Vector<Dim, T> &vec, const O &other)
{ return add(vec, other, std::is_arithmetic<O>()); }

template <unsigned Dim, typename T, typename O>
Vector<Dim, T>	operator-(const Vector<Dim, T> &vec, const O &other)
{ return sub(vec, other, std::is_arithmetic<O>()); }

template <unsigned Dim, typename T, typename O>
Vector<Dim, T>	operator*(const Vector<Dim, T> &vec, const O &other)
{ return mul(vec, other, std::is_arithmetic<O>()); }

template <unsigned Dim, typename T, typename O>
Vector<Dim, T>	operator/(const Vector<Dim, T> &vec, const O &other)
{ return div(vec, other, std::is_arithmetic<O>()); }

template <unsigned Dim, typename T, typename O>
Vector<Dim, T>	operator%(const Vector<Dim, T> &vec, const O &other)
{ return mod(vec, other, std::is_arithmetic<O>()); }

template <unsigned Dim, typename T>
Vector<Dim, T>	operator-(const Vector<Dim, T> &vec)
{
	Vector<Dim, T>	tmp;

	std::transform(vec.begin(), vec.end(), tmp.begin(), std::negate());

	return tmp;
}

template <unsigned Dim, typename T>
Vector<Dim, T>	operator&(const Vector<Dim, T> &vec, T value)
{
	Vector<Dim, T>	tmp;

	std::transform
	(
		vec.begin(),
		vec.end(),
		tmp.begin(),
		std::bind(std::bit_and(), std::placeholders::_1, value)
	);

	return tmp;
}

template <unsigned Dim, typename T>
std::ostream&	operator<<(std::ostream &os, const Vector<Dim, T> &vec)
{
	os << "{ ";

	std::copy(vec.begin(), vec.end(),
		std::ostream_iterator<T>(os, ", "));

	os << " }, ";

	return os;
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
