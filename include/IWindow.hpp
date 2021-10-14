#pragma once

#include <vector>
#include <list>

#include <Vector2D.hpp>
#include <ASizedDrawable.hpp>
#include <AColor.hpp>
#include <Image.hpp>

using std::ostream;
using std::vector;
using std::list;

// Pixel Color: '\e[48;2;RRR;GGG;BBBm  '

ostream &operator<<(ostream &os, const IDrawable &drawable)
{
	drawable.draw(os);
	return os;
}

class Window:			public Image
{
private:
	vector<IDrawable*>	drawables;

public:
	Window(unsigned w, unsigned h)
		:	Image(w, h), drawables()
	{ }

	Window(const Vector2D &dim)
		:	Image(dim), drawables()
	{ }
/*
	void	renderDrawable(const IDrawable *drawable)
	{

	} */
/*
	void	render()
	{
		for (const IDrawable *drawable : drawables) { renderDrawable(drawable); }
	} */


	// TODO: operator=
	// TODO: copy constructor
};

