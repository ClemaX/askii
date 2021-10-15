#pragma once

#include <vector>

#include <ACanvas.hpp>
#include <Vector2D.hpp>
#include <IDrawable.hpp>
#include <Pixel.hpp>

using std::vector;

template<typename P = Pixel>
class Canvas: public ACanvas
{
public:
	typedef P				pixel_t;
	typedef vector<pixel_t>	pixel_container;

protected:
	pixel_container	pixels;

public:
	Canvas(unsigned width, unsigned height)
		:	AImage(width, height), pixels(dim.x * dim.y)
	{ }

	Canvas(const Vector2D &dimensions)
		:	AImage(dimensions), pixels(dim.x * dim.y)
	{ }

	~Canvas()
	{ }

	// TODO: Pixel stream that optimizes sequential output directly
	void	draw(ostream &os) const
	{
		AColor	*currentColor = NULL;

		for (const Pixel &pixel : pixels) {
			if (currentColor == pixel.getColor())
				pixel.drawContent(os);
			else
				pixel.draw(os);
		}
	}

	void	resize(unsigned newW, unsigned newH)
	{
		AImage::resize(newW, newH);
		pixels.resize(dim.x * dim.y);
	}

	void	fill(AColor *color, char content = '\0')
	{
		if (content)
			for (Pixel &pixel : pixels) { pixel.setColor(color); pixel.setContent(content); }
		else
			for (Pixel &pixel : pixels) { pixel.setColor(color); }
	}

	const Pixel	&operator[](Vector2D const &pos) const
	{ return pixels[pos.y * dim.x + pos.x]; }

	Pixel	&operator[](Vector2D const &pos)
	{ return pixels[pos.y * dim.x + pos.x]; }
};
