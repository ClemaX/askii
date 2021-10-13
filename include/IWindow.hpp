#pragma once

#include <vector>
#include <list>

#include <Vector2D.hpp>
#include <ASizedDrawable.hpp>
#include <AColor.hpp>
#include <Image.hpp>

using std::ostream;
using std::vector;
using std::list;

// Pixel Color: '\e[48;2;RRR;GGG;BBBm  '

ostream &operator<<(ostream &os, const IDrawable &drawable)
{
	drawable.draw(os);
	return os;
}

class Window:			public ASizedDrawable
{
private:
	Image		image;

public:
	Window(unsigned w, unsigned h)
		:	ASizedDrawable(w, h), image(dim)
	{ }

	void	resize(unsigned w, unsigned h)
	{
		ASizedDrawable::resize(w, h);
		image.resize(w, h);
	}

	void	draw(ostream &os) const
	{
		image.draw(os);
	}
};

