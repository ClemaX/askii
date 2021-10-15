#include <AImage.hpp>

#include <BackgroundColor.hpp>
#include <ForegroundColor.hpp>

class Slope:	virtual public AImage
{
	Pixel			bg;
	Pixel			fg;

	unsigned		x;
	float			dy;

public:
	Slope(unsigned width, unsigned height, float dy = 1.0)
		:	AImage(width, height), bg(new BackgroundColor(0, 12, 25)), fg(new BackgroundColor(255, 255, 255)), x(0), dy(dy)
	{ std::cerr << "Created slope of size " << width << 'x' << height << std::endl; }

 	void	seek(int delta)
	{
		x += delta;
	}

	const Pixel	&operator[](Vector2D const &pos) const
	{
		int	height = (x + pos.x) * dy;

		return pos.y < height ? bg : fg;
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
