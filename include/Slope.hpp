#pragma once

#include <Plotter2D.hpp>
#include <PerlinNoise.hpp>

// TODO: Use 3D noise to map characters by brightness

class SlopeFunction:	public AFunction<2, float, float>
{
private:
	typedef PerlinNoise<>			noise_t;
	typedef typename noise_t::pos_t	noise_pos_t;

	noise_t	noise;

	float	slope;
	float	noiseAmp;
	int		offset;

	float	originX;

public:
	SlopeFunction(float slope = 0.7, float noiseAmp = 15, int offset = 5)
		:	noise(), slope(slope), noiseAmp(noiseAmp), offset(offset), originX(0)
	{ }

	float	operator()(const pos_t &pos) const
	{ return (slope * pos[0]) + noise({originX + pos[0] / 10, 0}) * noiseAmp + offset; }

	void	seek(float delta)
	{ originX += delta; }
};

class Slope:	public Plotter2D
{
	SlopeFunction	slope;

public:
	Slope(unsigned width, unsigned height)
		:	Plotter2D(width, height, slope, 1)
	{ }

 	void	seek(float delta)
	{
		slope.seek(delta);
	}

	int		getHeight(int posX) const
	{
		return !yBuff.empty() ? yBuff[posX] : 0;
	}
};
