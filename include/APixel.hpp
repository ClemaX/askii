#pragma once

#include <iomanip>

#include <IPixel.hpp>
#include <AColor.hpp>

#include <BackgroundColor.hpp>

template <u_char Size = 2>
class APixel : public IPixel
{
private:
	const AColor *color;
	char content[Size];

public:
	static const u_char size = Size;

	APixel(const AColor *color = NULL, char contentChar = ' ')
		: color(color)
	{
		setContent(contentChar);
	}

	virtual ~APixel(){};

	void setContent(char contentChar)
	{
		for (u_char i = 0; i < size; i++)
			content[i] = contentChar;
	}

	void setColor(AColor *newColor)
	{
		color = newColor;
	}

	const AColor *getColor() const
	{
		return color;
	}

	void clearColor()
	{
		color = NULL;
	}

	void draw(ostream &os) const
	{
		if (color != NULL)
			os << *color;
		os.write(content, size);
	}

	void drawContent(ostream &os) const
	{
		os.write(content, size);
	}
};
