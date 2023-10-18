#include "main.h"
/**
 * cstrlen - Calculate the length of a string
 * @dstrl: string to be measured
 *
 * Return: length of the string
 */
size_t cstrlen(char *dstrl)
{
	size_t l = 0;

	while (dstrl[l] != '\0')
	{
		l++;
	}

	return (l);
}
/**
 * cstrcp - Copy a string
 * @dest: Destination string where
 * src will be copied
 * @src: Source string to be copied
 */
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
