#include <Window.hpp>

#include <Slope.hpp>
#include <Canvas.hpp>

class	Player:	public Canvas<>
{
	const Slope	&slope;


public:
	Player(const Slope &slope, unsigned posX)
		:	AImage(2, 2), Canvas(2, 2), slope(slope)
	{
		std::cout << "Player posX: " << posX << std::endl;
	}

/* 	void	render()
	{
		int	slopeHeight = slope.getHeight(pos.x);

		if (pos.y + 1 < slopeHeight)
			pos.y++;
		if (pos.y > slopeHeight)
			pos.y = slopeHeight;
	} */
};

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
		//player.render();
		Window::render();
	}

	void	resize(unsigned width, unsigned height)
	{
		slope.resize(width, height);
		player.move(2, 0);
		Window::resize(width, height);
	}
};
