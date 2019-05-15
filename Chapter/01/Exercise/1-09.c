/* Exercise 1-9. Write a program to copy its input to its
 * output, replacing each string of one or more blanks by a
 * single blank. */

#include <stdio.h>

main()
{
	int c, nb;

	nb = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		if (c != ' ') {
			if (nb >= 1) {
				putchar(' ');
				nb = 0;
			}
			putchar(c);
		}
	}
}
