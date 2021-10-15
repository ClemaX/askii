#pragma once

#include <AColor.hpp>

class	HalfPixel:	public APixel<1>
{
public:
	HalfPixel(const AColor *color = nullptr, char content = ' ')
		:	APixel(color, content)
	{ }
};
