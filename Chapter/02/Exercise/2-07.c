/* Exercise 2-7. Write a function invert(x,p,n) that returns x with
 * the n bits that begin at position p inverted (i.e. changed into 0
 * and vice versa), leaving the others unchanged. */

/* Procedure:

   1. Get the n bits of x starting at position p.

   		1. shift left the complement of 0 by n.
			~0 << n						(11110000) -> for visualization only
		2. complement the result
			~(~0 << n)					(00001111)
		3. shift left the result to position p.
			~(~0 << n) << p + 1 - n		(00111100)
		4. AND the result to the invert of x
			~x & ~(~0 << n) << p + 1 - n	-> inverted n bits
											starting at position p.
											
   2. OR the result with x whose n bits starting at position p masked
   to zero.

   		1. shift left the complement of 0 by n
			~0 << n						(11110000)
		2. complement the result
			~(~0 << n)					(00001111)
		3. shift left the result to p
			~(~0 << n) << p + 1 - n		(00111100)
		4. complement the result
			~(~(~0 << n) << p + 1 - n)	(11000011)
		5. AND the result with x
			x & ~(~(~0 << n) << p + 1 - n)	-> masked x
		6. OR the result with the result of Procedure 1.4

			(x & ~(~(~0 << n) << p+1-n)) | (~x & ~(~0 << n) << p+1-n)
*/
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
	printf("%u\n", invert(0, 15, 6));	

	return 0;
}

/* invert: returns x with the n bits that begin at position p
 * inverted */
unsigned invert(unsigned x, int p, int n)
{
	return (x& ~(~(~0 << n) << p+1-n)) | (~x & ~(~0 << n) << p+1-n);
}
