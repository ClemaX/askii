#pragma once

#include <IPixel.hpp>
#include <AColor.hpp>

class Pixel:			public IPixel
{
private:
	const AColor	*color;
	const char		*content;

public:
	Pixel()
		:	color(NULL), content("  ")
	{}

	virtual ~Pixel() {};
/*
	Pixel()
		:	color(NULL), content("test")
	{} */

	void	setContent(const char *newContent)
	{
		content = newContent;
	}

	void	setColor(AColor *newColor)
	{
		color = newColor;
	}

	void	clearColor()
	{
		color = NULL;
	}

	void draw(ostream &os) const
	{
		if (color != NULL)
			os << *color << content;
		else
			os << content;
	}
};
