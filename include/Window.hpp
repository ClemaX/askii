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
	pixel_container			padding;

public:
	Window(unsigned w, unsigned h)
		:	AImage(w,h), Canvas(w, h), images()
	{ }

	Window(const Vector2D &dim)
		:	AImage(dim), Canvas(dim), images()
	{ }

	void	draw(ostream &os) const
	{
		const AColor	*currentColor = NULL;
		Vector2D		pos;

		for (; pos.y < dim.y; pos.y++) {
			for (pos.x = 0; pos.x < dim.x; pos.x++)
			{
				if (currentColor == operator[](pos).getColor())
					operator[](pos).drawContent(os);
				else
					operator[](pos).draw(os);
			}
		}
		os.flush();
	}

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

