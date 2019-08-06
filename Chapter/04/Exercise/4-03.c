/* Exercise 4-3. Given the basic framework, it's straightforward to
 * extend the calculator. Add the modulos (%) operator and provisions
 * for negative numbers. */

/* General idea:

   Adding the modulos operator:

   The modulo operator will be added as a case label in the switch
   statement of the main function. Based on the previous chapter of
   the book, the modulo operator cannot be applied to a float or a
   double type. To satisfy the requirement of the modulos operator,
   we will cast the operands to int before applying the modulos
   operation.

   Adding provision for negative numbers:

   The additional statement that will handle the provision for
   negative numbers, will be added in the getop function. Since the
   "-" character, is both used as an operator or as a negative sign,
   we will check the next character if it is a digit or not. If it is
   a digit, we have a negative number, otherwise we have a minus
   operator.

   		If the character is a "-", check if the next character is a
		digit. If it is, set the sign_flag as 1 and return the
		recently read character to the input, otherwise we return the
		"-" character as an operator.

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
			case '%':
				op2 = pop();
				if(op2 != 0.0)
					push((int)pop() % (int)op2);
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

