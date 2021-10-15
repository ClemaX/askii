#include <Window.hpp>

#include <Slope.hpp>

class	GameWindow:	public Window
{
private:
	Slope	slope;

public:
	GameWindow(unsigned w, unsigned h)
		:	AImage(w, h), Window(w, h), slope(w, h)
	{
		pushImage(slope);
	}

	void	resize(unsigned width, unsigned height)
	{
		slope.resize(width, height);
		Window::resize(width, height);
	}
};
