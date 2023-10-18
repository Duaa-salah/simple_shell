#include "main.h"

size_t cstrlen(char *dstrl)
{
	size_t l = 0;
	while (dstrl[l] != '\0')
	{
		l++;
	}
	return(l);
}

void cstrcp(char *dest, char *src)
{
	size_t d = 0;
	while (src[d] != '\0')
	{
		dest[d] = src[d];
		d++;
	}
	dest[d] = '\0';
}
