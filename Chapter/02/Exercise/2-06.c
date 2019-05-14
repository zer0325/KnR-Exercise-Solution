/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x
 * with the n bits that begin at position p set to the rightmost n
 * bits of y, leaving the other bits unchanged. */

/* Procedure:

   1. Get the rightmost n bits of y.

   		1. shift left the complement of 0 by n
			~0 << n				(11110000) --> for visualization only
		2. complement the result
			~(~0 << n)			(00001111)
		3. AND the result to y
			y & ~(~0 << n)		--> rightmost n bits of y

   2. Shift left the result to position p.

   		(y & ~(~0 << n)) << p + 1 - n

   3. OR the result with x whose n bits starting at position p are
   masked to zero.

   		Get the masked x

		1. shift left the complement of 0 by n
			~0 << n				(11110000)
		2. complement the result
			~(~0 << n)			(00001111)
		3. shift left the result to p
			~(~0 << n) << p + 1 - n 	(00111100)
		4. complement the result
			~(~(~0 << n) << p + 1 - n)	(11000011)
		5. AND the result with x
			x & ~(~(~0 << n) << p + 1 - n) -> masked x

		6. OR the result to the result of Procedure 2.

		(x & ~(~(~0 << n) << p+1-n)) | ((y & ~(~0 << n)) << p+1-n)
*/
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main()
{
	printf("%u\n", setbits(67, 8, 3, 33));
	return 0;
}

/* setbits: returns x with the n bits starting at position p set to
 * the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ~(~(~0 << n) << p+1-n)) | ((y & ~(~0 << n)) <<
			p+1-n);
}
