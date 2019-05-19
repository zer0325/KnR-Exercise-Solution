/* Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions. */

/*	Procedure:

	1. Get the rightmost bit.
		a. shift left the complement of 0 by 1.
			~0 << 1 		(11111110)
		b. complement the result
			~(~0 << 1)		(00000001)
		c. AND the result with x.
			x & ~(~0 << 1)	--> rightmost bit

	2. Shift left to the leftmost position.
		Lets say the result of Procedure 1 is:
			0 0 0 0 0 0 0 1 <---
			0 0 0 0 0 0 1 0
			...
			1 0 0 0 0 0 0 0 <--- We should end up here.

			leftmost_pos = FALSE
			while (!leftmost_pos) {
				y = y << 1
				if ((y << 1) >= 0)
					leftmost_pos = TRUE
			}
		
	3. Shift right x by 1.

			x = x >> 1;

	4. OR the result with the result of Procedure 2.

			x = x | y
			
	5. Repeat n times.

*/
#include <stdio.h>

int  rightrot(int x, int n);

main()
{
	printf("%d\n", rightrot(15, 3));
	return 0;
}
/* rightrot: returns x whose  value is rotated to the right by n bit
 * positions */
int rightrot(int x, int n)
{
	int y, leftmost_pos;
	
	while (n > 0) {
		y = x & ~(~0 << 1);
		if (y == 1) {
			leftmost_pos = 0;
			while (!leftmost_pos) {
				y = y << 1;
				if ((y << 1) <= 0)
					leftmost_pos = 1;
			}
		}
		x = x >> 1;
		x = x | y;
		--n;
	}
	return x;

}
