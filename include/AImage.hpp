#pragma once

#include <Pixel.hpp>

#include <ASizedDrawable.hpp>
#include <APositionedDrawable.hpp>

class AImage: public ASizedDrawable, public APositionedDrawable
{
public:
	AImage(unsigned width, unsigned height)
		:	ASizedDrawable(width / Pixel::size, height)
	{ }

	AImage(const Vector2D &dimensions)
		:	ASizedDrawable(dimensions.x / Pixel::size, dimensions.y)
	{ }

	virtual ~AImage()
	{ }

	virtual const Pixel	&operator[](Vector2D const &pos) const = 0;

	virtual void		resize(unsigned newW, unsigned newH)
	{
		ASizedDrawable::resize(newW / Pixel::size, newH);
	}
};
