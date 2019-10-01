/* Exercise 4-10. An alternate organization uses getline to read an
 * entire input line; this makes getch and ungetch unnecessary.
 * Revise the calculator to use this approach. 
*/

/* General idea:

   Based on the exercise, the getline function will read an entire
   input line. From this line, we will get the next operator or
   operand until we reach the end of the line. 

   To get the next operator or operand we will go through the line
   starting from the beginning of the line up to the end of the line.
   Assigning index as the point in the line, we will know that we are
   at the end of the line if index is equal to lenght of the line
   minus one.

   Program structure:
   
   		while there is a line
   			while not at the end of the line
				get the next operator or operand
				if(number)
					push operand
				else if(operator)
					pop operands
					do operation
					push result
				else if(newline)
					pop and print the top of the stack
				else
					error

*/

#include <stdio.h>
#include <stdlib.h>		/* for atof() */

#define MAXOP	100		/* max size of operand or operator */
#define NUMBER	'0'		/* signal that a number was found */
#define MAXLINE 1000	/* maximum input line */

char line[MAXLINE];
int index;

int getop(char []);
void push(double);
double pop(void);
int getline(char line[], int max);

/* reverse Polish Calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];
	int len;

	while((len = getline(line, MAXLINE)) > 0) {
		index = 0;				/* always start at the beginning of
								   the line */
		while(index < len) {
			type = getop(s);
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
	}
	return 0;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
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

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while((s[0] = c = line[index++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.') 
		return c;			/* not a number */
	i = 0;
	if (isdigit(c))			/* collect integer part */
		while (isdigit(s[++i] = c = line[index++]))
			;
	if (c == '.')			/* collect fraction part */
		while (isdigit(s[++i] = c = line[index++]))
			;
	s[i] = '\0';
	return NUMBER;
}
