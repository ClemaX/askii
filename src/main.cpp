#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>

#include <iostream>
#include <ctime>

#include <GameWindow.hpp>

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

void	onInterrupt(int sig)
{
	(void)sig;
	resetColors();
	clearScreen();
	exit(0);
}

int	main()
{
	signal(SIGWINCH, onResize);
	onResize(SIGWINCH);


	signal(SIGINT, onInterrupt);

	while (true)
	{
		clearScreen();
		window.render();
		window.draw(std::cout);
		window.seek(1);
		usleep(1000 * 100);
	}
	resetColors();
	clearScreen();

	return 0;
}
