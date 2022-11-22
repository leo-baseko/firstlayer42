// https://www.geeksforgeeks.org/variable-length-argument-c/

// C program to demonstrate use of variable
// number of arguments.
#include <stdarg.h>
#include <stdio.h>

// this function returns minimum of integer
// numbers passed.  First argument is count
// of numbers.
int	min(int arg_count, ...)
{
	int		i;
	int		min;
	int		a;
	va_list	ap;

	va_start(ap, arg_count);
	min = va_arg(ap, int);
	i = 2;
	while (i <= arg_count)
	{
		a = va_arg(ap, int);
		if (a < min)
			min = a;
		i++;
	}
	va_end(ap);
	return (min);
}

int average(int num, ...)
{
	va_list	valist;
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	va_start(valist, num);
	while (i < num)
	{
		sum += va_arg(valist, int);
		i++;
	}
	va_end(valist);
	return (sum / num);
}

int main()
{
	int count = 4;
	printf("Minimum value is %d\n", min(count, 10, 11, 6, 7, 100, 4, 45, 100, 0));

	printf("Average of {2, 3, 4} = %d\n", average(2, 3, 4));
    printf("Average of {3, 1, 1, 1, 5, 11, 15} = %d\n", average(3, 1, 2, 3, 5, 11, 15));

	return (0);
}
