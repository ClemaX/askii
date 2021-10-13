#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>

#include <iostream>
#include <ctime>

#include <IWindow.hpp>

#ifdef STDOUT_FILENO
# define WINDOW_FILENO STDOUT_FILENO
#else
# define WINDOW_FILENO 1
#endif

struct winsize size;

Window	window(0,0);

void	onResize(int sig)
{
	(void)sig;
	ioctl(WINDOW_FILENO, TIOCGWINSZ, &size);

	window.resize(size.ws_col, size.ws_row);
}

void	clearScreen()
{
	std::cout << "\033[H\033[j";
}

int	main()
{
	signal(SIGWINCH, onResize);
	onResize(SIGWINCH);

	while (true)
	{
		clearScreen();
		window.draw(std::cout);
		usleep(1000 * 1000);
	}
	return 0;
}
