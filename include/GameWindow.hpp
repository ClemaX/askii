#include <Window.hpp>

#include <Slope.hpp>
#include <Player.hpp>

#include <Plotter3D.hpp>

class	GameWindow:	public Window
{
private:
	Slope		slope;
	Player		player;

public:
	GameWindow(unsigned w, unsigned h)
		:	Window(w, h),
			slope(w, h),
			player(slope, w / (2 * pixel_t::size))
	{
		player[0].bg = Color(255, 0, 0);

		pushImage(slope);
		pushImage(player);
	}

	virtual ~GameWindow()
	{ }

 	void	seek(float delta)
	{
		slope.seek(delta);
	}

	void	render()
	{
		slope.render();
		player.render();
		Window::render();
	}

	void	resize(unsigned width, unsigned height)
	{
		slope.resize(width, height);
		Window::resize(width, height);
		player.move(dim.x / 2, dim.y);
	}
};
