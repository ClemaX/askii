#pragma once

#include <AFunction.hpp>
#include <ACanvas.hpp>

class Plotter2D:	public AImage
{
private:
	typedef AFunction<2, float, float>	function_t;

	const function_t	&f;

	Pixel				bg;
	Pixel				fg;

protected:
	typedef function_t::pos_t	function_pos_t;

	pos_t		origin;

	vector<int>	yBuff;

	float		zoomFactor;

public:
	Plotter2D(const dim_t &dimensions, const function_t &function, float zoomFactor = 1)
		:	AImage(dimensions), f(function),
			bg(Color(0, 12, 25)), fg(Color(255, 255, 255)),
			zoomFactor(zoomFactor)
	{ }

	Plotter2D(unsigned width, unsigned height, const function_t &function, float zoomFactor = 1)
		:	AImage(width, height), f(function),
			bg(Color(0, 12, 25)), fg(Color(255, 255, 255)),
			zoomFactor(zoomFactor)
	{ }

	~Plotter2D()
	{ }

	void	render()
	{
		function_pos_t	pos;

		for (; pos[0] < (int)yBuff.size(); pos[0]++)
		{ yBuff[pos[0]] = f({floorf((origin[0] + pos[0]) * zoomFactor)}); }
	}

	void	zoom(float factor)
	{ zoomFactor /= factor; }

	void	resize(unsigned newW, unsigned newH)
	{
		AImage::resize(newW, newH);
		yBuff.resize(dim.x);
	}

	Pixel	operator[](pos_t const &position) const
	{ return position.y < yBuff[position.x] ? bg : fg; }

	void	draw(ostream &os) const
	{
		pos_t	pos;

		for (; pos.y < dim.y; pos.y++)
			for (pos.x = 0; pos.x < dim.x; pos.x++)
				operator[](pos).draw(os);
	}
};
