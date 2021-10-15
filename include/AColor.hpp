#pragma once

#include <IDrawable.hpp>

class AColor: virtual public IDrawable
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
	AColor(uint8_t red, uint8_t green, uint8_t blue, Mode mode, Option option = DEFAULT)
		:	r(red % 256), g(green % 256), b(blue % 256), mode(mode), option(option)
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

		return *this;
	}

public:
	void	setColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		r = red % 256;
		g = green % 256;
		b = blue % 256;
	}

	void draw(ostream &os) const
	{
		os << "\033[" << mode << ';' << option << ';' << r << ';' << g << ';' << b << 'm';
	}
};
