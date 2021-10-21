#pragma once

#include <IDrawable.hpp>

class BaseColor
{
protected:
	uint8_t r;
	uint8_t g;
	uint8_t b;
	bool	initialized;

public:
	BaseColor()
		:	r(0), g(0), b(0), initialized(false)
	{ }

	BaseColor(uint8_t grayscale)
		:	r(grayscale), g(grayscale), b(grayscale), initialized(true)
	{ }

	BaseColor(uint8_t r, uint8_t g, uint8_t b)
		:	r(r), g(g), b(b), initialized(true)
	{ }

	BaseColor(const BaseColor &color)
		:	r(color.r), g(color.g), b(color.b), initialized(color.initialized)
	{ }

	~BaseColor()
	{ }

	void	set(uint8_t red, uint8_t green, uint8_t blue)
	{ r = red % 255; g = green % 255; b = blue % 255; initialized = true; }

	constexpr operator bool() const
	{ return initialized; }
};

class Color: public IDrawable, public virtual BaseColor
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
	Mode mode;
	Option option;

public:
	Color(Mode mode = BACKGROUND, Option option = DEFAULT)
		:	mode(mode), option(option)
	{ }

	Color(uint8_t r, uint8_t g, uint8_t b, Mode mode = BACKGROUND, Option option = DEFAULT)
		:	BaseColor(r, g, b), mode(mode), option(option)
	{ }

	Color(const Color &color)
		:	BaseColor(color), mode(color.mode), option(color.option)
	{ }

	Color (const BaseColor &base, Mode mode, Option option = DEFAULT)
		:	BaseColor(base), mode(mode), option(option)
	{ }

	Color	&operator=(const Color &color)
	{
		BaseColor::operator=(color);
		mode = color.mode;
		option = color.option;

		return *this;
	}

	template<typename T>
	Color	&operator*=(T scalar)
	{
		if (operator bool())
		{
			r *= scalar;
			g *= scalar;
			b *= scalar;
		}
		return *this;
	}

public:
	void draw(ostream &os) const
	{
		if (operator bool())
		{
			os << "\033[" \
				<< mode << ';' \
				<< option << ';' \
				<< +r << ';' \
				<< +g << ';' \
				<< +b \
			<< 'm';
		}
	}
};
