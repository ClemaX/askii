#pragma once

#include <Vector2D.hpp>
#include <IDrawable.hpp>

#include <iostream>

class APositionedDrawable: virtual public IDrawable
{
public:
	typedef Vector2D<int>	pos_t;

protected:
	pos_t	pos;

public:
	APositionedDrawable(unsigned x = 0, unsigned y = 0)
		:	pos(x, y)
	{ }

	APositionedDrawable(const pos_t &pos)
		:	pos(pos)
	{ }

	virtual void			move(unsigned x, unsigned y)
	{
		pos.x = x;
		pos.y = y;
	}

	virtual pos_t const&	getPos() const
	{ return pos; }

	virtual ~APositionedDrawable()
	{ }
};
