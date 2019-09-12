/* Exercise  4-8. Suppose that  there will never be more than one
 * character of pushback. Modify getch and ungetch accordingly */

/* General Idea:

   Since the exercise assumes that there  will never be more than one
   character of pushback, we will not use the variables buf and bufp.

   For the ungetch function, we are going to save the character to be
   pushed in pb_char and we will set the pb_flag.

   For the getch funtion, we will test if the pb_flag is set. If it
   is set, we we return the pb_char otherwise we call the getchar
   function.

   In this exercise, we are going to use the original rpn.c program
   from the book.

*/

#include <stdio.h>
#include <stdlib.h>		/* for atof() */

#define MAXOP	100		/* max size of operand or operator */
#define NUMBER	'0'		/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish Calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL	100		/* maximum depth of value stack */

int sp = 0;				/* next free stack position */
double val[MAXVAL];		/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, cant push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.') 
		return c;			/* not a number */
	i = 0;
	if (isdigit(c))			/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')			/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE	100

int pb_char = '\0';		/* pushed back character */
int pb_flag = 0;		/* push back flag */

int getch(void)			/* get a (possibly pushed back) character */
{
	return (pb_flag == 1) ? pb_flag = 0, pb_char : getchar();
}

void ungetch(int c)		/* push character back on input */
{
	
	pb_char = c;
	pb_flag = 1;
}
