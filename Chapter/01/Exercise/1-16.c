/* Exercise 1-16. Revise the main routine of the
 * longest-line program so it will correctly print the
 * length of arbitrarily long input lines, and as much as
 * possbile of the text */

#include <stdio.h>
#define MAXLINE 50		
/* Size of the array. This is not an imposed limit 
 * on what size the program only accepts. I initially
 * use 1000, but since I didn't see the effect when I
 * use this file as input, I use 50 to simulate the
 * effect of a line longer than 50. If changed to 1000,
 * the length of the longest-line will be the same */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;			/* current line length */
	int max;			/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		/* Test for long input line */
		if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') {
			while (getchar() != '\n')
				++len;
			++len;		/* include the newline character */
		}
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)	/* there was a line */
		printf("%d: %s\n", max, longest);
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}


