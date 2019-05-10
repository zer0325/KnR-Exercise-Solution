/* Exercise 2-3. Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

main()
{
	printf("%d\n", htoi("abc123"));
	printf("%d\n", htoi("0Xabc123"));
	printf("%d\n", htoi("0xabc123"));

	return 0;
}
/* The actual function as required by the exercise, the caller is for testing if
 * the  function is correct */

/* htoi: convert the hexadecimal string s to integer */
int htoi(char s[])
{
	int i, n, c, index = 0;

	/* check if the first two characters are 0x or 0X.
	   If they are, start evaluation at the 2nd index,
	   otherwise start at 0th index */
	if (s[0] == '0' && tolower(s[1]) == 'x')
		index = 2;

	n = 0;
	for (i = index; isdigit(c = tolower(s[i])) || isxdigit(c); ++i) {
		if (isdigit(c))
			n = 16 * n + (c - '0');
		else
			n = 16 * n + (c - 'a' + 10);
	}

	return n;
}
