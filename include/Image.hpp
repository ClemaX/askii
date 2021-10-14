#pragma once

#include <vector>

#include <Vector2D.hpp>
#include <IDrawable.hpp>
#include <ASizedDrawable.hpp>
#include <APositionedDrawable.hpp>
#include <Pixel.hpp>

using std::vector;

typedef vector<Pixel>	pixel_container;

class Image: public ASizedDrawable, public APositionedDrawable
{
	pixel_container	pixels;

public:
	Image(unsigned width, unsigned height)
		:	ASizedDrawable(width, height), pixels(dim.x * dim.y)
	{ }

	Image(const Vector2D &dimensions)
		:	ASizedDrawable(dimensions), pixels(dim.x * dim.y)
	{ }

	virtual ~Image()
	{ }

	void	resize(unsigned newW, unsigned newH)
	{
		dim.x = newW;
		dim.y = newH;
		pixels.resize(newW * newH);
	}

	void	renderImage(const Image &img)
	{
		Vector2D				pos(img.pos);
		Vector2D				end(min(pos, img.dim));

		for (; pos.y < dim.y; y++)
		{
			for (; pos.x < dim.x; x++)
			{
				pixels[pos] = img[pos]
			}
		}

	}

	void	render()
	{

	}

	void	draw(ostream &os) const
	{
		for (const Pixel &pixel : pixels) { pixel.draw(os); }
	}

	void	fill(AColor *color, const char *content = NULL)
	{
		if (content)
			for (Pixel &pixel : pixels) { pixel.setColor(color); pixel.setContent(content); }
		else
			for (Pixel &pixel : pixels) { pixel.setColor(color); }
	}


	const Pixel	&operator[](Vector2D const &pos)
	{ return pixels[pos.y * dim.x + pos.x]; }

};
