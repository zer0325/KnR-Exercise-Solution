/* Exercise 4-12. Adapt the ideas of printd to write a recursive
 * version of itoa; that is, convert an integer into a string by
 * calling a recursive routine. */


int i = 0;

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{

	if(n < 0) {
		s[i++] = '-';
		n = -n;				/* make n positive */
	}

	if(n / 10)
		itoa(n / 10, s);

	s[i++] = n % 10 + '0';
	s[i] = '\0';

}
