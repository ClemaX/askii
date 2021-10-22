#pragma once

#include <AImage.hpp>

class	ACanvas:	public AImage
{
private:
	const Vector<2, int>	origin;

public:
	virtual Pixel	&operator[](pos_t const &pos) = 0;

	ACanvas(uint width, uint height, uint posX = 0, uint posY = 0)
		:	AImage(width, height, posX, posY)
	{ }

	ACanvas(const dim_t &dimensions, const pos_t &position = { })
		:	AImage(dimensions, position)
	{ }

	virtual ~ACanvas()
	{ }

	void	renderImage(const AImage &img)
	{

		const pos_t	begin(clamp(img.getPos(), origin, dim));
		const pos_t	end(clamp(img.getPos() + img.getDim(), origin, dim));
		pos_t		imgBegin(begin < origin ? -begin : origin);
		pos_t		destPos;
		pos_t		imgPos;

		// TODO: Optimize second for loop with transform
		for (pos.y = begin.y, imgPos.y = imgBegin.y; pos.y < end.y; pos.y++, imgPos.y++)
			for (pos.x = begin.x, imgPos.x = imgBegin.x; pos.x < end.x; pos.x++, imgPos.x++)
				operator[](pos) = img[imgPos];
	}
};
