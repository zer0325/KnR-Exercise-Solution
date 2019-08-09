/* Exercise 4-4. Add commands to print the top element of the stack
 * without popping, to duplicate it, and to swap the top two
 * elements. Add a command to clear the stack. */

/* General idea:

   The commands for printing, duplicating, swapping and clearing are
   best implemented by using separate functions for each. For
   printing, we will call it as the function print(), for
   duplicating as dup(), for swapping as swap(), and for clearing as
   clear().

   When the print function is called, it will just access the value
   at the sp - 1 position, for sp > 0. When the dup function is
   called, it will duplicate the value at the sp - 1 position, and
   then push it at the top of the stack, for sp > 0 and sp < MAXVAL.
   When the  swap function is called, it will swap the two values at
   the sp - 1 and sp - 2 positions, for sp > 1 and sp <= MAXVAL. When
   the clear function is called, it will set the sp = 0.

   The equivalent commands for each function will be added as a case
   label in the switch statement of the main function. The case
   labels are 'p' for print(), 'd' for dup(), 's' for swap(), and 'c'
   for clear().

   We will also use the program that we have created for exercise
   4-3.

*/

#include <stdio.h>
#include <stdlib.h>		/* for atof() */

#define MAXOP	100		/* max size of operand or operator */
#define NUMBER	'0'		/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void print(void);
void dup(void);
void swap(void);
void clear(void);
void summary(void); 	/* for testing purposes only */

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
			case '%':
				op2 = pop();
				if(op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					printf("error: zero divisor\n");
				break;
			case 'p':
				print();
				break;
			case 'd':
				dup();
				break;
			case 's':
				swap();
				break;
			case 'c':
				clear();
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				summary();
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
/* print: prints the top of the stack without popping */
void print(void)
{
	if(sp > 0)
		printf("\t%.8g\n", val[sp - 1]);
}
/* dup: duplicates the top of the stack */
void dup(void)
{
	if(sp > 0 && sp < MAXVAL) 
		push(val[sp - 1]);
}
/* swap: swaps the top two elements of the stack */
void swap(void)
{
	double first, second;
	if(sp > 1 && sp <= MAXVAL) {
		first = pop(), second = pop();
		push(first), push(second);
	}
}
/* clear: clears the stack */
void clear(void)
{
	sp = 0;
}
/* summary: prints the size of the stack and the top two elements */
void summary(void)
{
	printf("stack size = %d\n", sp);
	printf("top two elements:\n");
	printf("%.8g\n%.8g\n", val[sp - 1], val[sp - 2]);
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, op, sign = 0;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.') {
		if (c != '-')
			return c;
		else
			op = c;
	}

	if (c == '-' && isdigit(c = getch())) { 
		sign = 1;		/* indicates a negative number */
		ungetch(c);
	}
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
	
	if (!sign && i == 0)
		return op;
	else
		return NUMBER;
}

#define BUFSIZE	100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

int getch(void)			/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

