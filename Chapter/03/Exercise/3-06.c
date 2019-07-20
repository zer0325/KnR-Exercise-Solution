/* Exercise 3-6. Write a version of ito that accepts three arguments
 * instead of two. The third argument is a minimum field width; the
 * converted number must be padded with blanks on the left if
 * necessary to make it wide enough.
 */

/* General idea;

   This will be an extension of the itoa function. All we need to do
   is add the procedure for the padding. The procedure will be added
   right before we add a null character at the end of the string s.
   We are going to use the version of itoa where the largest negative
   number is handled.
   
Algorithm:

	1. Preserve the code prior to the adding of the null character.
	2. starting at i, add a blank character until i = w - 1.
	3. add the null character.

*/
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define BITS 64

void reverse(char s[]);
void itoa(int n, char s[], int w);

main()
{
	int n, w;
	char s[BITS];

	n = INT_MIN;
	w = 5;
	for (w = 5; w <= 20; w += 5) {
		itoa(n, s, w);
		printf("at w = %2d, %s\n", w, s);
	}
	return 0;
}

void reverse(char s[])
{
	int i, j, c;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[], int w)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = (unsigned) n % 10 + '0';
	} while ((n = (unsigned) n / 10) > 0);

	if (sign < 0)
		s[i++] = '-';

	/* Procedure for padding */
	while (i < w) {
		s[i++] = 0x20;
	}
	s[i] = '\0';
	reverse(s);
}

