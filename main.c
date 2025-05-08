#include <unistd.h>

int main()
{
	write(STDOUT_FILENO, "hola\n", 5);
	return (0);
}