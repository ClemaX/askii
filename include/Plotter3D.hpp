#pragma once

#include <AFunction.hpp>
#include <ACanvas.hpp>

class Plotter3D:	public AImage
{
private:
	typedef AFunction<3, float, float>	function_t;

	const function_t	&f;

	Pixel				bg;
	Pixel				fg;

protected:
	typedef function_t::pos_t	function_pos_t;

	pos_t			origin;
	float			zoomFactor;

	vector<float>	zBuff;

public:
	Plotter3D(const dim_t &dimensions, const function_t &function)
		:	AImage(dimensions), f(function),
			bg(Color(0, 0, 0)), fg(Color(255, 255, 255)),
			zoomFactor(0.5)
	{ }

	Plotter3D(unsigned width, unsigned height, const function_t &function)
		:	AImage(width, height), f(function),
			bg(Color(0, 0, 0)), fg(Color(255, 255, 255)),
			zoomFactor(0.5)
	{ }

	virtual ~Plotter3D()
	{ }

	// TODO: Optimize out origin + pos
	void	render()
	{
		pos_t	pos;

		for (pos.y = 0; pos.y < dim.y; pos.y++)
			for (pos.x = 0; pos.x < dim.x; pos.x++)
				zBuff[pos.y * dim.x + pos.x] = f((origin + pos) / zoomFactor);
	}

	void	zoom(float factor)
	{ zoomFactor *= factor; }

	void	setOrigin(const pos_t &position)
	{ origin = position; }

	void	resize(unsigned newW, unsigned newH)
	{
		AImage::resize(newW, newH);
		zBuff.resize(dim.x * dim.y, 0);
	}

	Pixel	operator[](pos_t const &position) const
	{ return zBuff.empty() ? fg : fg * zBuff[position.y * dim.x + position.x]; }

	void	draw(ostream &os) const
	{
		pos_t	pos;

		for (; pos.y < dim.y; pos.y++)
			for (pos.x = 0; pos.x < dim.x; pos.x++)
				operator[](pos).draw(os);
	}
};
