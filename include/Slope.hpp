#pragma once

#include <Plotter2D.hpp>
#include <PerlinNoise.hpp>

// TODO: Use 3D noise to map characters by brightness

class SlopeFunction:	public AFunction<2>
{
private:
	typedef PerlinNoise<>	noise_t;

	noise_t	noise;

	float	slope;
	int		offset;


public:
	SlopeFunction(float slope = 0.6, int offset = 5)
		:	noise(), slope(slope), offset(offset)
	{ }

	int	operator()(const pos_t &pos) const
	{ return (slope * pos[0]) + noise({pos[0], 0, 0}) + offset; }
};

class Slope:	public Plotter2D
{
	SlopeFunction	slope;

public:
	Slope(unsigned width, unsigned height)
		:	Plotter2D(width, height, slope)
	{ }

 	void	seek(int delta)
	{
		origin.x += delta;
	}

	int		getHeight(int posX) const
	{
		return !yBuff.empty() ? yBuff[posX] : 0;
	}
};
