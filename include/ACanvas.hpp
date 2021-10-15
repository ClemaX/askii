#include <AImage.hpp>

class	ACanvas:	virtual public AImage
{
public:
	virtual Pixel	&operator[](Vector2D const &pos) = 0;

	void	renderImage(const AImage &img)
	{
		const Vector2D	&begin = img.getPos();
		const Vector2D	end(min(begin + img.getDim(), dim));
		const Vector2D	imgBegin(max(img.getPos(), Vector2D(0, 0)) - img.getPos());
		Vector2D		destPos;
		Vector2D		imgPos;

		for (pos.y = begin.y, imgPos.y = imgBegin.y; pos.y < end.y; pos.y++, imgPos.y++)
			for (pos.x = begin.x, imgPos.x = imgBegin.x; pos.x < end.x; pos.x++, imgPos.x++)
				operator[](pos) = img[imgPos];
	}
};
