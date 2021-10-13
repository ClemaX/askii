#pragma once

#include <Vector2D.hpp>
#include <IDrawable.hpp>

#include <iostream>

class ASizedDrawable:	public IDrawable
{
protected:
	Vector2D	dim;

public:
	ASizedDrawable(unsigned width, unsigned height)
		:	dim(width, height)
	{ }

	ASizedDrawable(const Vector2D &dim)
		:	dim(dim)
	{ }

	virtual void	resize(unsigned width, unsigned height)
	{
		dim.x = width;
		dim.y = height;

		std::cout << "resizing to " << width << ' ' << height << std::endl;
	}

	virtual ~ASizedDrawable()
	{ }
};
