#pragma once

#include <IPixel.hpp>
#include <AColor.hpp>


#include <BackgroundColor.hpp>

template <unsigned char Size = 2>
class APixel:			public IPixel
{
private:
	const AColor	*color;
	char			content[Size];

public:
	static const unsigned char	size = Size;

	APixel(const AColor *color = NULL, char contentChar = ' ')
		:	color(color)
	{
		setContent(contentChar);
	}

	virtual ~APixel() {};
/*
	APixel()
		:	color(NULL), content("test")
	{} */

	void	setContent(char contentChar)
	{ for (unsigned char i = 0; i < size; i++) content[i] = contentChar; }

	void	setColor(AColor *newColor)
	{ color = newColor; }

	const AColor	*getColor() const
	{ return color; }

	void	clearColor()
	{ color = NULL; }

	void draw(ostream &os) const
	{
		if (color != NULL)
			os << *color << content;
		else
			os << content;
	}

	void	drawContent(ostream &os) const
	{ os << content; }
};
