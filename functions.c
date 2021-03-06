#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"
/**
 * print_c- function that fills place holders with string
 * @parameters:takes the parameter of va_arg
 * @join: is the buffer (takes temporal value)
 * @j: is the position where will be replace the va_arg
 * Return:j the actual position .
 */
int print_c(va_list parameters, int j, char *join)
{
	join[j] = va_arg(parameters, int);
	return (j);
}
/**
 * print_p- function that fills place holders with string
 * @parameters: takes the parameter of va_arg
 * @join: is the buffer (takes temporal value)
 * @j: is the position where will be replace the va_arg
 * Return:j the actual position
 */
int print_p(va_list parameters, int j, char *join)
{
	char *p = "%";

	parameters = parameters;
	join[j] = *p;

	return (j);
}
/**
 * print_s-function that fills place holders with string
 * @parameters: takes the parameter of va_arg
 * @join: is the buffer (takes temporal value)
 * @j: is the position where will be replace the va_arg
 * Return:j the actual position .
 */
int print_s(va_list parameters, int j, char *join)
{
	int x = 0;
	int c = 0;
	char *str = "";
	char *null_var = "(null)";

	str = va_arg(parameters, char *);

	if (str == (char *)0)
	{
		for (c = 0; null_var[c] != '\0'; c++)
		{
			join[j] = null_var[c];
			j++;
		}
	}
	else
		for (x = 0; str[x] != '\0'; x++)
		{
			join[j] = str[x];
			j++;
		}
	return (j - 1);
}
/**
 * print_n - function that fills place holders with string
 * @parameters: takes the parameter of va_arg
 * @join: is the buffer (takes temporal value)
 * @j: is the position where will be replace the va_arg
 * Return:j the actual position .
 */
int print_n(va_list parameters, int j, char *join)
{
	long int number;
	int aux_variable, base;

	number = va_arg(parameters, int);

	if (number < 0)
	{
		number *= -1;
		join[j] = 45;
		j++;
	}
	else
		number = number;
	if (number >= 0 && number <= 9)
	{
		join[j] = (number + 48);
		j++;
	}
	if (number > 9)
	{
		base = 10;

		while (number / base > 9)
		{
			base *= 10;
		}
		while (base > 0)
		{
			aux_variable = number / base;
			number = number % base;
			join[j] = (aux_variable + 48);
			base = base / 10;
			j++;
		}
	}
	return (j - 1);
}
