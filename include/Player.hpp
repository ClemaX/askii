#pragma once

#include <Canvas.hpp>
#include <Slope.hpp>

class	Player:	public Canvas<>
{
	const Slope	&slope;


public:
	Player(const Slope &slope, unsigned posX)
		:	Canvas(2, 2, posX, slope.getHeight(posX)), slope(slope)
	{ }

	void	render()
	{
		int	minHeight = slope.getHeight(pos.x) - 1;

		if (pos.y < minHeight)
			pos.y++;
		if (pos.y > minHeight)
			pos.y = minHeight;
	}
};
