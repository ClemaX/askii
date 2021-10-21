#pragma once

#include <Color.hpp>

class BackgroundColor:	public Color
{
private:

public:
	BackgroundColor(uint8_t r, uint8_t g, uint8_t b, Option option = DEFAULT)
		:	Color(r, g, b, BACKGROUND, option)
	{ }
};
