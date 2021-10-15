#pragma once

#include <Vector2D.hpp>
#include <IDrawable.hpp>

#include <iostream>

class ASizedDrawable:	virtual public IDrawable
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

	virtual ~ASizedDrawable()
	{ }

	virtual void	resize(unsigned width, unsigned height)
	{
		dim.x = width;
		dim.y = height;

		std::cerr << "resizing to " << width << ' ' << height << std::endl;
	}

	virtual Vector2D const&	getDim() const
	{ return dim; }
};
