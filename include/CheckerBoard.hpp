#pragma once

#include <AImage.hpp>

class CheckerBoard: public AImage
{
private:
	Pixel	bg;
	Pixel	fg;

public:
	CheckerBoard(const dim_t &dimensions): AImage(dimensions),
			bg(Color(0, 12, 25)), fg(Color(255, 255, 255)) {}

	CheckerBoard(unsigned width, unsigned height): AImage(width, height),
			bg(Color(0, 12, 25)), fg(Color(255, 255, 255)) {}

	~CheckerBoard()
	{ }

	Pixel	operator[](pos_t const &position) const
	{ return (position.x & 1) ^ (position.y & 1) ? bg : fg; }
};
