/* Exercise 2-9. In a two's complement number system, x &= (x-1)
 * deletes the rightmost 1-bit in x. Explain why. Use this
 * observation to write a faster version of bitcount. */

/* A two's complement number system is a system in which numbers or
  integers are reprensented in its binary form.

  For example in an 8-bit system, the 2's complement of the number 7
  is 00000111. Another example is the 2's complement of the number
  -7, which is 11111001.

 why the expression: x =& (x - 1), deletes the rightmost 1 bit.

 Let x = 7

 	0 1 1 1 ---> 7
	0 1 1 0	---> 6
 -------------
 	0 1 1 0 --> output
			--> the rightmost 1 bit is masked to zero, thereby
			effectively deleting the rightmost 1 bit.
*/

#include <stdio.h>
#include <limits.h>

main()
{
	printf("%u\n", UINT_MAX);
	printf("%d\n", bitcount(UINT_MAX));

	return 0;

}

/* bitcount: count 1  bits in x */
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; b++)
		x &= (x - 1);

	return b;
}
