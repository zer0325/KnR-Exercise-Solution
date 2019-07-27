/* Exercise 4-2. Extend atof to handle scientific notation of the
 * form 
 *		123.45e-6
 *
 * where a floating-point number may be followed by e or E and an
 * optionally signed exponent.
 */

/* General idea:

   We will retain the code for the atof function. We add expression
   that check for the presence of the 'e' or 'E'. We will add
   expression that check for the sign of the exponent. And we will
   check for the presence of the value of the exponent. The value of
   the exponent is just a multiplier. E.g.

   		123.45e-6 is the same as 123.45x10^-6

	We will just multiply or divide the value before 'e' by 10, 6
	times, depending on the value of the sign of the exponent.

*/
#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

main()
{
	char s[] = "123.45e-6";

	printf("%g\n", atof(s));
	return 0;
}

double atof(char s[])
{
	double val, power;
	int i, sign;
	int exp_sign = 1;
	int exp;
	
	for (i = 0; isspace(s[i]); ++i)		/* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E')
		++i;
	if (s[i] == '-')
		exp_sign = -1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	for (exp = 0; isdigit(s[i]); i++)
		exp = exp * 10 + (s[i] - '0');

	if (exp_sign == -1) {
		for(i = 0; i < exp;  i++)
			power *= 10;
	} else {
		for (i = 0; i < exp; i++)
			val *= 10;
	}


	return sign * val / power;
}

