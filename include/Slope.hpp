#pragma once

#include <Plotter2D.hpp>
#include <PerlinNoise.hpp>
#include <Octaves.hpp>

// TODO: Use 3D noise to map characters by brightness

class SlopeFunction:	public AFunction<2, float, float>
{
private:
	typedef PerlinNoise<>			noise_t;
	typedef typename noise_t::pos_t	noise_pos_t;

	typedef Octaves<noise_t, 4>		octaves_t;

	octaves_t	octaves;

	float		slope;
	float		noiseAmp;
	int			offset;

	float		originX;

public:
	SlopeFunction(unsigned seed = 420, float slope = 1, float noiseAmp = 15, int offset = 5)
		:	octaves(seed, 0.5, 2), slope(slope), noiseAmp(noiseAmp),
			offset(offset), originX(0)
	{ }

	float	operator()(const pos_t &pos) const
	{ return (slope * pos[0]) + octaves({(originX + pos[0]) / 20, 0}) * noiseAmp + offset; }

	void	seek(float delta)
	{ originX += delta; }
};

class Slope:	public Plotter2D
{
	SlopeFunction	slope;

public:
	Slope(unsigned width, unsigned height)
		:	Plotter2D(width, height, slope)
	{ }

 	void	seek(float delta)
	{
		slope.seek(delta * zoomFactor);
	}

	int		getHeight(int posX) const
	{
		return !yBuff.empty() ? yBuff[posX] : 0;
	}
};
