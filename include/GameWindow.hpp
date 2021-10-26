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
			player(slope, w / (3 * pixel_t::size))
	{
		player[0].bg = Color(255, 0, 0);
		player[1].bg = Color(255, 0, 0);
		player[2].bg = Color(255, 0, 0);
		player[3].bg = Color(255, 0, 0);
		player[4].bg = Color(255, 255, 0);
		player[5].bg = Color(255, 0, 0);
		player[6].bg = Color(255, 0, 0);
		player[7].bg = Color(255, 0, 0);
		player[8].bg = Color(255, 0, 0);

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
		std::cerr << slope.getTangent(player.getPos().x) << std::endl;
		Window::render();
	}

	void	resize(unsigned width, unsigned height)
	{
		slope.resize(width, height);
		Window::resize(width, height);
		player.move(dim.x / 3, dim.y);
	}
};
