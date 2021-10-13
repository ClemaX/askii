#pragma once

#include <IDrawable.hpp>

class AColor:		public IDrawable
{
public:
	typedef enum
	{
		BACKGROUND = 48,
		FOREGROUND = 38
	}	Mode;

	typedef enum
	{
		DEFAULT = 2
	}	Option;

private:
	uint r;
	uint g;
	uint b;
	Mode mode;
	Option option;

protected:
	AColor(uint8_t r, uint8_t g, uint8_t b, Mode mode, Option option = DEFAULT)
		:	r(r), g(g), b(b), mode(mode), option(option)
	{}

	AColor(const AColor &color)
		:	r(color.r), g(color.g), b(color.b), mode(color.mode), option(color.option)
	{}

	AColor&	operator=(const AColor &color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		mode = color.mode;
		option = color.option;
	}

	void draw(ostream &os) const
	{
		os << "\033[" << mode << ';' << option << ';' << r << ';' << g << ';' << b << 'm';
	}
};
