#include <Window.hpp>

#include <Slope.hpp>
#include <Player.hpp>

#include <Plotter3D.hpp>

class	GameWindow:	public Window
{
private:
	//Slope		slope;
	//Player		player;
	Plotter3D					plotter;
	PerlinNoise<float>			noise;

public:
	GameWindow(unsigned w, unsigned h)
		:	Window(w, h),// slope(w, h),
			//player(slope, w / (2 * pixel_t::size)),
			plotter(w, h, noise)
	{
		//player[0].setColor(new BackgroundColor(255, 0, 0));
		pushImage(plotter);
		//pushImage(slope);
		//pushImage(player);
	}

	virtual ~GameWindow()
	{ }

 	void	seek(float delta)
	{
		plotter.zoom(delta);
		//slope.seek(delta);
	}

	void	render()
	{
		//slope.render();
		plotter.render();
		//player.render();
		Window::render();
	}

	void	resize(unsigned width, unsigned height)
	{
		//slope.resize(width, height);
		plotter.resize(width, height);
		Window::resize(width, height);
		//player.move(dim.x / 2, dim.y);
	}
};
