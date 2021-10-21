#pragma once

#include <vector>

#include <ACanvas.hpp>
#include <Vector2D.hpp>
#include <IDrawable.hpp>
#include <HalfPixel.hpp>
#include <Pixel.hpp>

using std::vector;

template<typename P = Pixel>
class Canvas:	public ACanvas
{
public:
	typedef P				pixel_t;
	typedef vector<pixel_t>	pixel_container;

protected:
	pixel_container	pixels;
	HalfPixel		padding;
	bool			shouldPad;

public:
	Canvas(uint width, uint height, uint posX = 0, uint posY = 0)
		:	ACanvas(width, height, posX, posY), pixels(dim.x * dim.y),
			shouldPad(width % pixel_t::size)
	{ }

	Canvas(const dim_t &dimensions, const pos_t &position = {})
		:	ACanvas(dimensions, position), pixels(dim.x * dim.y),
			shouldPad(dim.x % pixel_t::size)
	{ }

	virtual ~Canvas()
	{ }


	void	draw(ostream &os) const
	{
		pos_t			pos;

		for (; pos.y < dim.y; pos.y++)
		{
			for (pos.x = 0; pos.x < dim.x; pos.x++)
			{
				operator[](pos).draw(os);
			}
			if (shouldPad)
				padding.draw(os);
		}
		os.flush();
	}

	void	resize(uint newW, uint newH)
	{
		AImage::resize(newW, newH);
		pixels.resize(dim.x * dim.y);
		shouldPad = (newW % pixel_t::size);
	}

	void	fill(const Color &color, char content = '\0')
	{
		if (content)
			for (Pixel &pixel : pixels) { pixel.bg = color; pixel.setContent(content); }
		else
			for (Pixel &pixel : pixels) { pixel.bg = color; }
	}

	Pixel	operator[](pos_t const &pos) const
	{ return pixels[pos.y * dim.x + pos.x]; }

	Pixel	&operator[](pos_t const &pos)
	{ return pixels[pos.y * dim.x + pos.x]; }

	Pixel	&operator[](uint index)
	{ return pixels[index]; }

};
