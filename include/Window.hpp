#pragma once

#include <vector>
#include <list>

#include <Vector2D.hpp>
#include <ASizedDrawable.hpp>
#include <AColor.hpp>
#include <Canvas.hpp>

using std::ostream;
using std::vector;
using std::list;

// Pixel Color: '\e[48;2;RRR;GGG;BBBm  '

class Window:			public Canvas<Pixel>
{
private:
	vector<const AImage*>	images;

public:
	Window(unsigned w, unsigned h)
		:	AImage(w,h), Canvas(w, h)
	{ }

	Window(const dim_t &dim)
		:	AImage(dim), Canvas(dim)
	{ }

	void	render()
	{
		for (const AImage *image : images) { renderImage(*image); }
	}

	void	pushImage(const AImage &image)
	{
		images.push_back(&image);
	}

	// TODO: operator=
	// TODO: copy constructor
};

