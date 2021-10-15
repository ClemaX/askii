#pragma once

#include <IDrawable.hpp>

struct IPixel:			public IDrawable
{
	virtual void	drawContent(ostream &os) const = 0;
};
