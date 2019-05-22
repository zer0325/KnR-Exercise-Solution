/* Exercise 2-9. In a two's complement number system, x &= (x-1)
 * deletes the rightmost 1-bit in x. Explain why. Use this
 * observation to write a faster version of bitcount. */

/*	
	In a two's complement system, the subtraction M - N has the
	following rules:

		1. Add the two's complement of the subtrahend, N, to the
		   minuend M.
		2. Discard the carry over.

	In x - 1, the minuend is x and the subtrahend is 1. 
	
	The two's complement of a number is its 1's compelement plus 1. 

	Assuming an 8-bit unsigned system:

		0 0 0 0 0 0 0 1 ==> 1
		1 1 1 1 1 1 1 0 ==> 1's complement
	+ 				  1
		1 1 1 1 1 1 1 1 ==> 2's complement of 1.

	Lets assume that x = *****100, where x is either 0 or 1.

	Adding the two's complement of 1 to x, we have

		1 1 1 1 1 1 1 1 ==> 2's complement of 1.
		* * * * * 1 0 0 ==> x
		
		* * * * * 0 0 0 ==> the result of x - 1, where the rightmost
						    1 bit of x is now 0.

	AND'ng the above result to x,

		* * * * * 0 0 0 ==> x - 1
		* * * * * 1 0 0 ==> x

		* * * * * 0 0 0 ==> Note that the result is a value whose
							rightmost 1 bit is masked to zero, which
							effectively deletes the rightmost 1 bit.

*/

#include <stdio.h>

int bitcount(unsigned x);

main()
{
	printf("%d\n", bitcount(22342355));

	return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int b;
	
	for (b = 0; x != 0; ++b)
		x &= (x - 1);

	return b;
}
