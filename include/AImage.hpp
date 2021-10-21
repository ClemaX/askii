#pragma once

#include <Pixel.hpp>

#include <ASizedDrawable.hpp>
#include <APositionedDrawable.hpp>

class AImage: public ASizedDrawable, public APositionedDrawable
{
public:
	AImage(unsigned width, unsigned height, unsigned posX = 0, unsigned posY = 0)
		:	ASizedDrawable(width / Pixel::size, height), APositionedDrawable(posX, posY)
	{ }

	AImage(const dim_t &dimensions)
		:	ASizedDrawable(dimensions.x / Pixel::size, dimensions.y), APositionedDrawable()
	{ }

	AImage(const dim_t &dimensions, const pos_t &pos)
		:	ASizedDrawable(dimensions.x / Pixel::size, dimensions.y), APositionedDrawable(pos)
	{ }

	virtual ~AImage()
	{ }

	virtual Pixel		operator[](pos_t const &pos) const = 0;

	virtual void		resize(unsigned newW, unsigned newH)
	{ ASizedDrawable::resize(newW / Pixel::size, newH); }
};
