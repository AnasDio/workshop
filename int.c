#include <stdio.h>
#include <stdlib.h>
/**
 * _printint - a functino to print integers
 * @format: input format
 * Return: the length
*/
typedef struct spc{
char conversion_spc;
int (*f)(char *format, va_list);
}spcc;

int my_putchar(char c)
{
write(1, &c, 1);
return (1);
}
int my_putchar_wrapper(char *format, va_list args)
{
    char c = va_arg(args, int);
    return my_putchar(c);
}

int string_length(char *str)
{
int i, size = 0;

for (i = 0; str[i] != '\0'; i++)
size++;

return (size);
}

int get_spc(char *format, va_list args){
int j = 0;
spcc sppc[] = {
    {'%', my_putchar_wrapper},
    {'i', my_putchar_wrapper},
    {'d', my_putchar_wrapper},
    {0, NULL}
};
};
int printint(const char *format, ...)
{
    int x = 0;
    int length = 0;
    va_list nt;

    va_start(nt, format);
    if (format == NULL)
    {
        return (0);
    }
    for (;format[x-1];x++)
    {
        if(format[x] == '%' && format[x + 1])
        {
            length += my_putchar(format[x]);
        }
        else
        break;
    }
    va_end(nt);
    return (length);
}
