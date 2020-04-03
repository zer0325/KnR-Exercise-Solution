/* Exercise 5-13. Write the program tail, which prints the last n lines of its
 * input. By default,  n is 10, let us say, but it can be changed by an optional
 * argument, so that
 *
 *		tail -n
 *
 * prints the last n lines. The program should behave rationally no matter how
 * unreasonable the input or the value of n. Write the program so it makes the
 * best use of available storage; lines should be stored as in the sorting
 * program of Section 5.6, not in a two-dimensional array of fixed size. 
 */

/* General idea:

   The exercise requires us to use the storing mechanism of the sorting program
   of section 5.6.

   Lets use as a template the sorting process of the sorting program. But this
   time we are going to use only two steps in our tail program.

   The two steps are:

   		read all the lines of input
		print the last n lines

   From this we can use both the readlines and writelines function of the
   sorting program. The writelines function will have an additional argument, n,
   which is the number of lines to be printed.
*/

#include <stdio.h>
#include <string.h>
#define DEFAULT 10			/* default number of lines to be printed */

#define MAXLINES 5000		/* max #lines */

char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int n);

main(int argc, char *argv[])
{
	int n = DEFAULT;
	int nlines;

	if(argc == 2){
		++argv;
		n = atoi(++argv[0]);
	}
	
	if((nlines = readlines(lineptr, MAXLINES)) >= 0){
		writelines(lineptr, nlines, n);
		return 0;
	}else{
		printf("error: input too big.\n");
		return 1;
	}

}

#define MAXLEN	1000		/* max length of any input line */
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len,  nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while((len = getline(line, MAXLEN)) > 0){
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else{
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n';i++)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


/* alloc: return pointer to n characters */

#define  ALLOCSIZE 10000	/* size of available space */

static char allocbuf[ALLOCSIZE];		/* storage for alloc */
static char *allocp = allocbuf;			/* next free position */

char *alloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp >= n){ /* it fits */
		allocp += n;
		return allocp - n;		/* old p */
	} else						/* not enough room */
		return 0;
}

/* writelines: print the last n lines */
void writelines(char *lineptr[], int nlines, int n)
{
	int start_line = 0;
	int i;

	start_line = nlines - n;

	for(i = start_line; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
