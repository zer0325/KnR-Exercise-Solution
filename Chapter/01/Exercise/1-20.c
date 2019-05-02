/* Exercise 1-20. Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter? */

#include <stdio.h>
#define MAX 1000
#define N 8

/* 
	If the character is a tab character, the number of blanks will depend on the
	value of the current col. Placement of blank will start at col up to the
	tab stop. 

	lower_limit = col; 	upper_limit = x * N;	where x is the factor.

	Assume that N = 10;

	if 1 < col <= 10		x = 1
	if 11 < col <= 20		x = 2
	if 21 < col <= 30		x = 3

	From this:

	x = ((col - 1) / N) + 1 
*/

main()
{
	int c, col, i, x;
	char s[MAX];

	i = 0;
	col = 1;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			x = ((col - 1) / N) + 1;
			while (col <= x * N) {
				s[i] = '*';			/* The character * is used to see the effect
									   since a blank line will not be seen on
									   the display */
				++i;
				/* Overflow  check */
				if (i == MAX - 1) {
					s[i] = '\0';
					printf("%s", s);
					i = 0;
				}
				++col;
			}
		} else {
			s[i] = c;
			++i;
			++col;
		}

		if (c == '\n') 
			col = 1;

		/* Process the input when the array is full */
		if (i == MAX - 1) {
			s[i] = '\0';
			printf("%s", s);
			i = 0;
		}
	}
	/* Process the remaining input */
	s[i] = '\0';
	printf("%s", s);

	return 0;
}
