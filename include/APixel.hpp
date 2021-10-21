#pragma once

#include <iomanip>

#include <IPixel.hpp>
#include <Color.hpp>

#include <BackgroundColor.hpp>

template <u_char Size = 2>
class APixel : public IPixel
{
private:
	char content[Size];

public:
	static const u_char size = Size;

	Color	bg;
	Color	fg;

	APixel()
		: bg(Color::BACKGROUND), fg(Color::FOREGROUND)
	{ setContent(' '); }

	APixel(const BaseColor &bg, char contentChar = ' ')
		: bg(bg, Color::BACKGROUND), fg(Color::FOREGROUND)
	{ setContent(contentChar); }

	APixel(const BaseColor &bg, const BaseColor &fg, char contentChar = ' ')
		: bg(bg, Color::BACKGROUND), fg(fg, Color::FOREGROUND)
	{ setContent(contentChar); }

	virtual ~APixel(){};

	void setContent(char contentChar)
	{
		for (u_char i = 0; i < size; i++)
			content[i] = contentChar;
	}

	void draw(ostream &os) const
	{
		os << bg << fg;
		os.write(content, size);
	}

	void drawContent(ostream &os) const
	{
		os.write(content, size);
	}

	template<typename T>
	APixel	&operator*=(T scalar)
	{
		bg *= scalar;
		fg *= scalar;

		return *this;
	}
};

template<u_char Size, typename T>
APixel<Size>	operator*(APixel<Size> const& pixel, T scalar)
{
	APixel<Size> tmp(pixel);

	tmp *= scalar;

	return tmp;
}
