#pragma once

#include <vector>

#include <Vector2D.hpp>
#include <IDrawable.hpp>
#include <Pixel.hpp>

using std::vector;

class Image: public IDrawable, public Vector2D
{
	vector<Pixel>	pixels;

public:
	Image(unsigned w, unsigned h)
		:	Vector2D(w, h), pixels(x * y)
	{ }

	Image(const Vector2D &dim)
		:	Vector2D(dim), pixels(x * y)
	{}

	virtual ~Image()
	{ }

	void	resize(unsigned newW, unsigned newH)
	{
		x = newW;
		y = newH;
		pixels.resize(x * y);
	}

	void	draw(ostream &os) const
	{
		for (const Pixel &pixel : pixels) { pixel.draw(os); }
	}

	void	fill(AColor *color, const char *content)
	{
		for (Pixel &pixel : pixels) { pixel.setColor(color); }
	}
};
