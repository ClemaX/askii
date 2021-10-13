#pragma once

#include <AColor.hpp>

class ForegroundColor:	public AColor
{
private:

public:
	ForegroundColor(uint8_t r, uint8_t g, uint8_t b, Option option = DEFAULT)
		:	AColor(r, g, b, FOREGROUND, option)
	{ }
};
