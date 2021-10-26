#pragma once

#include <Canvas.hpp>
#include <Slope.hpp>

class	Player:	public Canvas<>
{
public:
	typedef Vector2D<float_t>	force_t;

private:
	const Slope	&slope;
	force_t		velocity;
	force_t		acceleration;
	float		mass;

public:
	Player(const Slope &slope, unsigned posX)
		:	Canvas(6, 3, posX, slope.getHeight(posX)), slope(slope), mass(10)
	{ }

	void	render(float_t delta)
	{
		velocity += acceleration;
		acceleration *= 0;
		pos.y += velocity.y;
	}

	force_t const	&getVelocity() const
	{ return velocity; }

	void	applyForce(force_t force)
	{ acceleration += force; }
};
