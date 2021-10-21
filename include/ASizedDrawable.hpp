#pragma once

#include <Vector2D.hpp>
#include <IDrawable.hpp>

#include <iostream>

class ASizedDrawable:	virtual public IDrawable
{
public:
	typedef Vector2D<int>	dim_t;

protected:
	dim_t	dim;

public:
	ASizedDrawable()
		:	dim(0, 0)
	{ }

	ASizedDrawable(unsigned width, unsigned height)
		:	dim(width, height)
	{ }

	ASizedDrawable(const dim_t &dim)
		:	dim(dim)
	{ }

	virtual ~ASizedDrawable()
	{ }

	virtual void	resize(unsigned width, unsigned height)
	{
		dim.x = width;
		dim.y = height;
	}

	virtual dim_t const&	getDim() const
	{ return dim; }
};
