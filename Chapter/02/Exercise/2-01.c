/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables from standard headers and by direct computation. Harder if
 * you compute them: determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

unsigned long power(int base, int n);

main()
{
	printf("\nRanges for char, short, int and long via standard header\n\n");
	printf("signed char: %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char: 0 to %d\n", UCHAR_MAX);
	printf("signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short: 0 to %d\n", USHRT_MAX);
	printf("signed int: %d to %d\n", INT_MIN, INT_MAX);
	printf("unsigned int: 0 to %u\n", UINT_MAX);
	printf("signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long: 0 to %lu\n", ULONG_MAX);
	printf("\n");

	printf("\nRanges for char, short, int, and long via computation\n\n");
	printf("signed char: %d to %d\n", power(-2, 7), power(2, 7) - 1);
	printf("unsigned char: 0 to %d\n", power(2, 8) - 1);
	printf("singed short: %d to %d\n", power(-2, 15), power(2, 15) - 1);
	printf("unsigned short: 0 to %d\n", power(2, 16) - 1);
	printf("signed int: %d to %d\n", power(-2, 31), power(2, 31) - 1);
	printf("unsigned int: 0 to %lu\n", power(2, 32) - 1);
	printf("signed long: %ld to %ld\n", power(-2, 63), power(2, 63) - 1);
	printf("unsigned long: 0 to %lu\n", power(2, 64) - 1);
	printf("\n");

	printf("\nRanges for float and double\n\n");
	printf("float: %g to %g\n", FLT_MIN, FLT_MAX);
	printf("double: %g to %g\n", DBL_MIN, DBL_MAX);
	printf("\n");


	return 0;
}

/* power: raise base to nth power; n >= 0 */
unsigned long power(int base, int n)
{
	int i;
	unsigned long p;

	p = 1;
	for (i = 1; i <=n; ++i)
		p = p * base;

	return p;
}
