#pragma once

struct Vector2D
{
	uint	x;
	uint	y;

	Vector2D()
		:	x(0), y(0)
	{ }

	Vector2D(const Vector2D &vec)
		:	x(vec.x), y(vec.y)
	{ }

	Vector2D(uint x, uint y)
		:	x(x), y(y)
	{ }
};

template<typename T>
constexpr T	min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

constexpr Vector2D min(const Vector2D &a, const Vector2D &b)
{
	Vector2D	vec (min(a.x, b.x), min(a.y, b.y));

	return vec;
}
