/* Exercise 1-21. Write a program entab that replaces
 * strings of blanks by the minimum number of tabs and
 * blanks to achieve the same spacing. Use the same tab
 * stops as for detab. When either a tab or a single blank
 * would suffice to reach a tab stop, which should be given
 * preference? 
 *
 * Answer to second question:
 * 
 * Based on our code, the tab character is given preference
 */

#include <stdio.h>
#define N 8			/* number of columns per tab stop */
#define MAX 1000

/* Step by step procedure:
	
   1. Process the input per character.
   	  a. Whenever a character is read, increment the col 
	  variable. 
   2. If the character is a blank, temporarily suspend the 
      saving  of the character to the array until the next
	  non-blank character. Instead increment the number of
	  blanks.
   3. If the character is a non-blank character, replace 
      the strings of blanks with the minimum number of 
	  tabs and blanks.
   	  a. Find the col where the first blank appears.

	 	 pos = col - nb;

	  b. Within the range of numbers between pos and col, 
	  count the numbers that are a factor of N. The total
	  number is the numer of tabs.

	  	 for (j = pos; j < col; ++j)
		 	if (j % N == 0)
				++tab;

	  c. Count the remaining blanks.
		
	     nb = 0;
	  	 for (j = col - 1; j >= pos && j % N != 0; --j)
			++nb;

   4. Read the tabs and blanks  to the array.
   5. Read the character to the array.
*/

main()
{
	int c, nb, col, pos, tab, j, i, x;
	char s[MAX];

	nb = tab = 0;
	col = 1;
	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		else {
			/* Replace the strings of blanks with the 
			 * minimum number of tabs and blanks to achieve
			 * the same spacing. */

			/* Find the column where the first blank 
			 * appears */
			pos = col - nb;
			
			/* Within the range of numbers between pos 
			 * and col, count the numbers that are a factor
			 * of N. */
			for (j = pos; j < col; ++j)
				if (j % N == 0)
					++tab;

			/* Count the remaining blanks */
			nb = 0;
			for (j = col - 1; j >= pos && j % N != 0; --j)
				++nb;

			/* Save the tabs to the array */
			for (j = 0; j < tab; ++j) {
				s[i] = '\t';
				++i;
				if (i == MAX - 1) {
					s[i] = '\0';
					printf("%s", s);
					i = 0;
				}
			}
			
			/* Save the blanks to the array */
			for (j = 0; j < nb; ++j) {
				s[i] = ' ';
				++i;
				if (i == MAX - 1) {
					s[i] = '\0';
					printf("%s", s);
					i = 0;
				}
			}

			/* Read the returned character to the array */
			s[i] = c;
			++i;

			/* Reinitialize nb and tab to zero */
			nb = 0;
			tab = 0;
		}
		if (c == '\n')
			col = 1;
		else if (c == '\t') {
			/* Set col to the column immediately after the 
			 * nearest tab stop.

			   To find the nearest tab stop, E.g. Set N = 10.

			   if 1 < col <= 10,  x = 1 where x is a factor
			    						of N.
			   if 11 < col <= 20, x = 2

			   In general:
			   x = (col - 1) / N + 1
			*/
			x = (col - 1) / N + 1;
			col = x * N + 1;
		} else 
			++col;

		/* Print the input when the array is full */
		if (i == MAX - 1) {
			s[i] = '\0';
			printf("%s", s);
			i = 0;
		}
	}
	/* For the remaining input */
	s[i] = '\0';
	printf("%s", s);

	return 0;
}
