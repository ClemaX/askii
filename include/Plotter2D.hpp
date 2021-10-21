#pragma once

#include <AFunction.hpp>
#include <ACanvas.hpp>

class Plotter2D:	public AImage
{
private:
	typedef AFunction<2, int>	function_t;

	const function_t	&f;

	Pixel				bg;
	Pixel				fg;

protected:
	typedef function_t::pos_t	function_pos_t;

	pos_t		origin;

	vector<int>	yBuff;

public:
	Plotter2D(const dim_t &dimensions, const function_t &function)
		:	AImage(dimensions), f(function),
			bg(Color(0, 12, 25)), fg(Color(255, 255, 255))
	{ }

	Plotter2D(unsigned width, unsigned height, const function_t &function)
		:	AImage(width, height), f(function),
			bg(Color(0, 12, 25)), fg(Color(255, 255, 255))
	{ }

	~Plotter2D()
	{ }

	void	render()
	{
		function_pos_t	pos;

		for (; pos[0] < (int)yBuff.size(); pos[0]++)
		{ yBuff[pos[0]] = f(pos); }
	}

	void	resize(unsigned newW, unsigned newH)
	{
		yBuff.resize(newW);
		AImage::resize(newW, newH);
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
