#pragma once

#include <Vector.hpp>
template <typename T = int>
struct Vector2D:	public Vector<2, T>
{
	T	&x;
	T	&y;

	Vector2D()
		:	Vector<2, T>(), x((*this)[0]), y((*this)[1])
	{ }

	~Vector2D()
	{ }

	Vector2D(const Vector<2, T> &vec)
		:	Vector<2, T>(vec), x((*this)[0]), y((*this)[1])
	{ }

	Vector2D(T x, T y)
		:	Vector<2, T> { x, y }, x((*this)[0]), y((*this)[1])
	{ }
};
