#pragma once

#include <vector>

#include <ACanvas.hpp>
#include <Vector2D.hpp>
#include <IDrawable.hpp>
#include <HalfPixel.hpp>
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
	HalfPixel		padding;
	bool			shouldPad;

public:
	Canvas(unsigned width, unsigned height)
		:	AImage(width, height), pixels(dim.x * dim.y), shouldPad(width % pixel_t::size)
	{ }

	Canvas(const dim_t &dimensions)
		:	AImage(dimensions), pixels(dim.x * dim.y), shouldPad(dim.x % pixel_t::size)
	{ }

	virtual ~Canvas()
	{ }


	void	draw(ostream &os) const
	{
		const AColor	*currentColor = NULL;
		pos_t			pos;

		for (; pos.y < dim.y; pos.y++) {
			for (pos.x = 0; pos.x < dim.x; pos.x++)
			{
				if (currentColor == operator[](pos).getColor())
					operator[](pos).drawContent(os);
				else
					operator[](pos).draw(os);
			}
			if (shouldPad)
				padding.draw(os);
		}
		os.flush();
	}

	void	resize(unsigned newW, unsigned newH)
	{
		AImage::resize(newW, newH);
		pixels.resize(dim.x * dim.y);
		shouldPad = (newW % pixel_t::size);
	}

	void	fill(AColor *color, char content = '\0')
	{
		if (content)
			for (Pixel &pixel : pixels) { pixel.setColor(color); pixel.setContent(content); }
		else
			for (Pixel &pixel : pixels) { pixel.setColor(color); }
	}

	const Pixel	&operator[](pos_t const &pos) const
	{ return pixels[pos.y * dim.x + pos.x]; }

	Pixel	&operator[](pos_t const &pos)
	{ return pixels[pos.y * dim.x + pos.x]; }

	Pixel	&operator[](unsigned index)
	{ return pixels[index]; }

};
