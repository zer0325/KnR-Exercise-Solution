/* Exercise 5-1. As written, getint treats a + or - not followed by a
 * digit as a valid representation of zero. Fix it to push such a
 * character back on the input. */

/*
	The version of getint provided by the book determines whether the
	input is a valid number, a non-number, or an End-Of-File based on
	the return value of the getint function. 

	If the return value is a zero, the input is not a number. If it
	is a positive value, the input is a number. And if the return
	value is the integer equivalent of EOF, we are at the end of the
	input.

	The exercise mentions that getint treats a + or a - followed by a
	non-digit as a valid representation of zero. It means that if the
	input is a - or + followed by a non-digit, the return value is a
	positive number.

	The exercise requires us to fix the getint function so that the
	above-mentioned sequence of input will return a zero, indicating
	that the input is not a number.

*/
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while(isspace(c = getch()))	
		;
	if(!isdigit(c) && c!= EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1: 1;
	if(c == '+' || c == '-')
		c = getch();

	/* The following if statement satisfies the requirement of the
	 * exercise */
	if(!isdigit(c) && c != EOF) {
		ungetch(c);
		return 0;
	}

	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

