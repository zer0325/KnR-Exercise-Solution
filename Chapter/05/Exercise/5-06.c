/* Exercise 5-6. Rewrite appropriate programs from earlier chapters
 * and exercises with pointers instead of array indexing. Good
 * possibilities include getline (Chapters 1 and 4), atoi, itoa, and
 * their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and
 * strindex and getop (Chapter 4).
 */

#include <stdio.h>
#include <string.h>
#include "getch.c"

#define NUMBER '0'	/* signal that a number was found */

int getline(char *s, int lim);
int atoi(char *s);
void itoa(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);
int getop(char *s);

main()
{
	char buff[1000];

	printf("getop returns: %d\n", getop(buff));
	printf("buff contains: %s\n", buff);	
	return 0;
}

/* getline: get line into s, return length; pointer version */
int getline(char *s, int lim)
{
	int c;
	char *p = s;

	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if(c == '\n')
		*s++ = c;
	*s = '\0';
	return s - p;
}

/* atoi: convert s to integer; version 2; pointer version */
int atoi(char *s)
{
	int n, sign;

	for(; isspace(*s); s++)		/* skip white space */
		;
	sign = (*s == '-') ? -1 : 1;
	if(*s == '+' || *s == '-')	/* skip sign */
		s++;
	for(n = 0; isdigit(*s); ++s)
		n = 10 * n + (*s -  '0');
	return sign * n;
}

/* itoa: convert n to characters in s*/
void itoa(int n, char *s)
{
	int sign;
	char *p = s;

	if((sign = n) < 0)	/* record sign */
		n = -n;			/* make n positive */
	do{			/* generate digist in reverse order */
		*s++ = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	if(sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(p);
}

/* reverse: reverse string s in place; pointer version */
void reverse(char *s)
{
	int c;
	char *p = s + strlen(s) - 1;

	for(; s < p; ++s, --p) {
		c = *s;
		*s = *p;
		*p = c;
	}
}

/* strindex: return index of t in s, -1 if none; pointer version */
int strindex(char *s, char *t)
{
	char *p = s;
	int i;
	for(; *s != '\0'; s++){
		for(i = 0; *(t+i) != '\0' && *(s+i) == *(t+i); ++i)
			;
		if(*(t+i) == '\0')
			return s - p;
	}
	return -1;
}

/* getop: get next operator or numeric operand; pointer version */
int getop(char *s)
{
	int c;
	while((*s = c = getch()) == ' ' || c == '\t')
		;
	*++s = '\0';
	if(!isdigit(c) && c != '.')
		return c;		/* not a number */
	if(isdigit(c))		/* collct integer part */
		while(isdigit(*s++ = c = getch()))
			;
	if(c == '.')		/* collect fraction part */
		while(isdigit(*s++ = c = getch()))
			;
	*s = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}
