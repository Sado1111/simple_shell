#include "shell.h"
/**
 * _perror - prints formated text before an error message.
 * @form: a string, can contain %s for string Only.
 *
 * Return: Nothing.
 */
void _perror(const char *form, ...)
{
	va_list ar;
	int i;

	va_start(ar, form);
	for(i = 0; form[i]; i++)
	{
		if (form[i] == '%')
		{
			print_str(ar);
			i++;
		}
		else
			_putchar(form[i]);
	}
	perror(NULL);
}
/**
 * _putchar - prints a single char to stderr stream.
 * @c: the char to be printed.
 *
 * Return: 1.
 */
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
/**
 * print_str - prints a string to stderr.
 * @ar: argument list.
 *
 * Return: Nothing.
 */
void print_str(va_list ar)
{
	char *tmp = va_arg(ar, char *);

	write(STDERR_FILENO, tmp, _strlen(tmp));
}
