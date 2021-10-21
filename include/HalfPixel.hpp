#pragma once

#include <APixel.hpp>

class	HalfPixel:	public APixel<1>
{
public:
	HalfPixel()
		:	APixel()
	{ }

	HalfPixel(Color color, char content = ' ')
		:	APixel(color, content)
	{ }
};
