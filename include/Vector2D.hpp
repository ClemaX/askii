#pragma once

struct Vector2D
{
	int	x;
	int	y;

	Vector2D()
		:	x(0), y(0)
	{ }

	Vector2D(const Vector2D &vec)
		:	x(vec.x), y(vec.y)
	{ }

	Vector2D(int x, int y)
		:	x(x), y(y)
	{ }

	Vector2D	&operator=(Vector2D const &vec)
	{
		x = vec.x;
		y = vec.y;

		return *this;
	}

	Vector2D	&operator+=(Vector2D const &vec)
	{
		x += vec.x;
		y += vec.y;

		return *this;
	}

	Vector2D	operator-=(Vector2D const &vec) const
	{
		return Vector2D(x + vec.x, y + vec.y);
	}

	Vector2D	operator/(Vector2D const &vec) const
	{
		return Vector2D(x / vec.x, y / vec.y);
	}

	Vector2D	operator*(Vector2D const &vec) const
	{
		return Vector2D(x * vec.x, y * vec.y);
	}

	Vector2D	operator+(Vector2D const &vec) const
	{
		return Vector2D(x + vec.x, y + vec.y);
	}

	Vector2D	operator-(Vector2D const &vec) const
	{
		return Vector2D(x - vec.x, y - vec.y);
	}

	Vector2D	operator*(int scalar) const
	{
		return Vector2D(x * scalar, y * scalar);
	}

	Vector2D	operator/(int scalar) const
	{
		return Vector2D(x / scalar, y / scalar);
	}
};
/*
Vector2D operator+(const Vector2D &a, const Vector2D &b)
{ return Vector2D(a.x + b.x, a.y + b.y); } */

template<typename T>
constexpr const T	&min(const T &a, const T &b)
{ return (a < b ? a : b); }

template<typename T>
constexpr T			&max(T &a, T &b)
{ return (a > b ? a : b); }

Vector2D	min(const Vector2D &a, const Vector2D &b)
{ return Vector2D(min(a.x, b.x), min(a.y, b.y)); }

Vector2D	max(const Vector2D &a, const Vector2D &b)
{ return Vector2D(max(a.x, b.x), max(a.y, b.y)); }
