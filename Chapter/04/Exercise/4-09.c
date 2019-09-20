/* Exercise 4-9. Our getch and ungetch do not handle a pushed-back
 * EOF correctly. Decide what their properties ought to be if an EOF
 * is pushed back, then implement your design. */

/* General idea:

	Out original getch and ungeth functions uses a buffer, buf, of
	type char. Since EOF has an integer of -1, the buffer will not be
	able to handle the EOF correctly. So to handle the EOF correctly,
	we will change the type of buf to int. 

*/

#define BUFSIZE 100

int buf[BUFSIZE]; 	/* buffer for ungetch */
int bufp = 0;

int getch(void)	/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
