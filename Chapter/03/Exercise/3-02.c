/* Exercise 3-2. Write a function escape(s,t) that converts
 * characters like newline and tab into visible escape sequences like
 * \n and \t as it copies the string t to s. Use a switch. Write a
 * function for the other direction as well, converting escape
 * sequences into real characters. */

#include <stdio.h>
#define SIZE 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

main()
{
	char s[SIZE];
	char t[SIZE];
	int c, i;

	i = 0;
	while ((c = getchar()) != '\n') {
		t[i] = c;
		++i;
	}
	t[i++] = '\n';
	t[i] = '\0';

	escape(s, t);
	printf("%s", s);
	printf("\n");
	unescape(t, s);
	printf("%s", t);

	return 0;
}
/* escape: converts the characters like newline and tab into visible
 * escape sequences.
 */
void escape (char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; ++i)
	{
		switch(t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
		}
	}
	s[j] = '\0';
}

/* unescape: converts the escape sequences like \t into its
 * equivalent character
 */
void unescape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; ++i) {
		if (t[i] == '\\') {
			switch(t[++i]) {
				case 'n':
					s[j++] = '\n';
					break;
				case 't':
					s[j++] = '\t';
					break;
			}
		}
		else
			s[j++] = t[i];
	}
	s[j] = '\0';
}
