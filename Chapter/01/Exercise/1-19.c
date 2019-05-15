/* Exercise 1-19. Write a function reverse(s) that reverses
 * the character string s. Use it to write a program that
 * reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
int getline(char s[], int lim);

main()
{
	int len;
	char line[MAXLINE];

	while (len = getline(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

/* getline: read the line into s, return length*/
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* reverse: reverses the character in s */
void reverse(char s[])
{
	int len, N, swap, i, tmp;

	/* Find the length of the string */
	for (len = 0; s[len] != '\0'; ++len)
		;

	/* ab 	-> swap a <-> b 
	   abc	-> swap a <-> c
	   abcd	-> swap a <-> d; b <-> c
	   
	   In general:

	   For an N-character string: swap N / 2 times.

	   In reference with the character positions:

	   ab	-> 0 <-> 1
	   abc	-> 0 <-> 2
	   abcd	-> 0 <-> 3; 1 <-> 2

	   In general:

	   For an N-character string: where string is n0, n1, n2,,..n(N-1)

	   n0 <-> n(N-1) OR  ni <-> n(N-1-i)
	*/

	N = len - 1;
	swap = 0;
	i = 0;
	while (swap != N / 2) {
		tmp = s[i];
		s[i] = s[N-1-i];
		s[N-1-i] = tmp;
		++swap;
		++i;
	}
}
