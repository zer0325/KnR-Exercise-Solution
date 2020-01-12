/* Exercise 5-7. Rewrite readlines to store lines in an array
 * supplied by main, rather than calling alloc to maintain storage.
 * How much faster is the program? */

/* General idea:

   The readlines mentioned is a function in the sort program
   discussed in the book. The exercise requires us to use an array
   supplied by main rather than calling the alloc function. We are
   going to add another parameter in the readlines function. The
   parameter will be the array that will store the lines.

   In the readlines function, the expression:

   		(p = alloc(len)) == NULL)

	makes p to point to the first character of every line and at the
	same time allocates space to the line. Also, this expression also
	tests if there is enough space in the temporary storage.

	So our revised readlines function will make p point to the
	element in the array where the first character in every line is
	stored.
*/

#include <stdio.h>
#include <string.h>
#include "getline.c"

#define MAXLINES 5000		/* max #lines to be sorted */
#define ALLOCSIZE 10000		/* size of available space */

char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], char *buff, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
main()
{
	char buff[ALLOCSIZE];
	int nlines; 	/* number of input lines read */

	if((nlines = readlines(lineptr, buff, MAXLINES)) >= 0) {
		printf("\nUnsorted:\n\n");
		writelines(lineptr, nlines);
		qsort(lineptr, 0, nlines-1);
		printf("\nSorted:\n\n");
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000		/* max length of any input line */
int getline(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *buff, int maxlines)
{
	int len, nlines;
	char *p = buff, line[MAXLEN];

	nlines = 0;
	while((len = getline(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (ALLOCSIZE - (p - buff)) < len) 
			return -1;
		else{
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;			/* adjust the pointer to point to the
								   element where the first character
								   of a line will be saved */
			*(p - 1) = '\0';	/* delete newline */
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for(i = 0; i < nlines; i++)
		printf("lineptr[%d] %p %s\n", i, lineptr[i], lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if(left >= right)	/* do nothing if array contains */
		return;			/* fewer than two elements */
	swap(v, left, (left+right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
