#pragma once

#include <ostream>

using std::ostream;

struct	IDrawable
{
	virtual void	draw(ostream &os) const = 0;

	friend std::ostream& operator<<(std::ostream& os, const IDrawable& drawable);
};

ostream &operator<<(ostream &os, const IDrawable &drawable)
{
	drawable.draw(os);
	return os;
}
