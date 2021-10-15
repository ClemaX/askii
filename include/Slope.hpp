#include <AImage.hpp>
#include <cmath>
#include <BackgroundColor.hpp>
#include <ForegroundColor.hpp>

class Slope:	virtual public AImage
{
	vector<int>		yBuff;
	Pixel			bg;
	Pixel			fg;

	unsigned		x;
	unsigned		offset;
	float			slope;
	float			bump;
	float			bump_dist;

public:
	Slope(unsigned width, unsigned height,
		unsigned offset = 5, float slope = 0.6, float bump = 4.0, float	bump_dist = 60.0)
		:	AImage(width, height), yBuff(width),
			bg(new BackgroundColor(0, 12, 25)), fg(new BackgroundColor(255, 255, 255)),
			x(1), offset(offset), slope(slope), bump(bump), bump_dist(bump_dist)
	{ }

 	void	seek(int delta)
	{

		x += delta;
		bump_dist = 60 * (1/(1+(0.02*x)));
		bump += 0.0000002*x;
		if (x > 500)
			slope = 0.7;
	}

	void	render()
	{
		for (int posX = 0; posX < (int)yBuff.size(); posX++)
		{ yBuff[posX] = (slope * (posX)) + bump * sin((-posX - (float)x)/bump_dist) + offset; }
	}

	void	resize(uint newW, uint newH)
	{
		yBuff.resize(newW);
		AImage::resize(newW, newH);
	}

	int		getHeight(int posX) const
	{
		return yBuff[posX];
	}

	const Pixel	&operator[](Vector2D const &position) const
	{
		return position.y < yBuff[position.x] ? bg : fg;
	}

	void	draw(ostream &os) const
	{
		Vector2D	pos;

		for (; pos.y < dim.y; pos.y++) {
			for (; pos.x < dim.x; pos.x++)
				operator[](pos).draw(os);
		}
	}
};
