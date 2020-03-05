/* Exercise 5-12. Extend entab and detab to accept the shorthand 

   		entab -m +n

   to mean tab stops every n columns, starting at column n. Choose convenient
   (for the user) default behavior. 
*/

/* 	
	Similar to the exercise 5-11, we are going to use as our basis the detab
	program since the logic will be the same for the entab program.

	tabstops will be: m+n, m+n+n, m+n+2n,..., m+n+kn;

	k = 1 if	m+n < col <= m+n+n
	k = 2 if	m+n+n < col <= m+n+2n

	k increments by 1 if col > m+n+2n

	The value of the tabstop will depend on the value of col.

	if(col <= m+n)
		N = m + n;
	else
	    N = m + n + kn;

	Now that the value of tabstops is taken care of, let us find the value of m
	and n.

	The value of m or n depends on the first character of the arguments. If the
	first character is a '-', the integer after the '-' is saved as m. If the
	first character is a '+', the integer is saved as n.

	Code Structure:

		while there is argument
			if the first character is '-'
				save the integer as m
			if the first character is '+'
				save the integer as n

		while the next character is not eof
			if it is a tab
				if col <= m+n
					N = m+n
				else
					N = m+n+kn

			---use the original code starting from here ----

*/

#include <stdio.h>
#define MAX 1000
#define DEFAULT 8		/* Default tabstop */

main(int argc, char *argv[])
{
	int c, col, i, x;
	char s[MAX];
	int N;
	int m = 0, n = DEFAULT;
	int k;

	while(--argc > 0){
		c = (*++argv)[0];
		switch(c){
			case '-':
				m = atoi(++argv[0]);
				break;
			case '+':
				n = atoi(++argv[0]);
				break;
		}
	}

	i = 0;
	col = 1;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			if(col <= m + n)
				N = m + n;
			else{
				for(k = 1; col > m + n + (k * n); ++k)
					;
				N = m + n + (k * n);
			}
			x = ((col - 1) / N) + 1;
			while (col <= x * N) {
				s[i] = ' ';		/* The character "*" is 
								 * used to see the effect
								 * since a blank line will
								 * not be seen on the
								 * display */
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
