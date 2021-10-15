#include <AImage.hpp>

class ACanvas: virtual public AImage
{
private:
	/* data */
public:
	//virtual Pixel		&operator[](Vector2D const &pos) = 0;

	virtual Pixel	&operator[](Vector2D const &pos) = 0;

	void				renderImage(const AImage &img)
	{
		const Vector2D	&begin = img.getPos();
		Vector2D		pos(img.getPos());
		const Vector2D	end(min(pos + img.getDim(), dim));
		Vector2D		imgBegin(max(img.getPos(), Vector2D(0,0)));
		Vector2D		imgPos;

		for (pos.y = begin.y, imgPos.y = imgBegin.y; pos.y < end.y; pos.y++, imgPos.y++)
			for (pos.x = begin.x, imgPos.x = imgBegin.x; pos.x < end.x; pos.x++, imgPos.x++)
				operator[](pos) = img[imgPos];
	}
};
