/* Exercise 3-4. In a two's complement number representation, our
 * version of itoa does not handle the largest negative number, that
 * is, the value of n equal to -(2^(wordsize-1)). Explain why not.
 * Modify it to print that value correctly, regardless of the machine
 * on which it runs.
 */

/* General Idea:

   Lets say that wordsize = 4. So,  the largest negative number is
   -(2^4-1), which is -8. In a two's complement number system, -8 is
   represented by 1000. In the code itoa, the statement n = -n,
   converts the negative number to positive.

   As per the Appendix A.7.4.5, The result of the unary minus
   operator is the negative of the operand. The negative of the
   unsigned quantity is computed by subtracting the promoted value
   from the largest value of the promoted type and adding one.

   Lets test if n = -n, will produce a positive number if n = -8 or
   1000.

   			1111 	-> largest number of the promoted type.
		-	1000	-> our number
		-----------
			0111	
		+	   1
		------------
			1000 	-> result, which is the same as n. 

	this means that the expression n = -n, for n = -8, will not
	produce a positive number.

*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#define SIZE 64

void reverse(char s[]);
void itoa(int n, char s[]);

main()
{
	int n;
	char s[SIZE];

	n = INT_MIN;
	itoa(n, s);
	printf("%s\n", s);

	return 0;
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa (int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = (unsigned)n % 10 + '0';
	} while ((n = (unsigned)n / 10) > 0);
	if (sign  < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


