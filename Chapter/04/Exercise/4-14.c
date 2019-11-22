/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges two
 * arguments of type t. (Block structure will help.)
 */

/* The code for the swap function looks like this:

   temp = x;
   x = y;
   y = temp;

   The code above is for swapping the values of x and y.

   From this we can define a swap macro. 

 */

#include <stdio.h>

#define swap(t,x,y) {t temp;temp = x; x = y; y = temp;}

main()
{
	int x = 10, y = 20;

	printf("Before swap x = %d, y = %d\n", x, y);
	swap(int,x,y);
	printf("After swap x = %d, y = %d\n", x, y);

	return 0;
}

