#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n)
{
	static char buf[BUFFER_SIZE];
	static ssize_t len, pos;
	ssize_t i = 0;
	char *tmp;

	if (!lineptr || !n)
		return (-1);
	if (!*lineptr || !*n)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (!*lineptr)
			return (-1);
	}
	while (1)
	{
		if (pos >= len)
		{
			len = read(0, buf, BUFFER_SIZE);
			pos = 0;
			if (len <= 0)
				return (-1);
		}
		if (i + 1 >= (ssize_t)*n)
		{
			*n *= 2;
			tmp = realloc(*lineptr, *n);
			if (!tmp)
				return (-1);
			*lineptr = tmp;
		}
		(*lineptr)[i++] = buf[pos++];
		if ((*lineptr)[i - 1] == '\n')
			break;
	}
	(*lineptr)[i] = '\0';
	return (i);
}
