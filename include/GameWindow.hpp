#include <Window.hpp>

#include <Slope.hpp>
#include <Player.hpp>

class	GameWindow:	public Window
{
private:
	Slope	slope;
	Player	player;

public:
	GameWindow(unsigned w, unsigned h)
		:	AImage(w, h), Window(w, h), slope(w, h), player(slope, 0)
	{
		player[0].setColor(new BackgroundColor(255, 0, 0));
		pushImage(slope);
		pushImage(player);
	}

 	void	seek(int delta)
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
		player.move(width / 4, 0);
		Window::resize(width, height);
	}
};
