#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>

#include <iostream>
#include <ctime>

#include <GameWindow.hpp>

#include <PerlinNoise.hpp>

#include <Plotter3D.hpp>

#ifdef STDOUT_FILENO
# define WINDOW_FILENO STDOUT_FILENO
#else
# define WINDOW_FILENO 1
#endif

struct winsize size;

GameWindow	window(0,0);

void	onResize(int sig)
{
	(void)sig;
	ioctl(WINDOW_FILENO, TIOCGWINSZ, &size);

	window.resize(size.ws_col, size.ws_row);
}

void	clearScreen()
{
	std::cout << "\033[H";
}

void	resetColors()
{
	std::cout << "\033[39;49m";
}

void	hideCursor()
{
	std::cout << "\033[?25l";
}

void	showCursor()
{
	std::cout << "\033[?25h";
}

void	onExit()
{
	resetColors();
	clearScreen();
	showCursor();
}

void	onInterrupt(int sig)
{
	(void)sig;
	onExit();
	exit(0);
}

int	main(int ac, const char **av)
{
	signal(SIGWINCH, onResize);
	signal(SIGINT, onInterrupt);
	onResize(SIGWINCH);

	hideCursor();

	while (true)
	{
		clearScreen();
		window.render();
		window.draw(std::cout);
		window.seek(0.25);
		usleep(1000 * 50);
	}

	onExit();

	return 0;
}
