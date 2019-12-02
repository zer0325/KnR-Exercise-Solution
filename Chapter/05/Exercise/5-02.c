/* Exercise 5-2. Write getfloat, the floating-point analog of getint.
 * What type does getfloat return as its function value? */

/* General Idea:

   The return value of getfloat will be similar to the return value
   of getint. The function getfloat returns 0, if the input is a
   non-number, a positive value if the input is a valid number, and
   an EOF indicator to indicate end-of-file.
*/

/* getfloat: get next floating-point from input into *pf */

int getfloat(double *pf)
{
	int c, sign;
	double power;

	while(isspace(c = getch()))		/* skip white space */
		;
	if(!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') {
		ungetch(c);		/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '-' || c == '+')
		c = getch();
	
	/* Get the decimal part */
	for(*pf = 0.0; isdigit(c); c = getch())
		*pf = 10.0 * *pf + (c - '0');

	/* Get the fractional part */
	if(c == '.')
		c = getch();
	for(power = 1.0; isdigit(c); c = getch()) {
		*pf = 10.0 * *pf + (c -'0');
		power *= 10.0;
	}
	
	*pf = sign * *pf / power;
	if(c != EOF)
		ungetch(c);
	return c;
}
