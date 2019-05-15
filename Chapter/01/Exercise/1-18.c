/* Exercise 1-18. Write a program to remove trailing blanks
 * and tabs from each line of input, and to delete entirely
 * blank lines. */

#include <stdio.h>
#define MAXLINE	1000	/* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */
	char orig[MAXLINE];		/* copy of the original line */

	while ((len = getline(line, MAXLINE)) > 0) {
		/* Create a copy of the original line */
		copy(orig, line);

		for (len = len - 2; len >= 0 && line[len] == ' ' || line[len] == '\t';
				--len)
			;

		++len;
		line[len] = '\n';
		++len;
		line[len] = '\0';
		if (len > 1)
			printf("%s", line);
	}
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

