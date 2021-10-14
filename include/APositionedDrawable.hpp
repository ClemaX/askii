#pragma once

#include <Vector2D.hpp>
#include <IDrawable.hpp>

#include <iostream>

class APositionedDrawable:	virtual public IDrawable
{
protected:
	Vector2D	pos;

public:
	APositionedDrawable(unsigned x = 0, unsigned y = 0)
		:	pos(x, y)
	{ }

	APositionedDrawable(const Vector2D &pos)
		:	pos(pos)
	{ }

	virtual void			move(unsigned x, unsigned y)
	{
		pos.x = x;
		pos.y = y;

		std::cout << "positioning to " << x << ' ' << y << std::endl;
	}

	virtual Vector2D const&	getPos() const
	{ return pos; }

	virtual ~APositionedDrawable()
	{ }
};
