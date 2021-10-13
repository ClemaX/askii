#pragma once

#include <AColor.hpp>

class BackgroundColor:	public AColor
{
private:

public:
	BackgroundColor(uint8_t r, uint8_t g, uint8_t b, Option option = DEFAULT)
		:	AColor(r, g, b, BACKGROUND, option)
	{ }
};
