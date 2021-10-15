#pragma once

#include <APixel.hpp>

class Pixel:	public APixel<2>
{
public:
	Pixel(const AColor *color = NULL, char contentChar = ' ')
		:	APixel<2>(color, contentChar)
	{ }
};
