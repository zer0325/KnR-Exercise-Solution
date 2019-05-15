/* Exercise 1-22. Write a program to "fold" long input
 * into two or more shorter lines after the last non-blank
 * character that occurs before the n-th column of input.
 * Make sure the program does something intelligent with
 * very long lines, and if there are no blanks or tabs 
 * before the specified column */

#include <stdio.h>
#define N 	40			/* column width */
#define MAX	1000		/* size of array */
#define TAB 8			/* tabstop size */

main()
{
	int c, i, col, x;
	char s[MAX];

	i = 0;
	col = 1;
	while ((c = getchar()) != EOF) {
		s[i] = c;
		++i;
		/* Array overflow check */
		if (i == MAX - 1) {
			s[i] = '\0';
			printf("%s", s);
			i = 0;
		}

		if (c == '\n')
			col = 1;
		else if (c == '\t') {
			/* Set the value of col to the column 
			 * immediately after the nearest tab stop.
			 * Since every tabstop is a factor of TAB, Find
			 * the factor.
			 *
			 * Assume TAB = 10;
			 * if 1 < col <= 10; 	x = 1
			 * if 11 < col <= 21;	x = 2
			 * 
			 * In general:
			 *
			 * x = (col - 1) / TAB + 1;
			 */
			x = (col - 1) / TAB + 1;
			col = x * TAB + 1;
		} else 
			++col;

		if (col > N) {
			s[i] = '\n';
			++i;
			/* Array overflow check */
			if (i == MAX - 1) {
				s[i] = '\0';
				printf("%s", s);
				i = 0;
			}
			col = 1;
			/* Take care of the condition where the last 
			 * non-blank character in a line falls exactly
			 * at the N-th column */
			c = getchar();
			if (c == '\n')
				;
			else {
				s[i] = c;
				++i;
				++col;
			}
		}
		/* Process the modified input when the array is 
		 * full */
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
